/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Interval
*/
#include "Interval.hpp"

Interval::Interval()
{
    _min = +std::numeric_limits<double>::infinity();
    _max = -std::numeric_limits<double>::infinity();
}

Interval::Interval(double min, double max)
{
    _min = min;
    _max = max;
}

double Interval::getSize() const
{
    return _max - _min;
}

bool Interval::isIn(double x) const
{
    return _min <= x && x <= _max;
}

bool Interval::srds(double x) const
{
    return _min < x && x < _max;
}

double Interval::getMin() const
{
    return _min;
}

double Interval::getMax() const
{
    return _max;
}

void Interval::setMin(double min)
{
    _min = min;
}

void Interval::setMax(double max)
{
    _max = max;
}

double Interval::clmp(double x) const
{
    return std::clamp(x, _min, _max);
}