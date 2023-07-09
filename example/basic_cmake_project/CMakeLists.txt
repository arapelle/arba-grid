cmake_minimum_required(VERSION 3.18)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package grid:
find_package(grid 0.3.0 CONFIG REQUIRED)
# Use grid release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE grid)
# Use grid release static target:
#target_link_libraries(${PROJECT_NAME} PRIVATE grid-static)

