// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from common.djinni

#pragma once

#include "Vec3I.h"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeVec3I final {
public:
    using CppType = ::Vec3I;
    using JniType = jobject;

    using Boxed = NativeVec3I;

    ~NativeVec3I();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeVec3I();
    friend ::djinni::JniClass<NativeVec3I>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("io/openmobilemaps/mapscore/shared/graphics/common/Vec3I") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(III)V") };
    const jfieldID field_x { ::djinni::jniGetFieldID(clazz.get(), "x", "I") };
    const jfieldID field_y { ::djinni::jniGetFieldID(clazz.get(), "y", "I") };
    const jfieldID field_z { ::djinni::jniGetFieldID(clazz.get(), "z", "I") };
};

}  // namespace djinni_generated