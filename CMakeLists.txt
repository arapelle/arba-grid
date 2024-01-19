cmake_minimum_required(VERSION 3.26)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/cmake/)

# CMAKE INCLUDES

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# C++ PROJECT

set_project_name(NAMESPACE "arba" BASE_NAME "grid")
string(TIMESTAMP configure_datetime "%Y%m%d-%H%M%S" UTC)
set_project_semantic_version("0.4.0"
    BUILD_METADATA "${configure_datetime}"
)
project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION "Simple C++ tools to manipulate 2D grid objects."
        HOMEPAGE_URL "https://github.com/arapelle/arba-grid"
        LANGUAGES CXX)
message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/arba/grid/concepts/grid.hpp
    include/arba/grid/concepts/grid_position.hpp
    include/arba/grid/grid.hpp
    include/arba/grid/grid_base.hpp
    include/arba/grid/grid_types.hpp
)

## Add C++ library:
add_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${configured_headers}
    CXX_STANDARD 20
)

## Link C++ targets:
if(NOT TARGET arba-math)
    find_package(arba-math 0.5.0 REQUIRED CONFIG)
endif()
target_link_libraries(${PROJECT_NAME}
    INTERFACE
        arba-math
)

## Install C++ library:
install_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
)

## Install project package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE cmake/config/package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME} FILENAME uninstall.cmake)

## Add tests:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF BUILD_arba-arba_TESTS)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()

## Add examples:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not" OFF BUILD_arba-arba_EXAMPLES)
if(BUILD_${PROJECT_NAME}_EXAMPLES AND BUILD_TESTING)
    add_subdirectory(example)
endif()
