cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)
find_package(Eigen REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(src)
