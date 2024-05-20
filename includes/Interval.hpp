/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Interval
*/

#ifndef INTERVAL_HPP_
#define INTERVAL_HPP_

#include <cmath>
#include <limits>
#include <algorithm>

class Interval {
  public:
    Interval();

    Interval(double min, double max);

    double getSize() const;

    bool isIn(double x) const;

    bool srds(double x) const;

    double clmp(double x) const;

    double getMin() const;
    double getMax() const;

    void setMin(double min);
    void setMax(double max);

    private:
        double _min, _max;
};

#endif /* !INTERVAL_HPP_ */
