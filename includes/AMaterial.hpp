/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** AMaterial
*/


#ifndef MATERIAL_H
#define MATERIAL_H

#include "HitRecord.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

class AMaterial {
  public:
    AMaterial();
    ~AMaterial() = default;

    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const;
};

#endif