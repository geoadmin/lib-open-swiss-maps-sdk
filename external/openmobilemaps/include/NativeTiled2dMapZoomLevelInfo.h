// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from tiled_layer.djinni

#pragma once

#include "Tiled2dMapZoomLevelInfo.h"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeTiled2dMapZoomLevelInfo final {
public:
    using CppType = ::Tiled2dMapZoomLevelInfo;
    using JniType = jobject;

    using Boxed = NativeTiled2dMapZoomLevelInfo;

    ~NativeTiled2dMapZoomLevelInfo();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeTiled2dMapZoomLevelInfo();
    friend ::djinni::JniClass<NativeTiled2dMapZoomLevelInfo>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("io/openmobilemaps/mapscore/shared/map/layers/tiled/Tiled2dMapZoomLevelInfo") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(DFIII)V") };
    const jfieldID field_zoom { ::djinni::jniGetFieldID(clazz.get(), "zoom", "D") };
    const jfieldID field_tileWidthLayerSystemUnits { ::djinni::jniGetFieldID(clazz.get(), "tileWidthLayerSystemUnits", "F") };
    const jfieldID field_numTilesX { ::djinni::jniGetFieldID(clazz.get(), "numTilesX", "I") };
    const jfieldID field_numTilesY { ::djinni::jniGetFieldID(clazz.get(), "numTilesY", "I") };
    const jfieldID field_zoomLevelIdentifier { ::djinni::jniGetFieldID(clazz.get(), "zoomLevelIdentifier", "I") };
};

}  // namespace djinni_generated
