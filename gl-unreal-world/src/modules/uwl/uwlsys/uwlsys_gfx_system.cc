#include "uwlsys_gfx_system.h"
#include "uwlec/uwlec_moveable.h"

using uwlec::Entity;
using uwlec::Moveable;
using uwlman::EntityManager;

namespace uwlsys {

GfxSystem::~GfxSystem()
{
}

void GfxSystem::initialize()
{
    _renderer->initialize();
    _renderer->set_cull_render_mode();

    _basicShader = _assetManager->loadShaderProgram("basic");
    _vbo = _renderer->create_vbo();
}

void GfxSystem::finalize()
{
    _renderer->finalize();
}

void GfxSystem::tick(double t, double dt)
{
    _renderer->clear_frame();

    EntityManager::EntitySet allEntities = _entityManager->allEntities();

    for (auto entity : allEntities) {
        auto m = _entityManager->getComponent<Moveable>(entity);

        if (m != nullptr) {
            _renderer->set_shader_program(_basicShader);
            _renderer->set_uniform_2f(_basicShader, "offset", m->x, m->y);
            _renderer->render_colored_triangle(_vbo, 0.0f, 0.0f);
        }
    }
}

void GfxSystem::render_scene()
{
}

};
