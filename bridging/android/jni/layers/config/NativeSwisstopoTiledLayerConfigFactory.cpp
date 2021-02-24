// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from layer_configs.djinni

#include "NativeSwisstopoTiledLayerConfigFactory.h"  // my header
#include "NativeSwisstopoLayerType.h"
#include "NativeTiled2dMapLayerConfig.h"

namespace djinni_generated {

NativeSwisstopoTiledLayerConfigFactory::NativeSwisstopoTiledLayerConfigFactory() : ::djinni::JniInterface<::SwisstopoTiledLayerConfigFactory, NativeSwisstopoTiledLayerConfigFactory>("ch/admin/geo/openswissmaps/shared/layers/config/SwisstopoTiledLayerConfigFactory$CppProxy") {}

NativeSwisstopoTiledLayerConfigFactory::~NativeSwisstopoTiledLayerConfigFactory() = default;


CJNIEXPORT void JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::SwisstopoTiledLayerConfigFactory>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT ::djinni_generated::NativeTiled2dMapLayerConfig::JniType JNICALL Java_ch_admin_geo_openswissmaps_shared_layers_config_SwisstopoTiledLayerConfigFactory_00024CppProxy_createRasterTileLayerConfig(JNIEnv* jniEnv, jobject /*this*/, jobject j_layerType)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfig(::djinni_generated::NativeSwisstopoLayerType::toCpp(jniEnv, j_layerType));
        return ::djinni::release(::djinni_generated::NativeTiled2dMapLayerConfig::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
