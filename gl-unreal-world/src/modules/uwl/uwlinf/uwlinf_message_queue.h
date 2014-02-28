#ifndef INC_UWLINF_MESSAGE_QUEUE_H
#define INC_UWLINF_MESSAGE_QUEUE_H

#include "uwlinf_message_queue_base.h"

#include <memory>
#include <iostream>

namespace uwlinf {

struct Message {
    Message() { }

    virtual ~Message() { }

    template<typename T>
    bool is()
    {
        return typeid(*this) == typeid(T);
    }
};

typedef MessageQueueBase<Message> MessageQueue;

};

#endif
