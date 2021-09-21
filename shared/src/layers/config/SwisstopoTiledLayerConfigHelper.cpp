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
#include "WmtsLayerConfiguration.h"
#include "WmtsTiled2dMapLayerConfigFactory.h"
#include <vector>

// taken from https://wmts.geo.admin.ch/1.0.0/WMTSCapabilities.xml,layer=ch.bafu.wasser-leitungen
std::vector<Tiled2dMapZoomLevelInfo> SwisstopoTiledLayerConfigHelper::getZoomLevelInfos() {
    return {
        //Tiled2dMapZoomLevelInfo(14285714.2857, 1024000, 1, 1, 0, getBounds()),    Tiled2dMapZoomLevelInfo(13392857.1429, 960000, 1, 1, 1, getBounds()),
        //Tiled2dMapZoomLevelInfo(12500000.0, 896000, 1, 1, 2, getBounds()),        Tiled2dMapZoomLevelInfo(11607142.8571, 832000, 1, 1, 3, getBounds()),
        //Tiled2dMapZoomLevelInfo(10714285.7143, 768000, 1, 1, 4, getBounds()),     Tiled2dMapZoomLevelInfo(9821428.57143, 704000, 1, 1, 5, getBounds()),
        //Tiled2dMapZoomLevelInfo(8928571.42857, 640000, 1, 1, 6, getBounds()),     Tiled2dMapZoomLevelInfo(8035714.28571, 576000, 1, 1, 7, getBounds()),
        //Tiled2dMapZoomLevelInfo(7142857.14286, 512000, 1, 1, 8, getBounds()),     Tiled2dMapZoomLevelInfo(6250000.0, 448000, 2, 1, 9, getBounds()),
        //Tiled2dMapZoomLevelInfo(5357142.85714, 384000, 2, 1, 10, getBounds()),    Tiled2dMapZoomLevelInfo(4464285.71429, 320000, 2, 1, 11, getBounds()),
        Tiled2dMapZoomLevelInfo(3571428.57143, 256000, 2, 2, 12, getBounds()),    Tiled2dMapZoomLevelInfo(2678571.42857, 192000, 3, 2, 13, getBounds()),
        Tiled2dMapZoomLevelInfo(2321428.57143, 166400, 3, 2, 14, getBounds()),    Tiled2dMapZoomLevelInfo(1785714.28571, 128000, 4, 3, 15, getBounds()),
        Tiled2dMapZoomLevelInfo(892857.142857, 64000, 8, 5, 16, getBounds()),     Tiled2dMapZoomLevelInfo(357142.857143, 25600, 19, 13, 17, getBounds()),
        Tiled2dMapZoomLevelInfo(178571.428571, 12800, 38, 25, 18, getBounds()),   Tiled2dMapZoomLevelInfo(71428.5714286, 5120, 94, 63, 19, getBounds()),
        Tiled2dMapZoomLevelInfo(35714.2857143, 2560, 188, 125, 20, getBounds()),  Tiled2dMapZoomLevelInfo(17857.1428571, 1280, 375, 250, 21, getBounds()),
        Tiled2dMapZoomLevelInfo(8928.57142857, 640, 750, 500, 22, getBounds()),   Tiled2dMapZoomLevelInfo(7142.85714286, 512, 938, 625, 23, getBounds()),
        Tiled2dMapZoomLevelInfo(5357.14285714, 384, 1250, 834, 24, getBounds()),  Tiled2dMapZoomLevelInfo(3571.42857143, 256, 1875, 1250, 25, getBounds()),
        Tiled2dMapZoomLevelInfo(1785.71428571, 128, 3750, 2500, 26, getBounds()), Tiled2dMapZoomLevelInfo(892.857142857, 64, 7500, 5000, 27, getBounds()),
        Tiled2dMapZoomLevelInfo(357.142857143, 32, 15000, 10000, 28, getBounds())};
}

RectCoord SwisstopoTiledLayerConfigHelper::getBounds() {
    return RectCoord(Coord(CoordinateSystemIdentifiers::EPSG2056(), 2420000, 1350000, 0),
                     Coord(CoordinateSystemIdentifiers::EPSG2056(), 2900000, 1030000, 0));
}
