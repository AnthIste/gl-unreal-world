#ifndef INC_ENTITY_ENTITY_SUBSCRIBER_H
#define INC_ENTITY_ENTITY_SUBSCRIBER_H

#include "entity/entity.h"

#include <vector>

namespace ecsentity {

class EntitySubscriber {
public:
    virtual ~EntitySubscriber() { }
    virtual void entitiesAdded(std::vector<ecsentity::Entity> entities) = 0;
};

};

#endif
