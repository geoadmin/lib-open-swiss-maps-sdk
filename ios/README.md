<h1 align="center">OpenSwissMapsSDK</h1>

<br />

<div align="center">
  <img width="200" height="45" src="logo.svg" />
</div>

<div align="center">
    <!-- SPM -->
    <a href="https://github.com/apple/swift-package-manager">
      <img alt="Swift Package Manager"
      src="https://img.shields.io/badge/SPM-%E2%9C%93-brightgreen.svg?style=flat">
    </a>
    <!-- License -->
    <a href="https://github.com/geoadmin/lib-open-swiss-maps-sdk/blob/master/LICENSE">
      <img alt="TODO" src="TODO">
    </a>
    <!-- iOS Build -->
    <a href="https://github.com/geoadmin/lib-open-swiss-maps-sdk/actions/workflows/ios.yml">
      <img alt="Build status: iOS"
      src="https://github.com/geoadmin/lib-open-swiss-maps-sdk/actions/workflows/ios.yml/badge.svg">
    </a>
    <!-- android Build -->
    <a href="https://github.com/geoadmin/lib-open-swiss-maps-sdk/actions/workflows/android.yml">
      <img alt="Build status: android"
      src="https://github.com/geoadmin/lib-open-swiss-maps-sdk/actions/workflows/android.yml/badge.svg">
    </a>
</div>

# iOS

[Installation & Build Instructions](docs/install_readme.md)

## How To use

##### Display Swisstopo Map in a ViewController

The SDK provides a the view SwisstopoMapView which is a UIView subclass. By default the `ch.swisstopo.pixelkarte-farbe`layer is displayed.

```swift
import UIKit
import SwisstopoMapSDK

class MapViewController: UIViewController {
  lazy var mapView = SwisstopoMapView()
  override func loadView() {
    view = mapView
  }
}
```

##### Initializing the view with a different baselayer type

```swift
lazy var mapView = SwisstopoMapView(baseLayerType: .SWISSIMAGE)
```

##### Changing the baselayer type after initializing the view

```swift
mapView.setBaseLayerType(type: .PIXELKARTE_GRAUSTUFEN)
```

##### Adding multiple layer 

```swift
let drohnenLayer = mapView.addSwisstopoLayer(type: .DROHNEN)
drohnenLayer.setAlpha(0.25)
```

##### Adjusting the camera

The camera position can easily be adjusted by manipulating the Camera2dInterface received from the map. E.g. to set a custom location:

```swift
mapView.camera.move(toCenterPosition: .init(systemIdentifier: MCCoordinateSystemIdentifiers.epsg4326(),
                                                x: 8.378232525377973,
                                                y: 46.962592372639634,
                                                z: 0), animated: true)
```

One can also change the default values for the camera's bounds and it's zoom range:

```kotlin
mapView.camera.setBounds(bounds: MCRectCoord(topLeft: MCCoord(systemIdentifier: MCCoordinateSystemIdentifiers.epsg2056(), x: 2485071.58, y: 1299941.79, z: 0.0), bottomRight: MCCoord(systemIdentifier: MCCoordinateSystemIdentifiers.epsg2056(), x: 2828515.82, y: 1075346.31, z: 0.0)))
mapView.camera.setMinZoom(5000000.0)
mapView.camera.setMaxZoom(250.0)
```

##### Reacting to clicks on a layer

```swift
import UIKit
import SwisstopoMapSDK
import MapCoreSharedModule

class MapViewController: UIViewController {
  lazy var mapView = SwisstopoMapView(baseLayerType: .SWISSIMAGE)
  
  override func loadView() {
    view = mapView
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    mapView.baseLayer.setCallbackHandler(self)
  }
}

extension MapViewController: MCTiled2dMapRasterLayerCallbackInterface {
  func onClickConfirmed(_ coord: MCCoord) -> Bool {
    // react to click
    // return true if interaction was consumend
    return true
  }
  func onLongPress(_ coord: MCCoord) -> Bool {
    // react to longpress
    // return true if interaction was consumend
    return true
  }
}
```
