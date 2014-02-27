#ifndef INC_UWLMAN_MESSAGE_QUEUE_H
#define INC_UWLMAN_MESSAGE_QUEUE_H

#include "uwlinf/uwlinf_message_queue.h"

namespace uwlman {

struct Message {
    unsigned int type;
    void* data;
};

typedef uwlinf::MessageQueue<Message> MessageQueue;

};

#endif
