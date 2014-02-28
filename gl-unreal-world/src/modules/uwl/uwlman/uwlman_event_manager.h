#ifndef INC_UWLMAN_EVENT_MANAGER_H
#define INC_UWLMAN_EVENT_MANAGER_H

#include "uwlinf/uwlinf_message_queue.h"
#include "uwlman/uwlman_message_receiver.h"

#include <memory>
#include <map>
#include <set>

namespace uwlman {

class EventManager {
public:
    EventManager(std::shared_ptr<uwlinf::MessageQueue> messageQueue)
        : _messageQueue(messageQueue)
    { }

    virtual ~EventManager() { }

    virtual void dispatchMessages();

    template <typename TMessage>
    void registerReceiver(std::shared_ptr<uwlman::MessageReceiver> receiver);

private:
    typedef std::set<std::shared_ptr<uwlman::MessageReceiver>> ReceiverSet;

    std::shared_ptr<uwlinf::MessageQueue> _messageQueue;

    std::map<size_t, ReceiverSet> _messageMap;

};

};

#include "uwlman_event_manager.tcc"

#endif
