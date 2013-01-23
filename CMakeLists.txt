cmake_minimum_required(VERSION 2.8)

find_package(GLUT)
find_package(OpenGL)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(src)
