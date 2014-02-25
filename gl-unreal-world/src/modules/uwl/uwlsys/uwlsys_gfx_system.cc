#include "uwlsys_gfx_system.h"

#include <iostream>

namespace uwlsys {

GfxSystem::~GfxSystem()
{
}

void GfxSystem::initialize()
{
    _renderer->initialize();
    _renderer->set_cull_render_mode();

    _vbo = _renderer->create_vbo();
}

void GfxSystem::finalize()
{
    _renderer->finalize();
}

void GfxSystem::tick(long t)
{
    _renderer->clear_frame();
    _renderer->render_colored_triangle(_vbo, 0.0f, 0.0f);
}

void GfxSystem::render_scene()
{
}

};
