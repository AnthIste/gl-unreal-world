#ifndef INC_UWLINF_MESSAGE_QUEUE_BASE_TCC
#define INC_UWLINF_MESSAGE_QUEUE_BASE_TCC

#include "uwlinf_message_queue_base.h"

namespace uwlinf {

template <typename TMessage>
MessageQueueBase<TMessage>::MessageQueueBase()
{
}

template <typename TMessage>
void MessageQueueBase<TMessage>::postMessage(std::unique_ptr<TMessage> message)
{
    if (!message) {
        return;
    }

    _queue.push(std::move(message));
}

template <typename TMessage>
std::unique_ptr<TMessage> MessageQueueBase<TMessage>::popMessage()
{
    auto front = std::move(_queue.front());
    _queue.pop();

    return front;
}

template <typename TMessage>
bool MessageQueueBase<TMessage>::hasMessage()
{
    return !_queue.empty();
}

};

#endif
