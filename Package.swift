// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "SwisstopoMapSDK",
    platforms: [
        .iOS(.v11),
    ],
    products: [
        .library(
            name: "SwisstopoMapSDK",
            targets: ["SwisstopoMapSDK"]
        ),
        .library(
            name: "SwisstopoMapSDKSharedModule",
            targets: ["SwisstopoMapSDKSharedModule"]
        ),
        .library(
            name: "SwisstopoMapSDKSharedModuleCpp",
            targets: ["SwisstopoMapSDKSharedModuleCpp"]
        ),
    ],
    dependencies: [
        .package(name: "MapCore",
                 url: "https://github.com/openmobilemaps/maps-core.git",
                 .branch("develop")),
        .package(name: "LayerGps",
                 url: "https://github.com/openmobilemaps/layer-gps.git",
                 .branch("develop")),
    ],
    targets: [
        .target(
            name: "SwisstopoMapSDK",
            dependencies: [
                .product(name: "LayerGps", package: "LayerGps"),
                .product(name: "MapCore", package: "MapCore"),
                "SwisstopoMapSDKSharedModule",
            ],
            path: "ios",
            exclude: ["README.md", "docs/install_readme.md"],
            resources: [
                .copy("resources/wmts/WMTSCapabilities_2056.xml"),
            ]
        ),
        .target(
            name: "SwisstopoMapSDKSharedModule",
            dependencies: [
                "SwisstopoMapSDKSharedModuleCpp",
                .product(name: "MapCoreSharedModule", package: "MapCore"),
            ],
            path: "bridging/ios",
            publicHeadersPath: ""
        ),
        .target(
            name: "SwisstopoMapSDKSharedModuleCpp",
            dependencies: [
                .product(name: "MapCoreSharedModuleCpp", package: "MapCore"),
            ],
            path: "shared",
            sources: ["src"],
            publicHeadersPath: "public",
            cxxSettings: [
                .headerSearchPath("**"),
                .headerSearchPath("public"),
                .headerSearchPath("src/config/layers"),
                .headerSearchPath("src/config"),
                .headerSearchPath("src"),
            ]
        ),
    ],
    cxxLanguageStandard: .cxx1z
)
