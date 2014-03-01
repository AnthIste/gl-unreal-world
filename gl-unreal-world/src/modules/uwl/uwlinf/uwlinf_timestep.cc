#include "uwlinf_timestep.h"

#include <cmath>

namespace uwlinf {

void TimeStep::tick()
{
    //double frameTime = std::min(_clock->tick(), 0.25);
    double frameTime = _clock->tick();
    _accumulator += frameTime;
}

double TimeStep::t()
{
    return _t;
}

double TimeStep::dt()
{
    return _dt;
}

bool TimeStep::hasTime()
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

double TimeStep::alpha()
{
    return _accumulator / _dt;
}

}; /* namespace uwl */
