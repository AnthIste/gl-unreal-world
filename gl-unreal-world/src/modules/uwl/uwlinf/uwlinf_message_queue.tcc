#ifndef INC_UWLINF_MQ_TCC
#define INC_UWLINF_MQ_TCC

#include "uwlinf_message_queue.h"

namespace uwlinf {

template <typename TMessage>
MessageQueue<TMessage>::MessageQueue()
{
}

template <typename TMessage>
void MessageQueue<TMessage>::postMessage(std::unique_ptr<TMessage> message)
{
    _queue.push(std::move(message));
}

template <typename TMessage>
std::unique_ptr<TMessage> MessageQueue<TMessage>::popMessage()
{
    auto front = std::move(_queue.front());
    _queue.pop();

    return front;
}

template <typename TMessage>
bool MessageQueue<TMessage>::hasMessage()
{
    return !_queue.empty();
}

};

#endif
