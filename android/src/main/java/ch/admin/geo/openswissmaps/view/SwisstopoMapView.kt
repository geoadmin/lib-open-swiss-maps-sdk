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
import io.openmobilemaps.mapscore.shared.map.MapConfig
import io.openmobilemaps.mapscore.shared.map.coordinates.CoordinateSystemFactory
import io.openmobilemaps.mapscore.shared.map.layers.tiled.raster.Tiled2dMapRasterLayerInterface

class SwisstopoMapView @JvmOverloads constructor(context: Context, attrs: AttributeSet? = null, defStyleAttr: Int = 0) :
	MapView(context, attrs, defStyleAttr) {

	private val swisstopoMapConfig: MapConfig = MapConfig(CoordinateSystemFactory.getEpsg2056System(), 4000000.0, 500.0)

	lateinit var baseLayer: Tiled2dMapRasterLayerInterface
		private set

	var textureLoader = TextureLoader(context, context.cacheDir, 50L * 1024L * 1024L, RequestUtils.getDefaultReferer(context))
		private set

	init {
		System.loadLibrary("open_swiss_maps_shared")

		setupMap(swisstopoMapConfig)
		createBaseLayer()
	}

	private fun createBaseLayer() {
		baseLayer =
			SwisstopoLayerFactory.createSwisstopoTiledRasterLayer(SwisstopoLayerType.PIXELKARTE_FARBE, textureLoader)
		mapInterface.addLayer(baseLayer.asLayerInterface())
	}

	fun setBaseLayerType(layerType: SwisstopoLayerType) {
		val newLayer = SwisstopoLayerFactory.createSwisstopoTiledRasterLayer(layerType, textureLoader)
		mapInterface.removeLayer(baseLayer.asLayerInterface())
		mapInterface.addLayer(newLayer.asLayerInterface())
		baseLayer.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
		baseLayer = newLayer
	}
}