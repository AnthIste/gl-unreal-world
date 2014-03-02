#include "uwlinf_timestep.h"

#include <cmath>

namespace uwlinf {

void TimeStep::tick()
{
    _frameTime = std::min(_clock->tick(), 0.25);
    _accumulator += _frameTime;
}

double TimeStep::t() const
{
    return _t;
}

double TimeStep::rt() const
{
    return _clock->getTime();
}

double TimeStep::dt() const
{
    return _dt;
}

double TimeStep::rdt() const
{
    return _frameTime;
}

bool TimeStep::hasTime() const
{
    return _accumulator > _dt;
}

void TimeStep::consumeTime()
{
    if (_accumulator > _dt) {
        _t += _dt;
        _accumulator -= _dt;
    }
}

double TimeStep::alpha() const
{
    return _accumulator / _dt;
}

}; /* namespace uwl */
