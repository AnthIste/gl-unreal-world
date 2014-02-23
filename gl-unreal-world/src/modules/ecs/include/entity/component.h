#ifndef INC_ENTITY_COMPONENT_H
#define INC_ENTITY_COMPONENT_H

namespace ecsentity {

typedef unsigned int component_t;

struct Component {
    unsigned int id;
    component_t type;

    virtual ~Component() {}
};

};

#endif
