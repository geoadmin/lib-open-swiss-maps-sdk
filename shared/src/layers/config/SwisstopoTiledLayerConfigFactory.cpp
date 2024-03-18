/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

#include "SwisstopoTiledLayerConfigFactory.h"
#include "CoordinateSystemIdentifiers.h"
#include "SwisstopoLayerType.h"
#include "SwisstopoTiledLayerConfigHelper.h"
#include "WmtsLayerDescription.h"
#include "WmtsTiled2dMapLayerConfigFactory.h"
#include <cmath>


std::shared_ptr<::Tiled2dMapLayerConfig>
SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfig(SwisstopoLayerType layerType) {
    return createRasterTileLayerConfigWithBaseUrl(layerType, std::nullopt, std::nullopt);
}

std::shared_ptr<::Tiled2dMapLayerConfig>
SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfigWithZoomInfo(SwisstopoLayerType layerType,
                                                                          const std::optional<Tiled2dMapZoomInfo> &zoomInfo) {
    return createRasterTileLayerConfigWithBaseUrl(layerType, zoomInfo, std::nullopt);
}


std::shared_ptr<::Tiled2dMapLayerConfig>
SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfigWithBaseUrl(SwisstopoLayerType layerType,
                                                                         const std::optional<::Tiled2dMapZoomInfo> &zoomInfo,
                                                                         const std::optional<std::string> &baseUrl) {
    std::string identifier;
    std::string time = "current";
    std::string extension = "png";
    int maxZoom = 27;
    int numDrawPreviousLayers = 0;

    switch (layerType) {
    case SwisstopoLayerType::PIXELKARTE_FARBE:
        identifier = "ch.swisstopo.pixelkarte-farbe";
        extension = "jpeg";
        maxZoom = 27;
        numDrawPreviousLayers = 2;
        break;
    case SwisstopoLayerType::PIXELKARTE_FARK_PK1000:
        identifier = "ch.swisstopo.pixelkarte-farbe-pk1000.noscale";
        extension = "jpeg";
        maxZoom = 26;
        numDrawPreviousLayers = 2;
        break;
    case SwisstopoLayerType::PIXELKARTE_GRAUSTUFEN:
        identifier = "ch.swisstopo.pixelkarte-grau";
        extension = "jpeg";
        maxZoom = 27;
        numDrawPreviousLayers = 2;
        break;
    case SwisstopoLayerType::PIXELKARTE_FARBE_WINTER:
        identifier = "ch.swisstopo.pixelkarte-farbe-winter";
        extension = "jpeg";
        maxZoom = 27;
        numDrawPreviousLayers = 2;
        break;
    case SwisstopoLayerType::SWISSIMAGE:
        identifier = "ch.swisstopo.swissimage";
        extension = "jpeg";
        maxZoom = 28;
        numDrawPreviousLayers = 2;
        break;
    case SwisstopoLayerType::SWISSIMAGE_1946:
        identifier = "ch.swisstopo.swissimage-product_1946";
        time = "1946";
        extension = "jpeg";
        maxZoom = 25;
        numDrawPreviousLayers = 2;
        break;
    case SwisstopoLayerType::LUFTFAHRTKARTEN_ICAO:
        identifier = "ch.bazl.luftfahrtkarten-icao";
        maxZoom = 19;
        break;
    case SwisstopoLayerType::SEGELFLUGKARTE:
        identifier = "ch.bazl.segelflugkarte";
        maxZoom = 19;
        break;
    case SwisstopoLayerType::MIL_AIRSPACE_CHART:
        identifier = "ch.vbs.milairspacechart";
        maxZoom = 19;
        break;
    case SwisstopoLayerType::SPERR_GEFAHRENZONENKARTE:
        identifier = "ch.vbs.sperr-gefahrenzonenkarte";
        maxZoom = 19;
        break;
    case SwisstopoLayerType::SWISSMILPILOTSCHART:
        identifier = "ch.vbs.swissmilpilotschart";
        maxZoom = 19;
        break;
    case SwisstopoLayerType::HIKS_DUFOR:
        identifier = "ch.swisstopo.hiks-dufour";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::HIKS_SIEGFRIED:
        identifier = "ch.swisstopo.hiks-siegfried";
        maxZoom = 25;
        break;
    case SwisstopoLayerType::SWISSTLM3D_EISENBAHNNETZ:
        identifier = "ch.swisstopo.swisstlm3d-eisenbahnnetz";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SWISSTLM3D_STRASSEN:
        identifier = "ch.swisstopo.swisstlm3d-strassen";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SWISSTLM3D_UEBRIGVERKEHR:
        identifier = "ch.swisstopo.swisstlm3d-uebrigerverkehr";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SWISSTLM3D_WANDERWEGE:
        identifier = "ch.swisstopo.swisstlm3d-wanderwege";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SCHWEIZMOBIL_WANDERLAND:
        identifier = "ch.astra.wanderland";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SCHWEIZMOBIL_VELOLAND:
        identifier = "ch.astra.veloland";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SCHWEIZMOBIL_MOUNTAINBIKELAND:
        identifier = "ch.astra.mountainbikeland";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::HANGNEIGUNG_30:
        identifier = "ch.swisstopo-karto.hangneigung";
        maxZoom = 25;
        break;
    case SwisstopoLayerType::HANGNEIGUNGSKLASSEN_30:
        identifier = "ch.swisstopo.hangneigung-ueber_30";
        maxZoom = 25;
        break;
    case SwisstopoLayerType::WILDSCHUTZ_GEBIETE:
        identifier = "ch.bafu.wrz-jagdbanngebiete_select";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::WILDRUHEZONEN:
        identifier = "ch.bafu.wrz-wildruhezonen_portal";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SCHNEESCHUH_ROUTEN:
        identifier = "ch.swisstopo-karto.schneeschuhrouten";
        maxZoom = 25;
        break;
    case SwisstopoLayerType::SKI_TOUR_ROUTEN:
        identifier = "ch.swisstopo-karto.skitouren";
        maxZoom = 25;
        break;
    case SwisstopoLayerType::DROHNEN:
        identifier = "ch.bazl.einschraenkungen-drohnen";
        maxZoom = 26;
        break;
    case SwisstopoLayerType::SCHUTZGEBIETE_LUFTFAHRT:
        identifier = "ch.bafu.schutzgebiete-luftfahrt";
        maxZoom = 25;
        break;
    case SwisstopoLayerType::EISZEIT:
        identifier = "ch.swisstopo.geologie-eiszeit-lgm-raster";
        maxZoom = 20;
        break;
    }


    std::string url = baseUrl.has_value() ? *baseUrl : "https://wmts.geo.admin.ch/1.0.0/";
    auto dimensions = { WmtsLayerDimension("Time", time, {}) };
    auto configuration = WmtsLayerDescription(identifier, "", "", dimensions, SwisstopoTiledLayerConfigHelper::getBounds(), "2056", url + identifier +
                                              "/default/{Time}/2056/{TileMatrix}/{TileCol}/{TileRow}." + extension, "image/"+extension);

    auto finalZoomInfo = zoomInfo.has_value() ? *zoomInfo : Tiled2dMapZoomInfo(0.65, numDrawPreviousLayers, 0, true, false, true, true);

    return createRasterTiledLayerConfigFromMetadata(configuration, maxZoom, finalZoomInfo);
}


std::shared_ptr<::Tiled2dMapLayerConfig> SwisstopoTiledLayerConfigFactory::createRasterTiledLayerConfigFromMetadata(const ::WmtsLayerDescription & description, int32_t maxZoom, const ::Tiled2dMapZoomInfo & zoomInfo) {
    auto zoomLevels = SwisstopoTiledLayerConfigHelper::getZoomLevelInfos();
    auto itMax = find_if(zoomLevels.begin(), zoomLevels.end(), [&maxZoom] (const Tiled2dMapZoomLevelInfo& s) { return s.zoomLevelIdentifier > maxZoom; } );
    std::vector<Tiled2dMapZoomLevelInfo> subvector = {zoomLevels.begin(), itMax };
    zoomLevels = subvector;

    return WmtsTiled2dMapLayerConfigFactory::create(description, zoomLevels, zoomInfo, SwisstopoTiledLayerConfigHelper::getBounds().topLeft.systemIdentifier, "");
}
