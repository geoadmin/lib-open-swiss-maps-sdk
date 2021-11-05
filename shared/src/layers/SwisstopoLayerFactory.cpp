/*
 * Copyright (c) 2021 Ubique Innovation AG <https://www.ubique.ch>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 *  SPDX-License-Identifier: MPL-2.0
 */

#include "SwisstopoLayerFactory.h"
#include "SwisstopoTiledLayerConfigFactory.h"
#include "Tiled2dMapRasterLayerInterface.h"

std::shared_ptr<::Tiled2dMapRasterLayerInterface>
SwisstopoLayerFactory::createSwisstopoTiledRasterLayer(::SwisstopoLayerType layerType,
                                                       const std::shared_ptr<::LoaderInterface> &loader) {
    return Tiled2dMapRasterLayerInterface::create(SwisstopoTiledLayerConfigFactory::createRasterTileLayerConfig(layerType),
                                                  loader);
}


std::shared_ptr<::Tiled2dMapRasterLayerInterface> SwisstopoLayerFactory::createSwisstopoTiledRasterLayerFromMetadata(const ::WmtsLayerDescription & configuration,
                                                                                                                            int32_t maxZoom,
                                                                                                                            const ::Tiled2dMapZoomInfo & zoomInfo,
                                                                                                                            const std::shared_ptr<::LoaderInterface> & loader) {
    return Tiled2dMapRasterLayerInterface::create(SwisstopoTiledLayerConfigFactory::createRasterTiledLayerConfigFromMetadata(configuration, maxZoom, zoomInfo),
                                                  loader);
}
