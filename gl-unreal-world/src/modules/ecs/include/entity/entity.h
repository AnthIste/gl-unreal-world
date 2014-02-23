#ifndef INC_ENTITY_ENTITY_H
#define INC_ENTITY_ENTITY_H

namespace entity {

#include <vector>

struct Entity {
    unsigned int id;
    std::vector<unsigned int> components;
};

};

#endif
