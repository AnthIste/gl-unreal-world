#ifndef INC_ENTITY_ENTITY_H
#define INC_ENTITY_ENTITY_H

#include <vector>

namespace ecsentity {

struct Entity {
    unsigned int id;
    std::vector<unsigned int> components;
};

};

#endif
