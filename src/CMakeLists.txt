include_directories(${GLUT_INCLUDE_DIR})
add_executable(test test.cpp)
target_link_libraries(test ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
