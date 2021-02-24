import MapCore
import SwisstopoMapSDKSharedModule
import UIKit

public class SwissTopoMapView: MCMapView {
    private let loader: MCTextureLoaderInterface

    private var baseLayer: MCTiled2dMapRasterLayerInterface?

    public init(baseLayerType: STSDKSwisstopoLayerType = .PIXELKARTE_FARBE,
                loader: MCTextureLoaderInterface = MCTextureLoader()) {
        self.loader = loader

        let coordinateSystem = MCCoordinateSystemFactory.getEpsg2056System()
        super.init(mapConfig: .init(mapCoordinateSystem: coordinateSystem,
                                    zoomMin: 4_000_000,
                                    zoomMax: 500))
        baseLayer = addSwisstopoLayer(type: baseLayerType)
    }

    public func setBaseLayerType(type: STSDKSwisstopoLayerType) {
        guard let newLayer = STSDKSwisstopoLayerFactory.createSwisstopoTiledRasterLayer(type, textureLoader: loader) else {
            fatalError("unable to create SwisstopoLayer")
        }

        if let layer = baseLayer {
            if let oldCallbackHandler = layer.getCallbackHandler() {
                newLayer.setCallbackHandler(oldCallbackHandler)
            }
            remove(layer: layer.asLayerInterface())
        }

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
