#ifndef INC_ENTITY_ENTITY_H
#define INC_ENTITY_ENTITY_H

#include <vector>

namespace entity {

struct Entity {
    unsigned int id;
    std::vector<unsigned int> components;
};

};

#endif
