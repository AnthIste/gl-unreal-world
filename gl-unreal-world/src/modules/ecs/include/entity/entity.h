#ifndef INC_ENTITY_ENTITY_H
#define INC_ENTITY_ENTITY_H

#include <set>

namespace ecsentity {

struct Entity {
    unsigned int id;
    std::set<unsigned int> components;
};

};

#endif
