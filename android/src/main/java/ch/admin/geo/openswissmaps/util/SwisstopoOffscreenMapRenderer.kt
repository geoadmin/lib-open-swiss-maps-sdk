package ch.admin.geo.openswissmaps.util

import android.content.Context
import ch.admin.geo.openswissmaps.networking.RequestUtils
import ch.admin.geo.openswissmaps.shared.layers.config.SwisstopoLayerType
import ch.admin.geo.openswissmaps.shared.layers.config.SwisstopoTiledLayerConfigFactory
import io.openmobilemaps.mapscore.map.loader.DataLoader
import io.openmobilemaps.mapscore.map.util.OffscreenMapRenderer
import io.openmobilemaps.mapscore.shared.graphics.common.Vec2I
import io.openmobilemaps.mapscore.shared.map.LayerInterface
import io.openmobilemaps.mapscore.shared.map.MapConfig
import io.openmobilemaps.mapscore.shared.map.coordinates.CoordinateSystemFactory
import io.openmobilemaps.mapscore.shared.map.layers.tiled.Tiled2dMapZoomInfo
import io.openmobilemaps.mapscore.shared.map.layers.tiled.raster.Tiled2dMapRasterLayerInterface
import io.openmobilemaps.mapscore.shared.map.layers.tiled.raster.wmts.WmtsCapabilitiesResource
import io.openmobilemaps.mapscore.shared.map.loader.LoaderInterface
import kotlinx.coroutines.CoroutineScope

class SwisstopoOffscreenMapRenderer(context: Context, coroutineScope: CoroutineScope, sizePx: Vec2I, density: Float = 72f) : OffscreenMapRenderer(sizePx, density), SwisstopoMapViewInterface {

	companion object {
		private val BASE_LAYER_TYPE_DEFAULT = SwisstopoLayerType.PIXELKARTE_FARBE
	}

	private val swisstopoMapConfig: MapConfig = MapConfig(CoordinateSystemFactory.getEpsg2056System())

	val swisstopoWmtsResource: WmtsCapabilitiesResource by lazy {
		val str = context.assets.open("wmts/WMTSCapabilities_2056.xml").bufferedReader().use { it.readText() }
		WmtsCapabilitiesResource.create(str)
	}

	var baseLayerZoomInfo = Tiled2dMapZoomInfo(1.0f, 0, 0, false, false, true, true)
	var baseLayer: Tiled2dMapRasterLayerInterface? = null
		private set

	var loaders = arrayListOf(
		DataLoader(context, context.cacheDir, 50L * 1024L * 1024L, RequestUtils.getDefaultReferer(context)) as LoaderInterface
	)
		private set

	init {
		setupMap(coroutineScope, swisstopoMapConfig, true)
		createBaseLayer(BASE_LAYER_TYPE_DEFAULT)
	}

	fun setupMap(loaders: ArrayList<LoaderInterface>? = null) {
		loaders?.let { this.loaders = it }
	}

	private fun createBaseLayer(layerType: SwisstopoLayerType) {
		val newBaseLayer = Tiled2dMapRasterLayerInterface.create(
			SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfigWithZoomInfo(layerType, baseLayerZoomInfo),
			loaders
		)
		requireMapInterface().addLayer(newBaseLayer.asLayerInterface())
		baseLayer = newBaseLayer
	}

	override fun setBaseLayerType(layerType: SwisstopoLayerType?) {
		baseLayer?.let { requireMapInterface().removeLayer(it.asLayerInterface()) }
		baseLayer = if (layerType != null) {
			val newLayer = Tiled2dMapRasterLayerInterface.create(
				SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfigWithZoomInfo(
					layerType,
					baseLayerZoomInfo
				), loaders
			)
			requireMapInterface().insertLayerAt(newLayer.asLayerInterface(), 0)
			baseLayer?.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
			newLayer
		} else null
	}

	override fun setBaseLayerType(identifier: String) {
		baseLayer?.let { requireMapInterface().removeLayer(it.asLayerInterface()) }
		baseLayer = if (identifier.isNotEmpty()) {
			val newLayer = swisstopoWmtsResource.createLayer(identifier, loaders)
			if (newLayer != null) {
				requireMapInterface().insertLayerAt(newLayer.asLayerInterface(), 0)
				baseLayer?.getCallbackHandler()?.let { newLayer.setCallbackHandler(it) }
				newLayer
			} else null
		} else null
	}

	override fun removeLayer(layer: LayerInterface) {
		super.removeLayer(layer)
		if (layer == baseLayer?.asLayerInterface()) baseLayer = null
	}

	override fun addSwisstopoLayer(layerType: SwisstopoLayerType): Tiled2dMapRasterLayerInterface {
		val layer = Tiled2dMapRasterLayerInterface.create(SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfig(layerType), loaders)
		addLayer(layer.asLayerInterface())
		return layer
	}

	override fun addSwisstopoLayer(layerType: SwisstopoLayerType, zoomInfo: Tiled2dMapZoomInfo): Tiled2dMapRasterLayerInterface {
		val layer = Tiled2dMapRasterLayerInterface.create(SwisstopoTiledLayerConfigFactory.createRasterTileLayerConfigWithZoomInfo(layerType, zoomInfo), loaders)
		addLayer(layer.asLayerInterface())
		return layer
	}

	override fun addSwisstopoLayer(identifier: String): Tiled2dMapRasterLayerInterface? {
		val layer = swisstopoWmtsResource.createLayer(identifier, loaders) ?: return null
		addLayer(layer.asLayerInterface())
		return layer
	}

	override fun addSwisstopoLayer(identifier: String, zoomInfo: Tiled2dMapZoomInfo): Tiled2dMapRasterLayerInterface? {
		val layer = swisstopoWmtsResource.createLayerWithZoomInfo(identifier, loaders, zoomInfo) ?: return null
		addLayer(layer.asLayerInterface())
		return layer
	}

}