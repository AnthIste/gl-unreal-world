#ifndef INC_UWLEC_RENDERABLE_H
#define INC_UWLEC_RENDERABLE_H

#include "uwlec_component.h"
#include "ogl/ogl_primitives.h"

#include <memory>

namespace uwlec {

/// <summary>
/// Processed by GfxSystem
/// </summary>
struct Renderable : public uwlec::Component {
    // Can switch to UID
    std::shared_ptr<ogl::Mesh1P> mesh;
};

};

#endif

