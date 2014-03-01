include_directories ("${PROJECT_SOURCE_DIR}/src/modules/uwl")

# configure GLFW library
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

include_directories (
    ogl
    oglres
    oglwin
)

file(GLOB sources
    ogl/*.cc
    oglres/*.cc
    oglwin/*.cc
)

add_library (ogl ${sources})
target_link_libraries (ogl uwl ${GLFW_LIBRARIES})

install (TARGETS ogl DESTINATION bin)
