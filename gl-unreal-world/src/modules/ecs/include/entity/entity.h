#ifndef INC_ENTITY_ENTITY_H
#define INC_ENTITY_ENTITY_H

#include <map>

namespace ecsentity {

struct Entity {
    unsigned int id;
    std::map<std::size_t, unsigned int> components;
};

};

#endif
