import MapCore
import SwisstopoMapSDKSharedModule
import UIKit

public class SwissTopoMapView: MCMapView {
    private let loader: MCTextureLoaderInterface

    open private(set) var baseLayer: MCTiled2dMapRasterLayerInterface

    public init(baseLayerType: STSDKSwisstopoLayerType = .PIXELKARTE_FARBE,
                loader: MCTextureLoaderInterface = MCTextureLoader()) {
        self.loader = loader

        guard let baseLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(baseLayerType, textureLoader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }

        self.baseLayer = baseLayer

        let coordinateSystem = MCCoordinateSystemFactory.getEpsg2056System()
        super.init(mapConfig: .init(mapCoordinateSystem: coordinateSystem,
                                    zoomMin: 4_000_000,
                                    zoomMax: 500))

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
