include_directories(
    ${GLUT_INCLUDE_DIR}/GL 
    ${EIGEN_INCLUDE_DIR}
)

add_executable(mesh_viewer mesh_viewer.cpp)
target_link_libraries(mesh_viewer ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
