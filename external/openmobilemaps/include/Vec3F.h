// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from common.djinni

#pragma once

#include <utility>

struct Vec3F final {
    float x;
    float y;
    float z;

    Vec3F(float x_,
          float y_,
          float z_)
    : x(std::move(x_))
    , y(std::move(y_))
    , z(std::move(z_))
    {}
};