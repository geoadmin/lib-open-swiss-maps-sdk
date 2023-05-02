// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from layer_configs.djinni

#include "NativeSwisstopoTiledLayerConfigFactory.h"  // my header
#include "Marshal.hpp"
#include "NativeSwisstopoLayerType.h"
#include "NativeTiled2dMapLayerConfig.h"
#include "NativeTiled2dMapZoomInfo.h"
#include "NativeWmtsLayerDescription.h"

namespace djinni_generated {

NativeSwisstopoTiledLayerConfigFactory::NativeSwisstopoTiledLayerConfigFactory() : ::djinni::JniInterface<::SwisstopoTiledLayerConfigFactory, NativeSwisstopoTiledLayerConfigFactory>("ch/admin/geo/openswissmaps/shared/layers/config/SwisstopoTiledLayerConfigFactory$CppProxy") {}

NativeSwisstopoTiledLayerConfigFactory::~NativeSwisstopoTiledLayerConfigFactory() = default;


CJNIEXPORT void JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        delete reinterpret_cast<::djinni::CppProxyHandle<::SwisstopoTiledLayerConfigFactory>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapLayerConfig::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_createRasterTileLayerConfig(JNIEnv* jniEnv, jobject /*this*/, jobject j_layerType)
{
    try {
        auto r = ::SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfig(::djinni_generated::NativeSwisstopoLayerType::toCpp(jniEnv, j_layerType));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapLayerConfig::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapLayerConfig::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_createRasterTileLayerConfigWithZoomInfo(JNIEnv* jniEnv, jobject /*this*/, jobject j_layerType, ::djinni_generated::NativeTiled2dMapZoomInfo::Boxed::JniType j_zoomInfo)
{
    try {
        auto r = ::SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfigWithZoomInfo(::djinni_generated::NativeSwisstopoLayerType::toCpp(jniEnv, j_layerType),
                                                                                             ::djinni::Optional<std::optional, ::djinni_generated::NativeTiled2dMapZoomInfo>::toCpp(jniEnv, j_zoomInfo));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapLayerConfig::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapLayerConfig::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_createRasterTileLayerConfigWithBaseUrl(JNIEnv* jniEnv, jobject /*this*/, jobject j_layerType, ::djinni_generated::NativeTiled2dMapZoomInfo::Boxed::JniType j_zoomInfo, jstring j_baseUrl)
{
    try {
        auto r = ::SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfigWithBaseUrl(::djinni_generated::NativeSwisstopoLayerType::toCpp(jniEnv, j_layerType),
                                                                                            ::djinni::Optional<std::optional, ::djinni_generated::NativeTiled2dMapZoomInfo>::toCpp(jniEnv, j_zoomInfo),
                                                                                            ::djinni::Optional<std::optional, ::djinni::String>::toCpp(jniEnv, j_baseUrl));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapLayerConfig::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapLayerConfig::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_createRasterTiledLayerConfigFromMetadata(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::NativeWmtsLayerDescription::JniType j_configuration, jint j_maxZoom, ::djinni_generated::NativeTiled2dMapZoomInfo::JniType j_zoomInfo)
{
    try {
        auto r = ::SwisstopoTiledLayerConfigFactory::createRasterTiledLayerConfigFromMetadata(::djinni_generated::NativeWmtsLayerDescription::toCpp(jniEnv, j_configuration),
                                                                                              ::djinni::I32::toCpp(jniEnv, j_maxZoom),
                                                                                              ::djinni_generated::NativeTiled2dMapZoomInfo::toCpp(jniEnv, j_zoomInfo));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapLayerConfig::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} // namespace djinni_generated
