// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from layers.djinni

#include "NativeSwisstopoLayerFactory.h"  // my header
#include "Marshal.hpp"
#include "NativeSwisstopoLayerType.h"
#include "NativeTileLoaderInterface.h"
#include "NativeTiled2dMapRasterLayerInterface.h"
#include "NativeTiled2dMapZoomInfo.h"
#include "NativeWmtsLayerDescription.h"

namespace djinni_generated {

NativeSwisstopoLayerFactory::NativeSwisstopoLayerFactory() : ::djinni::JniInterface<::SwisstopoLayerFactory, NativeSwisstopoLayerFactory>("ch/admin/geo/openswissmaps/shared/layers/SwisstopoLayerFactory$CppProxy") {}

NativeSwisstopoLayerFactory::~NativeSwisstopoLayerFactory() = default;


CJNIEXPORT void JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_SwisstopoLayerFactory_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::SwisstopoLayerFactory>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapRasterLayerInterface::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_SwisstopoLayerFactory_00024CppProxy_createSwisstopoTiledRasterLayer(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::NativeSwisstopoLayerType::JniType j_layerType, ::djinni_generated::NativeTileLoaderInterface::JniType j_tileLoader)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::SwisstopoLayerFactory::createSwisstopoTiledRasterLayer(::djinni_generated::NativeSwisstopoLayerType::toCpp(jniEnv, j_layerType),
                                                                          ::djinni_generated::NativeTileLoaderInterface::toCpp(jniEnv, j_tileLoader));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapRasterLayerInterface::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapRasterLayerInterface::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_SwisstopoLayerFactory_00024CppProxy_createSwisstopoTiledRasterLayerFromMetadata(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::NativeWmtsLayerDescription::JniType j_description, jint j_maxZoom, ::djinni_generated::NativeTiled2dMapZoomInfo::JniType j_zoomInfo, ::djinni_generated::NativeTileLoaderInterface::JniType j_tileLoader)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::SwisstopoLayerFactory::createSwisstopoTiledRasterLayerFromMetadata(::djinni_generated::NativeWmtsLayerDescription::toCpp(jniEnv, j_description),
                                                                                      ::djinni::I32::toCpp(jniEnv, j_maxZoom),
                                                                                      ::djinni_generated::NativeTiled2dMapZoomInfo::toCpp(jniEnv, j_zoomInfo),
                                                                                      ::djinni_generated::NativeTileLoaderInterface::toCpp(jniEnv, j_tileLoader));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapRasterLayerInterface::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
