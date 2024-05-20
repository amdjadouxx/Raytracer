/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Utils
*/

#include "Random.hpp"

Random::Random() {
}

Random::~Random() {
}

double Random::randomDouble() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

double Random::randomDouble(double min, double max) {
    return min + (max - min) * randomDouble();
}