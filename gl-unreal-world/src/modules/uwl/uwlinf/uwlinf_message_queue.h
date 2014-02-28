#ifndef INC_UWLINF_MESSAGE_QUEUE_H
#define INC_UWLINF_MESSAGE_QUEUE_H

#include "uwlinf_message_queue_base.h"

#include <memory>

namespace uwlinf {

struct Message {
    Message() { }

    virtual ~Message() { }

    template<typename T>
    bool is()
    {
        return typeid(this) == typeid(T);
    }
};

class MessageQueue : public MessageQueueBase<Message> {
public:
    MessageQueue();

    virtual ~MessageQueue() { }
};

};

#endif
