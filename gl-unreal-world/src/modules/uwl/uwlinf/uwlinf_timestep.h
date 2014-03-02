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
          _frameTime(0.0),
          _accumulator(0.0)
    { }

    virtual ~TimeStep() { }

    /// <summary>
    /// Creates simulation time to be consumed
    /// </summary>
    virtual void tick();

    /// <summary>
    /// Current simulation time
    /// </summary>
    virtual double t() const;

    /// <summary>
    /// Current real wall-clock time, can go out of sync with
    /// simulation time (spiral of death)
    /// </summary>
    virtual double rt() const;

    /// <summary>
    /// Fixed timestep value
    /// </summary>
    virtual double dt() const;

    /// <summary>
    /// Current real wall-clock dt, can go out of sync with
    /// accumulated simulation time (spiral of death)
    /// </summary>
    virtual double rdt() const;

    /// <summary>
    /// Enough time has accumulated for at least 1 dt step to be consumed
    /// </summary>
    virtual bool hasTime() const;

    /// <summary>
    /// Proceed simulation time by dt
    /// </summary>
    virtual void consumeTime();

    /// <summary>
    /// Simulation time < dt that is accumulated but not yet consumed
    /// </summary>
    virtual double alpha() const;

private:
    std::shared_ptr<uwlinf::Clock> _clock;

    double _t;

    double _dt;

    double _frameTime;

    double _accumulator;

};

}; /* namespace uwl */

#endif
