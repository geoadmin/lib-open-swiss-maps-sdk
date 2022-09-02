package ch.admin.geo.openswissmaps.util

import android.content.Context
import io.openmobilemaps.mapscore.map.util.MapRenderHelper
import io.openmobilemaps.mapscore.map.util.MapViewRenderState
import io.openmobilemaps.mapscore.shared.graphics.common.Vec2I
import io.openmobilemaps.mapscore.shared.map.coordinates.RectCoord
import io.openmobilemaps.mapscore.shared.map.loader.LoaderInterface
import kotlinx.coroutines.CoroutineScope

class SwisstopoMapRenderHelper : MapRenderHelper() {

	companion object {
		@JvmStatic
		fun renderMap(
			context: Context,
			coroutineScope: CoroutineScope,
			loaders: ArrayList<LoaderInterface>? = null,
			onSetupMap: (SwisstopoMapViewInterface) -> Unit,
			onStateUpdate: (MapViewRenderState) -> Unit,
			renderBounds: RectCoord,
			renderSizePx: Vec2I,
			renderDensity: Float = 72f,
			renderTimeoutSeconds: Float = 20f
		) {
			onStateUpdate.invoke(MapViewRenderState.Loading)

			val mapRenderer = SwisstopoOffscreenMapRenderer(context, coroutineScope, renderSizePx, renderDensity)
			mapRenderer.setupMap(loaders)
			onSetupMap(mapRenderer)

			render(mapRenderer, renderBounds, renderTimeoutSeconds, onStateUpdate)
		}
	}

}