#ifndef INC_UWLMAN_MESSAGE_RECEIVER_H
#define INC_UWLMAN_MESSAGE_RECEIVER_H

#include "uwlinf/uwlinf_message_queue.h"

#include <memory>

namespace uwlman {

class MessageReceiver : public std::enable_shared_from_this<MessageReceiver> {
public:
    virtual ~MessageReceiver() { }

    virtual void receiveMessage(std::shared_ptr<uwlinf::Message> message) = 0;
};

};

#endif
