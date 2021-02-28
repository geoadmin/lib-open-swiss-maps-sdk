// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loader.djinni

#pragma once

#include "TextureLoaderResult.h"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeTextureLoaderResult final {
public:
    using CppType = ::TextureLoaderResult;
    using JniType = jobject;

    using Boxed = NativeTextureLoaderResult;

    ~NativeTextureLoaderResult();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeTextureLoaderResult();
    friend ::djinni::JniClass<NativeTextureLoaderResult>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("io/openmobilemaps/mapscore/shared/map/loader/TextureLoaderResult") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Lio/openmobilemaps/mapscore/shared/graphics/objects/TextureHolderInterface;Lio/openmobilemaps/mapscore/shared/map/loader/LoaderStatus;)V") };
    const jfieldID field_data { ::djinni::jniGetFieldID(clazz.get(), "data", "Lio/openmobilemaps/mapscore/shared/graphics/objects/TextureHolderInterface;") };
    const jfieldID field_status { ::djinni::jniGetFieldID(clazz.get(), "status", "Lio/openmobilemaps/mapscore/shared/map/loader/LoaderStatus;") };
};

}  // namespace djinni_generated