#ifndef INC_OGL_PRIMITIVES_H
#define INC_OGL_PRIMITIVES_H

#include "ogl_vertex_formats.h"

#include <vector>

namespace ogl {

struct Mesh1P {
    std::vector<Vertex1P> vertices;
};

struct Mesh1P1C {
    std::vector<Vertex1P1C> vertices;
};

struct Mesh1P_indexed {
    std::vector<Vertex1P> vertices;
    std::vector<int> indices;
};

struct Mesh1P1C_indexed {
    std::vector<Vertex1P1C> vertices;
    std::vector<int> indices;
};

}; /* namespace ogl */

#endif
