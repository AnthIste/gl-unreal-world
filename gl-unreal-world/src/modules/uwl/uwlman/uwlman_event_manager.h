#ifndef INC_UWLMAN_EVENT_MANAGER_H
#define INC_UWLMAN_EVENT_MANAGER_H

#include "uwlinf/uwlinf_message_queue.h"

#include <memory>

namespace uwlman {

class EventManager {
public:
    EventManager(std::shared_ptr<uwlinf::MessageQueue> messageQueue)
        : _messageQueue(messageQueue)
    { }

    virtual ~EventManager() { }

    virtual void dispatchMessages();

private:
    std::shared_ptr<uwlinf::MessageQueue> _messageQueue;

};

};

#endif
