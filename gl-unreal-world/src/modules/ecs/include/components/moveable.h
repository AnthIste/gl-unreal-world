#ifndef INC_COMPONENTS_MOVEABLE_H
#define INC_COMPONENTS_MOVEABLE_H

namespace components {

#include "entity/component.h"

using entity::Component;

struct Moveable : public Component {
    double x;
    double y;
    double z;
};

};

#endif
