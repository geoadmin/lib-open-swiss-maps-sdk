# Android

## How to build

Make sure you have the necessary submodules for Djinni and [Open Mobile Maps](https://github.com/openmobilemaps/maps-core) initialized and updated. To do this, use

```
git submodule update --init
```

### Updating Djinni bridging files

The bridging interface between Kotlin and C++ are defined in the djinni files under [djinni](../djinni). After modifying those files the new bridging code can be generated by running

```make clean djinni```

in the folder [djinni](../djinni). This generates the Kotlin bindings, the C++ header files as well as all the JNI glue code.

### Building the Android Library

The Android library can be opened as an Android Studio project in the [android](.) folder. Alternatively, you can build the library using gradle from the command line using

```
./gradlew assemble
```

and you find the generated .aar library under `build/outputs/aar/`. For development, it is easiest to include this library directly as a module into a wrapping Android application project, that can be run on a device.

<h2>Installation</h2>

Either include the `android` folder as a module in the Android project or move the generated .aar to e.g. the `app/libs` folder of the project and include it in the project via the apps `build.gradle`:

```
implementation fileTree(dir: 'libs', include: ['*.aar'])
```

### Dependencies

When the Open Swiss Maps is included as .aar, the following dependencies in the apps `build.gradle` are necessary:

```
implementation "androidx.activity:activity-ktx:1.1.0"
implementation "androidx.lifecycle:lifecycle-runtime-ktx:2.2.0"
implementation "org.jetbrains.kotlinx:kotlinx-coroutines-android:1.4.2"
implementation 'com.squareup.okhttp3:okhttp:4.7.2' // used for the default TextureLoader
```

