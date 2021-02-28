// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from touch_handler.djinni

#pragma once

#include <functional>

enum class TouchAction : int {
    DOWN,
    MOVE,
    UP,
};

namespace std {

template <>
struct hash<::TouchAction> {
    size_t operator()(::TouchAction type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
