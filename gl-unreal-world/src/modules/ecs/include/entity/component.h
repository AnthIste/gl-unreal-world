#ifndef INC_ENTITY_COMPONENT_H
#define INC_ENTITY_COMPONENT_H

namespace ecsentity {

struct Component {
    unsigned int id;
    unsigned int type;

    virtual ~Component() {}
};

};

#endif
