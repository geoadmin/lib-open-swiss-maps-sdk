# iOS

## Installation

Open Mobile Maps is available through [Swift Package Manager](https://swift.org/package-manager/).

### Xcode

For App integration within XCode, add this package to your App target. To do this, follow the step by step tutorial [Adding Package Dependencies to Your App](https://developer.apple.com/documentation/xcode/adding_package_dependencies_to_your_app).

### Swift Package

Once you have your Swift package set up, adding Open Mobile Maps as a dependency is as easy as adding it to the dependencies value of your Package.swift.

```swift
dependencies: [
    .package(url: "https://github.com/geoadmin/lib-open-swiss-maps-sdk.git", .upToNextMajor(from: "1.0.0"))
]
```

### iOS 10

Unfortunately, Swift package is only supported starting with iOS 11. If you need iOS 10 support you have to compile the library as a framework yourself.

## How to build

If you'd like to build Open Mobile Maps yourself, make sure you have all submodules initialized and updated. To do this, use

```shell
git submodule init
git submodule update
```

### Updating Djinni bridging files

The bridging interface between Kotlin and C++ are defined in the djinni files under [djinni](../djinni). After modifying those files, the new bridging code can be generated by running

```make clean djinni```

in the folder [djinni](../djinni). This generates the Kotlin bindings, the C++ header files as well as all the Objective C glue code.

### Building the iOS Package.

The [Package.swift](../Package.swift) file can be opened in Xcode and build directly from there. 