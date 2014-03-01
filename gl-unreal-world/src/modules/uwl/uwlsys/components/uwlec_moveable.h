#ifndef INC_COMPONENTS_MOVEABLE_H
#define INC_COMPONENTS_MOVEABLE_H

#include "uwlec/uwlec_component.h"

namespace uwlsys {

struct Moveable : public uwlec::Component {
    // Convert to vec3
    double x;
    double y;
    double z;

    // Convert to vec3
    double dx;
    double dy;
    double dz;
};

};

#endif
