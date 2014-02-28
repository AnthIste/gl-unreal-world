#ifndef INC_UWLINF_MQ_H
#define INC_UWLINF_MQ_H

#include <memory>
#include <queue>

namespace uwlinf {

template <typename TMessage>
class MessageQueue {
public:
    MessageQueue();

    virtual ~MessageQueue() { }

    virtual void postMessage(std::unique_ptr<TMessage> message);

    virtual std::unique_ptr<TMessage> popMessage();

    virtual bool hasMessage();

private:
    std::queue<std::unique_ptr<TMessage>> _queue;

};

};

#include "uwlinf_message_queue.tcc"

#endif
