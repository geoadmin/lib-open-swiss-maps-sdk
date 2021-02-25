/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

import MapCore
import SwisstopoMapSDKSharedModule
import UIKit

public class SwisstopoMapView: MCMapView {
    private let loader: MCTextureLoaderInterface

    open private(set) var baseLayer: MCTiled2dMapRasterLayerInterface

    public init(baseLayerType: STSDKSwisstopoLayerType = .PIXELKARTE_FARBE,
                loader: MCTextureLoaderInterface = SwisstopoTextureLoader(),
                zoomMin: Double = 5_500_000,
                zoomMax: Double = 500) {
        self.loader = loader

        guard let baseLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(baseLayerType, textureLoader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }

        self.baseLayer = baseLayer

        let coordinateSystem = MCCoordinateSystemFactory.getEpsg2056System()
        super.init(mapConfig: .init(mapCoordinateSystem: coordinateSystem,
                                    zoomMin: zoomMin,
                                    zoomMax: zoomMax))

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
}
