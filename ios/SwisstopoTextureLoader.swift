/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

import Foundation
import MapCore
import SwisstopoMapSDKSharedModule

public class SwisstopoTextureLoader: MCTextureLoader {
    private var referer: String

    public override init(urlSession: URLSession? = nil) {
        let bundleIdentifier = Bundle.main.bundleIdentifier ?? "N/A"
        let appVersion = (Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String) ?? "N/A"
        let mapsCoreVersion = STSDKOpenSwissMapsSharedModule.version()
        referer = "\(bundleIdentifier);\(appVersion);openswissmaps;\(mapsCoreVersion)"
        super.init(urlSession: urlSession)
    }

    public override func modifyUrlRequest(request: inout URLRequest) {
        request.setValue(referer, forHTTPHeaderField: "referer")
    }
}
