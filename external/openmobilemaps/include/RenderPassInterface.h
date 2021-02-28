// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#pragma once

#include "GraphicsObjectInterface.h"
#include <memory>
#include <vector>

struct RenderPassConfig;

class RenderPassInterface {
public:
    virtual ~RenderPassInterface() {}

    virtual std::vector<std::shared_ptr<::GraphicsObjectInterface>> getGraphicsObjects() = 0;

    virtual RenderPassConfig getRenderPassConfig() = 0;
};