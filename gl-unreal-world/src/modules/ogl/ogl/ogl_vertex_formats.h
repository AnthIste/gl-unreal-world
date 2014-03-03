#ifndef INC_OGL_VERTEX_FORMATS_H
#define INC_OGL_VERTEX_FORMATS_H

namespace ogl {

struct Vertex1P {
    double x;
    double y;
    double z;
};

struct Vertex1P1C {
    double x;
    double y;
    double z;

    double r;
    double g;
    double b;
};

}; /* namespace ogl */

#endif
