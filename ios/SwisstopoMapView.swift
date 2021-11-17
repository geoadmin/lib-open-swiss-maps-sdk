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
@_exported import LayerGps
@_exported import SwisstopoMapSDKSharedModule
@_exported import MapCoreSharedModule
import UIKit

public class SwisstopoMapView: MCMapView {
    private let loader: MCLoaderInterface

    open private(set) var baseLayer: MCTiled2dMapRasterLayerInterface

    private(set) var currentBaseLayer: STSDKSwisstopoLayerType

    private lazy var capabilitiesResource = SwisstopoCapabilitiesResource.capabilitiesResource

    open private(set) var gpsLayer: MCGpsLayer?

    public init(baseLayerType: STSDKSwisstopoLayerType = .PIXELKARTE_FARBE,
                loader: MCLoaderInterface = SwisstopoTextureLoader()) {
        self.loader = loader
        self.currentBaseLayer = baseLayerType

        guard let baseLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(baseLayerType, loader: loader) else {
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
        guard currentBaseLayer != type else {
            // base layer is already set
            return
        }
        currentBaseLayer = type
        guard let newLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(type, loader: loader) else {
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
        guard let layer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(type, loader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }

        if let gpsLayer = gpsLayer {
            insert(layer: layer.asLayerInterface(), below: gpsLayer.asLayerInterface())
        } else {
            add(layer: layer.asLayerInterface())
        }

        return layer
    }

    @discardableResult
    public func addSwisstopoLayer(identifier: String) -> MCTiled2dMapRasterLayerInterface {
        guard let layer = capabilitiesResource.createLayer(identifier, tileLoader: loader) else {
            fatalError("Layer does not exist")
        }
        
        if let gpsLayer = gpsLayer {
            insert(layer: layer.asLayerInterface(), below: gpsLayer.asLayerInterface())
        } else {
            add(layer: layer.asLayerInterface())
        }

        return layer
    }

    @discardableResult
    public func addGpsLayer(style: MCGpsStyleInfo = .defaultStyle) -> MCGpsLayer {
        if let gpsLayer = gpsLayer {
            return gpsLayer
        }

        let layer = MCGpsLayer(style: style)

        gpsLayer = layer

        add(layer: layer.asLayerInterface())

        return layer
    }
}
