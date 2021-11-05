/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

package ch.admin.geo.openswissmaps.view

import android.content.Context
import android.util.AttributeSet
import androidx.lifecycle.Lifecycle
import ch.admin.geo.openswissmaps.R
import ch.admin.geo.openswissmaps.networking.RequestUtils
import ch.admin.geo.openswissmaps.shared.layers.config.SwisstopoLayerType
import ch.admin.geo.openswissmaps.shared.layers.config.SwisstopoTiledLayerConfigFactory
import io.openmobilemaps.gps.GpsLayer
import io.openmobilemaps.gps.GpsProviderType
import io.openmobilemaps.gps.providers.LocationProviderInterface
import io.openmobilemaps.gps.shared.gps.GpsMode
import io.openmobilemaps.gps.shared.gps.GpsStyleInfo
import io.openmobilemaps.gps.style.GpsStyleInfoFactory
import io.openmobilemaps.mapscore.map.loader.DataLoader
import io.openmobilemaps.mapscore.map.view.MapView
import io.openmobilemaps.mapscore.shared.map.LayerInterface
import io.openmobilemaps.mapscore.shared.map.MapConfig
import io.openmobilemaps.mapscore.shared.map.coordinates.CoordinateSystemFactory
import io.openmobilemaps.mapscore.shared.map.layers.tiled.raster.Tiled2dMapRasterLayerInterface
import io.openmobilemaps.mapscore.shared.map.layers.tiled.raster.wmts.WmtsCapabilitiesResource

class SwisstopoMapView @JvmOverloads constructor(context: Context, attrs: AttributeSet? = null, defStyleAttr: Int = 0) :
    MapView(context, attrs, defStyleAttr) {

    companion object {
        private val BASE_LAYER_TYPE_DEFAULT = SwisstopoLayerType.PIXELKARTE_FARBE
        private const val ZOOM_MIN_DEFAULT = 5000000.0
        private const val ZOOM_MAX_DEFAULT = 250.0
    }

    private val swisstopoMapConfig: MapConfig = MapConfig(CoordinateSystemFactory.getEpsg2056System())

    val swisstopoWmtsResource: WmtsCapabilitiesResource by lazy {
        val str = context.assets.open("wmts/WMTSCapabilities_2056.xml").bufferedReader().use { it.readText() }
        WmtsCapabilitiesResource.create(str)
    }

    var baseLayer: Tiled2dMapRasterLayerInterface? = null
        private set

    var gpsLayer: GpsLayer? = null
        private set

    var loader = DataLoader(context, context.cacheDir, 50L * 1024L * 1024L, RequestUtils.getDefaultReferer(context))
        private set

    init {
        var useMSAA = false
        context.theme.obtainStyledAttributes(attrs, R.styleable.SwisstopoMapView, 0, 0).apply {
            try {
                useMSAA = getBoolean(R.styleable.SwisstopoMapView_useMSAA, false)
            } finally {
                recycle()
            }
        }
        setupMap(swisstopoMapConfig, useMSAA)
        createBaseLayer(BASE_LAYER_TYPE_DEFAULT)
        requireMapInterface().getCamera().setMinZoom(ZOOM_MIN_DEFAULT)
        requireMapInterface().getCamera().setMaxZoom(ZOOM_MAX_DEFAULT)
        requireMapInterface().getCamera().setZoom(ZOOM_MIN_DEFAULT, false)
    }

    override fun onDestroy() {
        super.onDestroy()
        baseLayer = null
        gpsLayer = null
    }

    private fun createBaseLayer(layerType: SwisstopoLayerType) {
        val newBaseLayer = Tiled2dMapRasterLayerInterface.create(
            SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfig(layerType),
            loader
        )
        requireMapInterface().addLayer(newBaseLayer.asLayerInterface())
        baseLayer = newBaseLayer
    }

    fun setBaseLayerType(layerType: SwisstopoLayerType?) {
        baseLayer?.let { requireMapInterface().removeLayer(it.asLayerInterface()) }
        baseLayer = if (layerType != null) {
            val newLayer = Tiled2dMapRasterLayerInterface.create(SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfig(layerType), loader)
            requireMapInterface().insertLayerAt(newLayer.asLayerInterface(), 0)
            baseLayer?.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
            newLayer
        } else null
    }

    fun setBaseLayerType(identifier: String) {
        baseLayer?.let { requireMapInterface().removeLayer(it.asLayerInterface()) }
        baseLayer = if (layerType != null) {
            val newLayer = swisstopoWmtsResource.createLayer(identifier, loader)
            requireMapInterface().insertLayerAt(newLayer.asLayerInterface(), 0)
            baseLayer?.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
            newLayer
        } else null
    }

    override fun removeLayer(layer: LayerInterface) {
        super.removeLayer(layer)
        if (layer == baseLayer?.asLayerInterface()) baseLayer = null
    }

    fun addSwisstopoLayer(layerType: SwisstopoLayerType): Tiled2dMapRasterLayerInterface {
        val layer = Tiled2dMapRasterLayerInterface.create(SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfig(layerType), loader)
        val gpsLayerInterface = gpsLayer?.asLayerInterface()
        if (gpsLayerInterface != null) {
            insertLayerBelow(layer.asLayerInterface(), gpsLayerInterface)
        } else {
            addLayer(layer.asLayerInterface())
        }
        return layer
    }

    fun addSwisstopoLayer(identifier: String): Tiled2dMapRasterLayerInterface {
        val layer = swisstopoWmtsResource.createLayer(identifier, loader)
        val gpsLayerInterface = gpsLayer?.asLayerInterface()
        if (gpsLayerInterface != null) {
            insertLayerBelow(layer.asLayerInterface(), gpsLayerInterface)
        } else {
            addLayer(layer.asLayerInterface())
        }
        return layer
    }

    fun addGpsLayer(lifecycle: Lifecycle,
                    style: GpsStyleInfo = GpsStyleInfoFactory.createDefaultStyle(context),
                    providerType: GpsProviderType = GpsProviderType.GPS_ONLY
    ): GpsLayer = addGpsLayer(lifecycle, style, providerType.getProvider(context))

    fun addGpsLayer(lifecycle: Lifecycle, style: GpsStyleInfo = GpsStyleInfoFactory.createDefaultStyle(context),
                    locationProvider: LocationProviderInterface): GpsLayer {
        gpsLayer?.let { return it }
        val newGpsLayer = GpsLayer(context, style, locationProvider)
        addLayer(newGpsLayer.asLayerInterface())
        newGpsLayer.registerLifecycle(lifecycle)
        newGpsLayer.setMode(GpsMode.STANDARD)
        newGpsLayer.setHeadingEnabled(style.headingTexture != null)
        gpsLayer = newGpsLayer
        return newGpsLayer
    }
}