<h1 align="center">Open Swiss Maps SDK</h1>

<br />

<div align="center">
  <img width="90" height="90" src="../logo.png" />
<br />
<br />
</div>

<div align="center">
    <!-- SPM -->
    <a href="https://github.com/apple/swift-package-manager">
      <img alt="Swift Package Manager"
      src="https://img.shields.io/badge/SPM-%E2%9C%93-brightgreen.svg?style=flat">
    </a>
    <!-- License -->
    <a href="https://github.com/openmobilemaps/maps-core/blob/master/LICENSE">
      <img alt="License: MPL 2.0"
      src="https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg">
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

## Installation

Open Mobile Maps is available through [Swift Package Manager](https://swift.org/package-manager/).

For App integration within Xcode, add this package to your App target. To do this, follow the step by step tutorial [Adding Package Dependencies to Your App](https://developer.apple.com/documentation/xcode/adding_package_dependencies_to_your_app) and add the package with the url:
```
https://github.com/geoadmin/lib-open-swiss-maps-sdk.git
```

### Swift Package

Once you have your Swift package set up, adding Open Mobile Maps as a dependency is as easy as adding it to the dependencies value of your Package.swift.

```swift
dependencies: [
    .package(url: "https://github.com/geoadmin/lib-open-swiss-maps-sdk.git", .upToNextMajor(from: "3.4.0"))
]
```

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

See [available layers](../AVAILABLE_LAYERS.md) for a list of all supported layers.

##### Adding layer using WMTS identifier

There are numerous additional layer types available via the Swisstopo wmts service. They can be added similarly to the predefined `SwisstopoLayerTypes`.

```swift
let neophytenLayer = mapView.addSwisstopoLayer(identifier: "ch.bafu.neophyten-haargurke")
```

Browse the [Geocatalog](https://map.geo.admin.ch) to find available data.

##### Adjusting the camera

The camera position can easily be adjusted by manipulating the Camera2dInterface received from the map. E.g. to set a custom location:

```swift
mapView.camera.move(toCenterPosition: .init(systemIdentifier: MCCoordinateSystemIdentifiers.epsg4326(),
                                                x: 8.378232525377973,
                                                y: 46.962592372639634,
                                                z: 0), animated: true)
```

One can also change the default values for the camera's bounds and it's zoom range:

```swift 
mapView.camera.setBounds(MCRectCoord(topLeft: MCCoord(systemIdentifier: MCCoordinateSystemIdentifiers.epsg2056(), x: 2485071.58, y: 1299941.79, z: 0.0),
                                     bottomRight: MCCoord(systemIdentifier: MCCoordinateSystemIdentifiers.epsg2056(), x: 2828515.82, y: 1075346.31, z: 0.0)))
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

#### Adding a gps layer

A gps layer can conveniently be added to the `SwisstopoMapView` by calling:
```swift
mapView.addGpsLayer()
```

##### Style

The layer can be visually customized at creation time by also supplying a `MCGpsStyleInfo`:
```swift
public extension MCGpsStyleInfo {
    static var customStyle: MCGpsStyleInfo {
        guard let pointImage = UIImage(named: "ic_gps_point", in: .module, compatibleWith: nil),
              let pointCgImage = pointImage.cgImage,
              let pointTexture = try? TextureHolder(pointCgImage),
              let headingImage = UIImage(named: "ic_gps_direction", in: .module, compatibleWith: nil),
              let headingCgImage = headingImage.cgImage,
              let headingTexture = try? TextureHolder(headingCgImage) else {
                  fatalError("gps style assets not found")
              }

        return MCGpsStyleInfo(pointTexture: pointTexture,
                       headingTexture: headingTexture,
                              accuracyColor:  UIColor(red: 112/255,
                                                      green: 173/255,
                                                      blue: 204/255,
                                                      alpha: 0.2).mapCoreColor)
    }
}
```

##### Modes and Heading

The `GpsLayer` has four different modes to react to location updates:

**DISABLED**: No gps indicator is rendered on the map.

**STANDARD**: The indicator is drawn  at the current location, along with the current heading (if enabled and a texture is provided)

**FOLLOW**: In addition to the same behavior as `STANDARD`, upon a location update, the camera is animated to keep the indicators position centered in the map.

**FOLLOW_AND_TURN**: While following the indicators location updates (as in `FOLLOW`), the camera is rotated to have the map oriented in the direction of the current heading.


## How to build
[Build Instructions](docs/install_readme.md)
