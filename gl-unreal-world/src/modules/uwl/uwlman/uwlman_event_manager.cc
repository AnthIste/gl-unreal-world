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

        if (receivers.empty()) {
            LOG4CXX_WARN(Logger::getRootLogger(), "uwlman::EventManager - "
                << "No receivers registered for message"
                << typeid(*message).name());

            return;
        }

        LOG4CXX_DEBUG(Logger::getRootLogger(), "uwlman::EventManager - "
            << "Dispatching message to " << receivers.size() << " receivers: "
            << typeid(*message).name());

        std::shared_ptr<uwlinf::Message> messageToDispatch(message.release());

        for (auto receiver : receivers) {
            receiver->receiveMessage(messageToDispatch);
        }
    }
}

};
