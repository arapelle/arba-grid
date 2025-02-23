cmake_minimum_required(VERSION 3.26)

# EXTERNAL DEPENDENCIES

add_subdirectory(external)

# CMAKE INCLUDES

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/cmake/)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "arba" BASE_NAME "grid")
string(TIMESTAMP configure_datetime "%Y%m%d-%H%M%S")
set_project_semantic_version("0.5.0" BUILD_METADATA "${configure_datetime}")

project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION "A C++ library providing tools to manipulate 2D grid objects."
        HOMEPAGE_URL "https://github.com/arapelle/arba-math"
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_SEMANTIC_VERSION} ${CMAKE_BUILD_TYPE}")

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/arba/grid/concept/grid.hpp
    include/arba/grid/concept/grid_position.hpp
    include/arba/grid/grid_base.hpp
    include/arba/grid/grid.hpp
    include/arba/grid/grid_types.hpp
)

## Add C++ library:
add_cpp_library(${PROJECT_NAME} HEADER_ONLY
  HEADERS ${headers} ${configured_headers}
  HEADERS_BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
  CXX_STANDARD 20
  DEFAULT_WARNING_OPTIONS
)
add_library("${PROJECT_NAMESPACE}::${PROJECT_BASE_NAME}${LIBRARY_TYPE_POSTFIX}" ALIAS ${PROJECT_NAME})

## Link C++ targets:
find_package(arba-math 0.6.0 REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME}
    INTERFACE
        arba::math
)

## Add tests:
add_test_subdirectory_if_build(test)

## Add examples:
add_example_subdirectory_if_build(example)

# C++ INSTALL

## Install C++ library:
install_cpp_libraries(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets)

## Install project package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE cmake/config/package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})
