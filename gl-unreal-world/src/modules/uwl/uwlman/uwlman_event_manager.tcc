#ifndef INC_UWLMAN_EVENT_MANAGER_TCC
#define INC_UWLMAN_EVENT_MANAGER_TCC

#include "uwlman_event_manager.h"

#include <log4cxx/logger.h>

using namespace log4cxx;

namespace uwlman {

template <typename TMessage>
void EventManager::registerReceiver(std::shared_ptr<uwlman::MessageReceiver> receiver)
{
    auto key = typeid(TMessage).hash_code();
    _messageMap[key].insert(receiver);

    LOG4CXX_DEBUG(Logger::getRootLogger(), "Registering receiver: "
                                           << " (" << typeid(TMessage).name() << ")");
}

};

#endif
