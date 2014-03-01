#include "uwlinf_clock.h"

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

namespace uwlinf {

Clock::Clock()
{
    _time = 0.0;
    _elapsedTime = 0.0;
    _scale = 1.0;
}

double Clock::tick()
{
    double t = glfwGetTime();
    double dt = t - _time;
    double sdt = scaledTime(dt);

    _time = t;
    _elapsedTime += sdt;

    return sdt;
}

double Clock::getTime()
{
    return _elapsedTime;
}

double Clock::getAbsoluteTime()
{
    return _time;
}

void Clock::setTimeScale(double scale)
{
    _scale = scale;
}

double Clock::scaledTime(double time)
{
    return time * _scale;
}

};
