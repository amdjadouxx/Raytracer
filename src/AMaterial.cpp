/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** AMaterial
*/

#include "AMaterial.hpp"

AMaterial::AMaterial()
{
}

bool AMaterial::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const
{
    (void)r_in;
    (void)rec;
    (void)attenuation;
    (void)scattered;
    return false;
}