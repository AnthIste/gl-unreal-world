#ifndef INC_ENTITY_ENTITY_MANAGER_H
#define INC_ENTITY_ENTITY_MANAGER_H

#include "entity/entity_subscriber.h"

#include <memory>
#include <vector>

namespace entity {

class EntityManager {
public:
    EntityManager();
    virtual ~EntityManager();

    void subscribeEntityChanges(std::shared_ptr<EntitySubscriber> subscriber);

    void subscribeComponentChanges(std::shared_ptr<EntitySubscriber> subscriber, std::vector<unsigned int> componentTypes);
};

};

#endif
