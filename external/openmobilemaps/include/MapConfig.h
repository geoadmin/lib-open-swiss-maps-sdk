// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#pragma once

#include "MapCoordinateSystem.h"
#include <utility>

struct MapConfig final {
    ::MapCoordinateSystem mapCoordinateSystem;

    MapConfig(::MapCoordinateSystem mapCoordinateSystem_)
    : mapCoordinateSystem(std::move(mapCoordinateSystem_))
    {}
};