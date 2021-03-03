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



# Android

## How to use

### Add dependency
To add the OpenSwissMaps SDK to your Android project, add the following line to your build.gradle
```
dependencies {
  implementation 'ch.admin.geo.openswissmaps:openswissmaps-android:1.1.0'
}
```
Make sure you have jcenter() listed in your project repositories. 

### Display a Swisstopo Map

The SDK provides the `SwisstopoMapView` for configuring and displaying maps.  To use it, simply include it in a layout and register it to the lifecycle of the activity or fragment that contains the view. This is necessary for the execution of map internal tasks such as tile-loading.

```Kotlin
val mapView = findViewById<SwisstopoMapView>(R.id.map_view)
mapView.registerLifecycle(lifecycle)
```

##### Changing the default layer type

The map contains a base-layer that displays the `ch.swisstopo.pixelkarte-farbe` layer by default. The base-layer's type can be changed (or removed by passing `null`) at any time. For example with:

```Kotlin
mapView.setBaseLayerType(SwisstopoLayerType.SWISSIMAGE)
```

##### Adding multiple Swisstopo layers

New layers can easily be created on either the `SwisstopoMapView` directly or be added to it after using the `SwisstopoLayerFactory`. Their transparency value can be adjusted by calling `setAlpha` on the layer object.

```Kotlin
val layer = mapView.addSwisstopoLayer(SwisstopoLayerType.Drohnen)
```

 ```Kotlin
val layer = SwisstopoLayerFactory.createSwisstopoTiledRasterLayer(SwisstopoLayerType.DROHNEN, mapView.textureLoader)
layer.setAlpha(0.5)
mapView.addLayer(layer.asLayerInterface())
 ```

 See [available layers](../AVAILABLE_LAYERS.md) for a list of all supported layers.

##### Additional Swisstopo Layer Types

There are numerous additional layer types available via the Swisstopo wmts service. They can be added similarly to the predefined `SwisstopoLayerTypes`.

```Kotlin
val layer = mapView.addSwisstopoLayer("ch.bafu.neophyten-haargurke")
```

or via:

```Kotlin
val layer = mapView.swisstopoWmtsResource.createLayer("ch.bafu.neophyten-haargurke", mapView.textureLoader)
mapView.addLayer(layer.asLayerInterface())
```

Browse the [Geocatalog](https://map.geo.admin.ch) to find available data.

##### Adjusting the Camera

The camera position can easily be adjusted by manipulating the `Camera2dInterface` received from the map. E.g. to set it to a custom location:

```Kotlin
mapView.getCamera()
	.moveToCenterPositionZoom(Coord(CoordinateSystemIdentifiers.EPSG4326(), 8.543912536386152, 47.37623511643675, 0.0), 
	3000.0,
	true)
```

One can also change the default values for the camera's bounds and it's zoom range:

```kotlin
mapView.getCamera().setBounds(RectCoord(Coord(CoordinateSystemIdentifiers.EPSG2056(), 2485071.58, 1299941.79, 0.0), Coord(CoordinateSystemIdentifiers.EPSG2056(), 2828515.82, 1075346.31, 0.0)))
mapView.getCamera().setMinZoom(5000000.0)
mapView.getCamera().setMaxZoom(250.0)
```

##### Reacting to layer clicks

To react to user interaction with a layer, a callback handler can be set. E.g. on the baseLayer in the map (or any other tiled raster layer)

```kotlin
mapView.baseLayer?.setCallbackHandler(object : Tiled2dMapRasterLayerCallbackInterface() {
   override fun onClickConfirmed(coord: Coord): Boolean {
      // Return true, if the click has been consumed here
      return true
   }

   override fun onLongPress(coord: Coord): Boolean {
      // Return true, if the long press has been consumed here
      return true
   }
})
```

Please note that other layer types expose different functionalities in their callback handlers. The polygon layer, for example, returns the polygon hit by the click.

## How to build
[Installation & Build Instructions](docs/install_readme.md)

## License

This project is licensed under the terms of the MPL 2 license. See the [LICENSE](../LICENSE) file.
