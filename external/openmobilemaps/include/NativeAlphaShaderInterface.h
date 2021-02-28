// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from shader.djinni

#pragma once

#include "AlphaShaderInterface.h"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeAlphaShaderInterface final : ::djinni::JniInterface<::AlphaShaderInterface, NativeAlphaShaderInterface> {
public:
    using CppType = std::shared_ptr<::AlphaShaderInterface>;
    using CppOptType = std::shared_ptr<::AlphaShaderInterface>;
    using JniType = jobject;

    using Boxed = NativeAlphaShaderInterface;

    ~NativeAlphaShaderInterface();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeAlphaShaderInterface>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeAlphaShaderInterface>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeAlphaShaderInterface();
    friend ::djinni::JniClass<NativeAlphaShaderInterface>;
    friend ::djinni::JniInterface<::AlphaShaderInterface, NativeAlphaShaderInterface>;

};

}  // namespace djinni_generated
