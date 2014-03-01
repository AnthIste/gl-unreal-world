#ifndef INC_UWLEC_MOVEABLE_H
#define INC_UWLEC_MOVEABLE_H

#include "uwlec_component.h"

namespace uwlec {

/// <summary>
/// Processed by GameLogicSystem
/// </summary>
struct Moveable : public uwlec::Component {
    // TODO: vec3
    double x;
    double y;
    double z;

    // TODO: vec3
    double dx;
    double dy;
    double dz;
};

};

#endif
