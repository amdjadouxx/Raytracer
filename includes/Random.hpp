/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <random>

class Random {
    public:
    Random();
    ~Random();
    double randomDouble();
    double randomDouble(double min, double max);
};



#endif /* !UTILS_HPP_ */
