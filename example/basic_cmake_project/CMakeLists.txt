cmake_minimum_required(VERSION 3.26)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package arba-grid:
find_package(arba-grid 0.4.0 CONFIG REQUIRED)
# Use arba-grid release header-only target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba-grid)
