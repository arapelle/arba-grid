cmake_minimum_required(VERSION 3.18)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

#-----
# PROJECT

check_cmake_binary_dir()
set_build_type_if_undefined()

#-----
# C++ PROJECT

project(grid
        VERSION 0.1.0
        DESCRIPTION "Simple C++ tools to manipulate 2D grid objects."
        HOMEPAGE_URL "https://github.com/arapelle/grid"
        LANGUAGES CXX)

message(STATUS "BUILD   : ${CMAKE_BUILD_TYPE}")
message(STATUS "CPPCOMP : ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION}")

#-----
include(CTest)

# Project options
library_build_options(${PROJECT_NAME} HEADER_ONLY EXAMPLE TEST)

# Add C++ library
add_cpp_honly_library(${PROJECT_NAME}
    CXX_STANDARD 20
    NAMESPACE arba::
    INCLUDE_DIRECTORIES include
    OUTPUT_VERSION_HEADER "version.hpp"
    )

# Link targets
if(NOT TARGET arba::math)
    find_package(math 0.3 REQUIRED CONFIG)
endif()
cpp_library_targets_link_libraries(${PROJECT_NAME} HEADER_ONLY PUBLIC arba::math)

# Install C++ library
install_cpp_library_targets(${PROJECT_NAME}
                            TARGETS ${PROJECT_NAME}
                            INCLUDE_DIRECTORIES "include/${PROJECT_NAME}"
                            NAMESPACE arba::
                            )

# Install package
install_package(${PROJECT_NAME}
                INPUT_PACKAGE_CONFIG_FILE ${PROJECT_NAME}-config.cmake.in
                EXPORT_NAMES ${PROJECT_NAME})

if(${PROJECT_NAME}_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

if(${PROJECT_NAME}_BUILD_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()

#-----
