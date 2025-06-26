// swift-tools-version:6.1

import PackageDescription

let package = Package(
    name: "SwisstopoMapSDK",
    platforms: [
        .iOS(.v14)
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
        .package(url: "https://github.com/openmobilemaps/maps-core", from: "3.3.0"),
        .package(url: "https://github.com/openmobilemaps/layer-gps.git", from: "3.3.0")
    ],
    targets: [
        .target(
            name: "SwisstopoMapSDK",
            dependencies: [
                .product(name: "LayerGps", package: "layer-gps"),
                .product(name: "MapCore", package: "maps-core"),
                "SwisstopoMapSDKSharedModule",
            ],
            path: "ios",
            exclude: ["README.md", "docs/install_readme.md"],
            resources: [
                .process("resources/wmts/WMTSCapabilities_2056.xml")
            ]
        ),
        .target(
            name: "SwisstopoMapSDKSharedModule",
            dependencies: [
                "SwisstopoMapSDKSharedModuleCpp",
                .product(name: "MapCoreSharedModule", package: "maps-core"),
            ],
            path: "bridging/ios",
            publicHeadersPath: ""
        ),
        .target(
            name: "SwisstopoMapSDKSharedModuleCpp",
            dependencies: [
                .product(name: "MapCoreSharedModuleCpp", package: "maps-core")
            ],
            path: "shared",
            sources: ["src", "public"],
            publicHeadersPath: "public",
            cxxSettings: [
                .headerSearchPath("public"),
                .headerSearchPath("src/layers/config"),
                .headerSearchPath("src/layers"),
                .headerSearchPath("src"),
            ]
        ),
    ],
    cxxLanguageStandard: .cxx17
)
