#ifndef INC_UWLINF_TIMESTEP_H
#define INC_UWLINF_TIMESTEP_H

#include "uwlinf_clock.h"

#include <memory>

namespace uwlinf {

class TimeStep {
public:
    TimeStep(std::shared_ptr<uwlinf::Clock> clock, double dt)
        : _clock(clock),
          _t(0.0),
          _dt(dt),
          _accumulator(0.0)
    { }

    virtual ~TimeStep() { }

    virtual void tick();

    virtual double t();

    virtual double dt();

    virtual bool hasTime();

    virtual void consumeTime();

    virtual double alpha();

private:
    std::shared_ptr<uwlinf::Clock> _clock;

    double _t;

    double _dt;

    double _accumulator;

};

}; /* namespace uwl */

#endif
