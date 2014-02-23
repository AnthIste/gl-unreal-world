#ifndef INC_COMPONENTS_MOVEABLE_H
#define INC_COMPONENTS_MOVEABLE_H

#include "entity/component.h"

namespace components {

using entity::Component;

struct Moveable : public Component {
    double x;
    double y;
    double z;
};

};

#endif
