#ifndef INC_COMPONENTS_MOVEABLE_H
#define INC_COMPONENTS_MOVEABLE_H

#include "uwlec_component.h"

namespace uwlec {

struct Moveable : public uwlec::Component {
    double x;
    double y;
    double z;
};

};

#endif
