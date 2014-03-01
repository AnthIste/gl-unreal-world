#ifndef INC_UWLEC_RENDERABLE_H
#define INC_UWLEC_RENDERABLE_H

#include "uwlec_component.h"

namespace uwlec {

enum ModelType {
    MOD_TRIANGLE,
    MOD_SQUARE,
};

/// <summary>
/// Processed by GfxSystem
/// </summary>
struct Renderable : public uwlec::Component {
    ModelType type;
    unsigned int color;
    double scale;

    // TODO: vec3
    double x;
    double y;
    double z;
};

};

#endif

