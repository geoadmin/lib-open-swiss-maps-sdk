/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

#include "SwisstopoTiledLayerConfigHelper.h"
#include "CoordinateSystemIdentifiers.h"
#include "WmtsLayerDescription.h"
#include "WmtsTiled2dMapLayerConfigFactory.h"
#include <vector>

const RectCoord SwisstopoTiledLayerConfigHelper::bounds = RectCoord(Coord(CoordinateSystemIdentifiers::EPSG2056(), 2420000, 1350000, 0),
                                                                    Coord(CoordinateSystemIdentifiers::EPSG2056(), 2900000, 1030000, 0));

// taken from https://wmts.geo.admin.ch/1.0.0/WMTSCapabilities.xml,layer=ch.bafu.wasser-leitungen
std::vector<Tiled2dMapZoomLevelInfo> SwisstopoTiledLayerConfigHelper::getZoomLevelInfos() {
    return {
        getZoomLevelInfo(14285714.2857, 1024000, 1, 1, 1, 0),
        getZoomLevelInfo(13392857.1429, 960000, 1, 1, 1, 1),
        getZoomLevelInfo(12500000.0, 896000, 1, 1, 1, 2),
        getZoomLevelInfo(11607142.8571, 832000, 1, 1, 1, 3),
        getZoomLevelInfo(10714285.7143, 768000, 1, 1, 1, 4),
        getZoomLevelInfo(9821428.57143, 704000, 1, 1, 1, 5),
        getZoomLevelInfo(8928571.42857, 640000, 1, 1, 1, 6),
        getZoomLevelInfo(8035714.28571, 576000, 1, 1, 1, 7),
        getZoomLevelInfo(7142857.14286, 512000, 1, 1, 1, 8),
        getZoomLevelInfo(6250000.0, 448000, 2, 1, 1, 9),
        getZoomLevelInfo(5357142.85714, 384000, 2, 1, 1, 10),
        getZoomLevelInfo(4464285.71429, 320000, 2, 1, 1, 11),
        getZoomLevelInfo(3571428.57143, 256000, 2, 2, 1, 12),
        getZoomLevelInfo(2678571.42857, 192000, 3, 2, 1, 13),
        getZoomLevelInfo(2321428.57143, 166400, 3, 2, 1, 14),
        getZoomLevelInfo(1785714.28571, 128000, 4, 3, 1, 15),
        getZoomLevelInfo(892857.142857, 64000, 8, 5, 1, 16),
        getZoomLevelInfo(357142.857143, 25600, 19, 13, 1, 17),
        getZoomLevelInfo(178571.428571, 12800, 38, 25, 1, 18),
        getZoomLevelInfo(71428.5714286, 5120, 94, 63, 1, 19),
        getZoomLevelInfo(35714.2857143, 2560, 188, 125, 1, 20),
        getZoomLevelInfo(17857.1428571, 1280, 375, 250, 1, 21),
        getZoomLevelInfo(8928.57142857, 640, 750, 500, 1, 22),
        getZoomLevelInfo(7142.85714286, 512, 938, 625, 1, 23),
        getZoomLevelInfo(5357.14285714, 384, 1250, 834, 1, 24),
        getZoomLevelInfo(3571.42857143, 256, 1875, 1250, 1, 25),
        getZoomLevelInfo(1785.71428571, 128, 3750, 2500, 1, 26),
        getZoomLevelInfo(892.857142857, 64, 7500, 5000, 1, 27),
        getZoomLevelInfo(357.142857143, 25.6, 18750, 12500, 1, 28)};
}


Tiled2dMapZoomLevelInfo SwisstopoTiledLayerConfigHelper::getZoomLevelInfo(double zoom,
                                                                          float tileWidthLayerSystemUnits,
                                                                          int32_t numTilesX,
                                                                          int32_t numTilesY,
                                                                          int32_t numTilesT,
                                                                          int32_t zoomLevelIdentifier) {
    const auto bounds = RectCoord(SwisstopoTiledLayerConfigHelper::bounds.topLeft,
                                  Coord(CoordinateSystemIdentifiers::EPSG2056(), SwisstopoTiledLayerConfigHelper::bounds.topLeft.x + tileWidthLayerSystemUnits * numTilesX, SwisstopoTiledLayerConfigHelper::bounds.topLeft.y - tileWidthLayerSystemUnits * numTilesY, 0));

    return Tiled2dMapZoomLevelInfo(zoom,tileWidthLayerSystemUnits, numTilesX, numTilesY, numTilesT, zoomLevelIdentifier, bounds);
}
