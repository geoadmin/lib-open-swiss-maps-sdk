package ch.admin.geo.openswissmaps

import io.openmobilemaps.gps.LayerGps
import io.openmobilemaps.mapscore.MapsCore

object OpenSwissMaps {
	fun initialize() {
		System.loadLibrary("openswissmaps")
		LayerGps.initialize()
		MapsCore.initialize()
	}
}