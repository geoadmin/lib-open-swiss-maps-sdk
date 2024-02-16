package ch.admin.geo.openswissmaps.util

import ch.admin.geo.openswissmaps.shared.layers.config.SwisstopoLayerType
import io.openmobilemaps.mapscore.map.util.MapViewInterface
import io.openmobilemaps.mapscore.shared.map.layers.tiled.Tiled2dMapZoomInfo
import io.openmobilemaps.mapscore.shared.map.layers.tiled.raster.Tiled2dMapRasterLayerInterface

interface SwisstopoMapViewInterface : MapViewInterface {
	fun setBaseLayerType(layerType: SwisstopoLayerType?)
	fun setBaseLayerType(identifier: String)
	fun addSwisstopoLayer(layerType: SwisstopoLayerType): Tiled2dMapRasterLayerInterface
	fun addSwisstopoLayer(layerType: SwisstopoLayerType, zoomInfo: Tiled2dMapZoomInfo): Tiled2dMapRasterLayerInterface
	fun addSwisstopoLayer(identifier: String): Tiled2dMapRasterLayerInterface?
	fun addSwisstopoLayer(identifier: String, zoomInfo: Tiled2dMapZoomInfo): Tiled2dMapRasterLayerInterface?
}