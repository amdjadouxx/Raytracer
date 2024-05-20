/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Planes
*/
#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>
#include "AObject.hpp"
#include "IHittable.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Interval.hpp"

class Planes : public AObject {
    public:
        Planes(const Point3D& center, double radius);
        ~Planes();
        bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
    private:
        Point3D center;
        double radius;
};

#endif /* !PLANES_HPP */