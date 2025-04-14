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
import MapCoreSharedModule

public class SwisstopoCapabilitiesResource {

    private init() {}

    public static let capabilitiesResource: MCWmtsCapabilitiesResource = {
        let url = Bundle(for: SwisstopoCapabilitiesResource.self).url(forResource: "WMTSCapabilities_2056", withExtension: "xml")
        let xml = try! String(contentsOf: url!)
        let resource = MCWmtsCapabilitiesResource.create(xml)!
        return resource
    }()
}
