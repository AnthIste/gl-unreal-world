#ifndef INC_UWLINF_MESSAGE_QUEUE_BASE_H
#define INC_UWLINF_MESSAGE_QUEUE_BASE_H

#include <memory>
#include <queue>

namespace uwlinf {

template <typename TMessage>
class MessageQueueBase {
public:
    MessageQueueBase();

    virtual ~MessageQueueBase() { }

    virtual void postMessage(std::unique_ptr<TMessage> message);

    virtual std::unique_ptr<TMessage> popMessage();

    virtual bool hasMessage();

private:
    std::queue<std::unique_ptr<TMessage>> _queue;

};

};

#include "uwlinf_message_queue_base.tcc"

#endif
