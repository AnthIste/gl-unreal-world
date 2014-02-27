#ifndef INC_UWLINF_CLOCK_H
#define INC_UWLINF_CLOCK_H

namespace uwlinf {

class Clock {
public:
    Clock();

    virtual ~Clock() { }

    virtual double tick();

    virtual double getTime();

    virtual double getAbsoluteTime();

    virtual void setTimeScale(double scale);

private:
    double scaledTime(double time);

private:
    double _time;

    double _elapsedTime;

    double _scale;
};

};

#endif
