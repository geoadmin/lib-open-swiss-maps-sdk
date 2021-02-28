# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

file(GLOB_RECURSE cpp_SRC
        "../bridging/android/jni/*.h"
        "../bridging/android/jni/*.hpp"
        "../bridging/android/jni/*.cpp"
        "../shared/src/*.h"
        "../shared/src/*.cpp"
        "../shared/src/*.hpp"
        "src/main/cpp/*.h"
        "src/main/cpp/*.cpp"
        "../external/djinni/support-lib/*.h"
        "../external/djinni/support-lib/*.hpp"
        "../external/djinni/support-lib/*.cpp"
        )

add_library( # Sets the name of the library.
        open_swiss_maps_shared

        # Sets the library as a shared library.
        SHARED

        ${cpp_SRC})

include_directories(../external/djinni/support-lib)
include_directories(../external/djinni/support-lib/jni)
include_directories(../bridging/android/jni/layers)
include_directories(../bridging/android/jni/layers/config)
include_directories(../shared/src)
include_directories(../shared/src/layers)
include_directories(../shared/src/layers/config)
include_directories(../shared/public)
include_directories(src/main/cpp)

include_directories(../external/openmobilemaps/include)


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        open_swiss_maps_shared

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

find_library(opengl-lib
        GLESv2)

target_link_libraries(open_swiss_maps_shared
        ${opengl-lib})

add_library(mapscore_shared SHARED IMPORTED)
set_property(TARGET mapscore_shared PROPERTY IMPORTED_LOCATION "../../../../../external/openmobilemaps/libs/android.${CMAKE_ANDROID_ARCH_ABI}/libmapscore_shared.so")
target_link_libraries(open_swiss_maps_shared mapscore_shared)