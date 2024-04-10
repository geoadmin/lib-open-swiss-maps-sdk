// swift-tools-version:5.5

import PackageDescription

let package = Package(
    name: "SwisstopoMapSDK",
    platforms: [
        .iOS(.v11),
        .macOS(.v12)
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
        .package(url: "https://github.com/openmobilemaps/maps-core.git", from: "2.0.6"),
        .package(url: "https://github.com/openmobilemaps/layer-gps.git", from: "2.0.6")
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
                .copy("resources/wmts/WMTSCapabilities_2056.xml"),
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
                .product(name: "MapCoreSharedModuleCpp", package: "maps-core"),
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
    cxxLanguageStandard: .cxx17
)
