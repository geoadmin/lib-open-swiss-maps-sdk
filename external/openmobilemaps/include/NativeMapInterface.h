// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#pragma once

#include "MapInterface.h"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeMapInterface final : ::djinni::JniInterface<::MapInterface, NativeMapInterface> {
public:
    using CppType = std::shared_ptr<::MapInterface>;
    using CppOptType = std::shared_ptr<::MapInterface>;
    using JniType = jobject;

    using Boxed = NativeMapInterface;

    ~NativeMapInterface();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeMapInterface>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeMapInterface>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeMapInterface();
    friend ::djinni::JniClass<NativeMapInterface>;
    friend ::djinni::JniInterface<::MapInterface, NativeMapInterface>;

};

}  // namespace djinni_generated