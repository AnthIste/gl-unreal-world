#ifndef INC_COMPONENTS_MOVEABLE_H
#define INC_COMPONENTS_MOVEABLE_H

#include "entity/component.h"

namespace ecscomponents {

struct Moveable : public ecsentity::Component {
    double x;
    double y;
    double z;
};

};

#endif
