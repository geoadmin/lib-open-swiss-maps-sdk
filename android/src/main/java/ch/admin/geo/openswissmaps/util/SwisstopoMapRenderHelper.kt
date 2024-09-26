package ch.admin.geo.openswissmaps.util

import android.content.Context
import io.openmobilemaps.mapscore.map.util.MapRenderHelper
import io.openmobilemaps.mapscore.map.util.MapViewRenderState
import io.openmobilemaps.mapscore.shared.graphics.common.Vec2I
import io.openmobilemaps.mapscore.shared.map.coordinates.RectCoord
import io.openmobilemaps.mapscore.shared.map.loader.LoaderInterface
import io.openmobilemaps.mapscore.shared.map.scheduling.ExecutionEnvironment
import io.openmobilemaps.mapscore.shared.map.scheduling.TaskConfig
import io.openmobilemaps.mapscore.shared.map.scheduling.TaskInterface
import io.openmobilemaps.mapscore.shared.map.scheduling.TaskPriority
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

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

			mapRenderer.requireMapInterface().getScheduler().addTask(object : TaskInterface() {
				override fun getConfig() = TaskConfig("render_task_start", 0, TaskPriority.NORMAL, ExecutionEnvironment.GRAPHICS)

				override fun run() {
					coroutineScope.launch(Dispatchers.Default) {
						render(mapRenderer, renderBounds, renderTimeoutSeconds, onStateUpdate, true)
					}
				}
			})
		}
	}

}