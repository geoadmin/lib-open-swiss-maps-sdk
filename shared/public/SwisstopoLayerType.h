// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from layer_configs.djinni

#pragma once

#include <functional>

enum class SwisstopoLayerType : int {
    PIXELKARTE_FARBE = 0,
    PIXELKARTE_FARK_PK1000 = 1,
    PIXELKARTE_GRAUSTUFEN = 2,
    PIXELKARTE_FARBE_WINTER = 3,
    SWISSIMAGE = 4,
    SWISSIMAGE_1946 = 5,
    LUFTFAHRTKARTEN_ICAO = 6,
    SEGELFLUGKARTE = 7,
    MIL_AIRSPACE_CHART = 8,
    SPERR_GEFAHRENZONENKARTE = 9,
    SWISSMILPILOTSCHART = 10,
    HIKS_DUFOR = 11,
    HIKS_SIEGFRIED = 12,
    SWISSTLM3D_EISENBAHNNETZ = 13,
    SWISSTLM3D_STRASSEN = 14,
    SWISSTLM3D_UEBRIGVERKEHR = 15,
    SWISSTLM3D_WANDERWEGE = 16,
    SCHWEIZMOBIL_WANDERLAND = 17,
    SCHWEIZMOBIL_VELOLAND = 18,
    SCHWEIZMOBIL_MOUNTAINBIKELAND = 19,
    HANGNEIGUNG_30 = 20,
    HANGNEIGUNGSKLASSEN_30 = 21,
    WILDSCHUTZ_GEBIETE = 22,
    WILDRUHEZONEN = 23,
    SCHNEESCHUH_ROUTEN = 24,
    SKI_TOUR_ROUTEN = 25,
    DROHNEN = 26,
    SCHUTZGEBIETE_LUFTFAHRT = 27,
    EISZEIT = 28,
};

constexpr const char* toString(SwisstopoLayerType e) noexcept {
    constexpr const char* names[] = {
        "PIXELKARTE_FARBE",
        "PIXELKARTE_FARK_PK1000",
        "PIXELKARTE_GRAUSTUFEN",
        "PIXELKARTE_FARBE_WINTER",
        "SWISSIMAGE",
        "SWISSIMAGE_1946",
        "LUFTFAHRTKARTEN_ICAO",
        "SEGELFLUGKARTE",
        "MIL_AIRSPACE_CHART",
        "SPERR_GEFAHRENZONENKARTE",
        "SWISSMILPILOTSCHART",
        "HIKS_DUFOR",
        "HIKS_SIEGFRIED",
        "SWISSTLM3D_EISENBAHNNETZ",
        "SWISSTLM3D_STRASSEN",
        "SWISSTLM3D_UEBRIGVERKEHR",
        "SWISSTLM3D_WANDERWEGE",
        "SCHWEIZMOBIL_WANDERLAND",
        "SCHWEIZMOBIL_VELOLAND",
        "SCHWEIZMOBIL_MOUNTAINBIKELAND",
        "HANGNEIGUNG_30",
        "HANGNEIGUNGSKLASSEN_30",
        "WILDSCHUTZ_GEBIETE",
        "WILDRUHEZONEN",
        "SCHNEESCHUH_ROUTEN",
        "SKI_TOUR_ROUTEN",
        "DROHNEN",
        "SCHUTZGEBIETE_LUFTFAHRT",
        "EISZEIT",
    };
    return names[static_cast<int>(e)];
}

namespace std {

template <>
struct hash<::SwisstopoLayerType> {
    size_t operator()(::SwisstopoLayerType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

} // namespace std
