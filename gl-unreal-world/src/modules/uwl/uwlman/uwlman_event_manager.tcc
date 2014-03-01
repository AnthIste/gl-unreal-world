#ifndef INC_UWLMAN_EVENT_MANAGER_TCC
#define INC_UWLMAN_EVENT_MANAGER_TCC

#include "uwlman_event_manager.h"

#include <iostream>

namespace uwlman {

template <typename TMessage>
void EventManager::registerReceiver(std::shared_ptr<uwlman::MessageReceiver> receiver)
{
    auto key = typeid(TMessage).hash_code();
    _messageMap[key].insert(receiver);

    std::cout << "Registering receiver: "
              << key
              << std::endl;
}

};

#endif
