#ifndef INC_UWLMAN_MESSAGE_QUEUE_H
#define INC_UWLMAN_MESSAGE_QUEUE_H

#include "uwlinf/uwlinf_message_queue.h"

#include <memory>

namespace uwlman {

struct Message {
    Message() { }

    virtual ~Message() { }

    template<typename T>
    bool is() { return typeid(this) == typeid(T); }
};

class MessageQueue : public uwlinf::MessageQueue<Message> {
public:
    MessageQueue();

    virtual ~MessageQueue() { }
};

};

#endif
