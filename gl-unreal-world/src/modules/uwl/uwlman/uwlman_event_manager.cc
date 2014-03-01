#include "uwlman_event_manager.h"

#include <log4cxx/logger.h>

using namespace log4cxx;

namespace uwlman {

void EventManager::dispatchMessages()
{
    while (_messageQueue->hasMessage()) {
        auto message = _messageQueue->popMessage();
        auto key = typeid(*message).hash_code();

        auto receivers = _messageMap[key];

        LOG4CXX_DEBUG(Logger::getRootLogger(), "Dispatching message: "
                                               << " (" << typeid(*message).name() << ")");

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
