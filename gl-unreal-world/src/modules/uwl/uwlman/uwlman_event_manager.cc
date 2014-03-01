#include "uwlman_event_manager.h"

#include <iostream>

namespace uwlman {

void EventManager::dispatchMessages()
{
    while (_messageQueue->hasMessage()) {
        auto message = _messageQueue->popMessage();
        auto key = typeid(*message).hash_code();

        auto receivers = _messageMap[key];

        std::cout << "Dispatching message: "
                  << key
                  << std::endl;

        if (receivers.empty()) {
            return;
        }

        std::shared_ptr<uwlinf::Message> messageToDispatch(message.release());

        for (auto receiver : receivers) {
            receiver->receiveMessage(messageToDispatch);
        }
    }
}

};
