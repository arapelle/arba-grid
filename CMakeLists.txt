cmake_minimum_required(VERSION 3.26)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/cmake/)

# CMAKE INCLUDES

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# C++ PROJECT

set(PROJECT_NAME "arba-grid")
set(project_namespace "arba")
set(project_base_name "grid")
set(PROJECT_VERSION 0.3.0)
project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION "Simple C++ tools to manipulate 2D grid objects."
        HOMEPAGE_URL "https://github.com/arapelle/grid"
        LANGUAGES CXX)
message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
generate_version_macro_header(generated_version_header
                              ${project_namespace}_${project_base_name}
                              ${project_namespace}/${project_base_name}/version.hpp)

## Headers:
set(headers
    include/arba/grid/grid.hpp
    include/arba/grid/grid_base.hpp
    include/arba/grid/grid_types.hpp
)

## Add C++ library:
add_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${generated_version_header}
    CXX_STANDARD 20
)

## Link C++ targets:
if(NOT TARGET arba-math)
    find_package(arba-math 0.4.0 REQUIRED CONFIG)
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
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})

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
