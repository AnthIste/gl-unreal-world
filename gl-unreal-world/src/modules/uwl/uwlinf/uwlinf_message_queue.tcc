#ifndef INC_UWLINF_MQ_TCC
#define INC_UWLINF_MQ_TCC

#include "uwlinf_message_queue.h"

namespace uwlinf {

template <typename TMessage>
MessageQueue<TMessage>::MessageQueue()
{
}

template <typename TMessage>
void MessageQueue<TMessage>::postMessage(TMessage message)
{
    _queue.push(message);
}

template <typename TMessage>
TMessage MessageQueue<TMessage>::popMessage()
{
    return _queue.pop();
}

template <typename TMessage>
bool MessageQueue<TMessage>::hasMessage()
{
    return !_queue.empty();
}

};

#endif
