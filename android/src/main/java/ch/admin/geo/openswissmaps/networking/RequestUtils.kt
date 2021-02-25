/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

package ch.admin.geo.openswissmaps.networking

import android.content.Context
import android.content.pm.PackageManager
import ch.admin.geo.openswissmaps.BuildConfig

object RequestUtils {

	fun getDefaultReferer(context: Context): String {
		val packageInfo = try {
			context.packageManager.getPackageInfo(context.packageName, 0)
		} catch (e: PackageManager.NameNotFoundException) {
			e.printStackTrace()
			null
		}
		return context.packageName + ";" + (packageInfo?.versionName
			?: "-") + ";openswissmaps;" + BuildConfig.VERSION_NAME
	}

}