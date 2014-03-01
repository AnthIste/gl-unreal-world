#include "uwlman_entity_factory.h"
#include "uwlec/uwlec_moveable.h"
#include "uwlec/uwlec_renderable.h"

using uwlec::Entity;
using uwlec::Moveable;
using uwlec::Renderable;

namespace uwlman {

std::shared_ptr<Entity> EntityFactory::createEntity(EntityType type, double x, double y)
{
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

    renderableComponent->color = 0xFFFF0000;
    renderableComponent->scale = 1.0;

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

    renderableComponent->color = 0xFF00FF00;
    renderableComponent->scale = 0.5;

    _entityManager->registerEntity(entity);
    _entityManager->addComponent<Moveable>(entity, moveableComponent);
    _entityManager->addComponent<Renderable>(entity, renderableComponent);

    return entity;
}

};
