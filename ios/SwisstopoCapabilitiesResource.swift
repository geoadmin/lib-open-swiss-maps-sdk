//
//  File.swift
//  
//
//  Created by Nicolas Märki on 03.03.21.
//

import Foundation
import MapCoreSharedModule
import MapCore

public class SwisstopoCapabilitiesResource {

    private init() {}

    public static let capabilitiesResource: MCWmtsCapabilitiesResource = {
        let url = Bundle.module.url(forResource: "WMTSCapabilities_2056", withExtension: "xml")
        let xml = try! String(contentsOf: url!)
        let resource = MCWmtsCapabilitiesResource.create(xml)!
        return resource
    }()
}
