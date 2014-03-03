#include "uwlman_entity_factory.h"
#include "uwlec/uwlec_moveable.h"
#include "uwlec/uwlec_renderable.h"

using uwlec::Entity;
using uwlec::Moveable;
using uwlec::Renderable;

namespace uwlman {

std::shared_ptr<Entity> EntityFactory::createEntity(EntityType type, double x, double y)
{
    if (_guzzlerMesh == nullptr || _wooterMesh == nullptr) {
        initializeMeshData();
    }

    switch (type) {
        case EntityType::Guzzler:
            return createGuzzler(x, y);

        case EntityType::Wooter:
            return createWooter(x, y);

        default:
            return nullptr;
    }
}

std::shared_ptr<Entity> EntityFactory::createGuzzler(double x, double y)
{
    auto entity = std::make_shared<Entity>();
    auto moveableComponent = std::make_shared<Moveable>();
    auto renderableComponent = std::make_shared<Renderable>();

    moveableComponent->x = x;
    moveableComponent->y = y;
    moveableComponent->z = 0.0;

    moveableComponent->dx = 0.0;
    moveableComponent->dy = 0.0;
    moveableComponent->dz = 0.0;

    renderableComponent->mesh = _guzzlerMesh;

    _entityManager->registerEntity(entity);
    _entityManager->addComponent<Moveable>(entity, moveableComponent);
    _entityManager->addComponent<Renderable>(entity, renderableComponent);

    return entity;
}

std::shared_ptr<Entity> EntityFactory::createWooter(double x, double y)
{
    auto entity = std::make_shared<Entity>();
    auto moveableComponent = std::make_shared<Moveable>();
    auto renderableComponent = std::make_shared<Renderable>();

    moveableComponent->x = x;
    moveableComponent->y = y;
    moveableComponent->z = 0.0;

    moveableComponent->dx = 0.0;
    moveableComponent->dy = 0.0;
    moveableComponent->dz = 0.0;

    renderableComponent->mesh = _wooterMesh;

    _entityManager->registerEntity(entity);
    _entityManager->addComponent<Moveable>(entity, moveableComponent);
    _entityManager->addComponent<Renderable>(entity, renderableComponent);

    return entity;
}

void EntityFactory::initializeMeshData()
{
    _guzzlerMesh = createMesh(EntityType::Guzzler);
    _wooterMesh = createMesh(EntityType::Wooter);
}

std::shared_ptr<ogl::Mesh1P> EntityFactory::createMesh(EntityType type)
{
    const float vertexData[] = {
        0.0f,    0.1f, 0.0f, 1.0f,   // (Vec4)
        0.1f, -0.0732f, 0.0f, 1.0f,  // (Vec4)
        -0.1f, -0.0732f, 0.0f, 1.0f, // (Vec4)
    };

    auto mesh = std::make_shared<ogl::Mesh1P>();
    auto nVertices = sizeof(vertexData) / sizeof(float) / 4;

    for (auto i = 0; i < nVertices; i++) {
        ogl::Vertex1P vert;
        const float* vec4 = &vertexData[i * 4];

        vert.x = vec4[0];
        vert.y = vec4[1];
        vert.z = vec4[2];

        mesh->vertices.push_back(vert);
    }

    return mesh;
}

};
