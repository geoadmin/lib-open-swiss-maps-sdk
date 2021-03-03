// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wmts_capabilities.djinni

#pragma once

#include "TextureLoaderInterface.h"
#include "Tiled2dMapRasterLayerInterface.h"
#include <memory>
#include <string>
#include <vector>

struct WmtsLayerDescription;

class WmtsCapabilitiesResource {
public:
    virtual ~WmtsCapabilitiesResource() {}

    static std::shared_ptr<WmtsCapabilitiesResource> create(const std::string & xml);

    virtual std::shared_ptr<::Tiled2dMapRasterLayerInterface> createLayer(const std::string & identifier, const std::shared_ptr<::TextureLoaderInterface> & textureLoader) = 0;

    virtual std::vector<WmtsLayerDescription> getAllLayers() = 0;
};
