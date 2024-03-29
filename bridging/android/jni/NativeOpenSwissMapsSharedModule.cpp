// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from open_swiss_maps.djinni

#include "NativeOpenSwissMapsSharedModule.h"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeOpenSwissMapsSharedModule::NativeOpenSwissMapsSharedModule() : ::djinni::JniInterface<::OpenSwissMapsSharedModule, NativeOpenSwissMapsSharedModule>("ch/admin/geo/openswissmaps/shared/OpenSwissMapsSharedModule$CppProxy") {}

NativeOpenSwissMapsSharedModule::~NativeOpenSwissMapsSharedModule() = default;


CJNIEXPORT void JNICALL Java_ch_admin_geo_openswissmaps_shared_OpenSwissMapsSharedModule_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        delete reinterpret_cast<::djinni::CppProxyHandle<::OpenSwissMapsSharedModule>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_admin_geo_openswissmaps_shared_OpenSwissMapsSharedModule_version(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        auto r = ::OpenSwissMapsSharedModule::version();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} // namespace djinni_generated
