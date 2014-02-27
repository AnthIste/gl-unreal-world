#ifndef INC_UWLINF_MQ_H
#define INC_UWLINF_MQ_H

#include <queue>

namespace uwlinf {

template <typename TMessage>
class MessageQueue {
public:
    MessageQueue();

    virtual ~MessageQueue() { }

    virtual void postMessage(TMessage message);

    virtual TMessage popMessage();

    virtual bool hasMessage();

private:
    std::queue<TMessage> _queue;

};

};

#include "uwlinf_message_queue.tcc"

#endif
