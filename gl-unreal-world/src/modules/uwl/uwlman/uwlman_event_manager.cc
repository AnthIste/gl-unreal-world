#include "uwlman_event_manager.h"

#include <iostream>

namespace uwlman {

void EventManager::dispatchMessages()
{
    while (_messageQueue->hasMessage()) {
        auto message = _messageQueue->popMessage();
        auto type_code = typeid(message).hash_code();

        // TODO: read configuration to determine targets
        std::cout << "Dispatching message" << std::endl;
    }
}

};
