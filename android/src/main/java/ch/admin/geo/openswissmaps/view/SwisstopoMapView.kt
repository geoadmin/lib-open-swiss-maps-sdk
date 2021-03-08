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
import ch.admin.geo.openswissmaps.networking.RequestUtils
import ch.admin.geo.openswissmaps.shared.layers.SwisstopoLayerFactory
import ch.admin.geo.openswissmaps.shared.layers.config.SwisstopoLayerType
import io.openmobilemaps.mapscore.map.loader.TextureLoader
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

	var textureLoader = TextureLoader(context, context.cacheDir, 50L * 1024L * 1024L, RequestUtils.getDefaultReferer(context))
		private set

	init {
		System.loadLibrary("openswissmaps")

		setupMap(swisstopoMapConfig)
		createBaseLayer(BASE_LAYER_TYPE_DEFAULT)
		mapInterface.getCamera().setMinZoom(ZOOM_MIN_DEFAULT)
		mapInterface.getCamera().setMaxZoom(ZOOM_MAX_DEFAULT)
		mapInterface.getCamera().setZoom(ZOOM_MIN_DEFAULT, false);
	}

	private fun createBaseLayer(layerType: SwisstopoLayerType) {
		val newBaseLayer =
			SwisstopoLayerFactory.createSwisstopoTiledRasterLayer(layerType, textureLoader)
		mapInterface.addLayer(newBaseLayer.asLayerInterface())
		baseLayer = newBaseLayer
	}

	fun setBaseLayerType(layerType: SwisstopoLayerType?) {
		baseLayer?.let { mapInterface.removeLayer(it.asLayerInterface()) }
		baseLayer = if (layerType != null) {
			val newLayer = SwisstopoLayerFactory.createSwisstopoTiledRasterLayer(layerType, textureLoader)
			mapInterface.insertLayerAt(newLayer.asLayerInterface(), 0)
			baseLayer?.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
			newLayer
		} else null
	}

	fun setBaseLayerType(identifier: String) {
		baseLayer?.let { mapInterface.removeLayer(it.asLayerInterface()) }
		baseLayer = if (layerType != null) {
			val newLayer = swisstopoWmtsResource.createLayer(identifier, textureLoader)
			mapInterface.insertLayerAt(newLayer.asLayerInterface(), 0)
			baseLayer?.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
			newLayer
		} else null
	}

	override fun removeLayer(layer: LayerInterface) {
		super.removeLayer(layer)
		if (layer == baseLayer?.asLayerInterface()) baseLayer = null
	}

	fun addSwisstopoLayer(layerType: SwisstopoLayerType) : Tiled2dMapRasterLayerInterface {
		val layer = SwisstopoLayerFactory.createSwisstopoTiledRasterLayer(layerType, textureLoader)
		addLayer(layer.asLayerInterface())
		return layer
	}

	fun addSwisstopoLayer(identifier: String) : Tiled2dMapRasterLayerInterface {
		val layer = swisstopoWmtsResource.createLayer(identifier, textureLoader)
		addLayer(layer.asLayerInterface())
		return layer
	}
}