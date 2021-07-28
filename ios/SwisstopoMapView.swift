/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

@_exported import MapCore
@_exported import SwisstopoMapSDKSharedModule
@_exported import MapCoreSharedModule
import UIKit

public class SwisstopoMapView: MCMapView {
    private let loader: MCTileLoaderInterface

    open private(set) var baseLayer: MCTiled2dMapRasterLayerInterface

    private lazy var capabilitiesResource = SwisstopoCapabilitiesResource.capabilitiesResource

    public init(baseLayerType: STSDKSwisstopoLayerType = .PIXELKARTE_FARBE,
                loader: MCTileLoaderInterface = SwisstopoTextureLoader()) {
        self.loader = loader

        guard let baseLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(baseLayerType, textureLoader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }

        self.baseLayer = baseLayer

        let coordinateSystem = MCCoordinateSystemFactory.getEpsg2056System()
        super.init(mapConfig: .init(mapCoordinateSystem: coordinateSystem))

        camera.setMinZoom(10_000_000)
        camera.setMaxZoom(300)
        camera.setZoom(10_000_000, animated: false)

        add(layer: baseLayer.asLayerInterface())
    }

    public func setBaseLayerType(type: STSDKSwisstopoLayerType) {
        guard let newLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(type, textureLoader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }

        if let oldCallbackHandler = baseLayer.getCallbackHandler() {
            newLayer.setCallbackHandler(oldCallbackHandler)
        }
        remove(layer: baseLayer.asLayerInterface())

        baseLayer = newLayer

        insert(layer: newLayer.asLayerInterface(), at: 0)
    }

    @discardableResult
    public func addSwisstopoLayer(type: STSDKSwisstopoLayerType) -> MCTiled2dMapRasterLayerInterface {
        guard let layer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(type, textureLoader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }
        add(layer: layer.asLayerInterface())
        return layer
    }

    @discardableResult
    public func addSwisstopoLayer(identifier: String) -> MCTiled2dMapRasterLayerInterface {
        guard let layer = capabilitiesResource.createLayer(identifier, tileLoader: loader) else {
            fatalError("Layer does not exist")
        }

        add(layer: layer.asLayerInterface())
        return layer
    }
}
