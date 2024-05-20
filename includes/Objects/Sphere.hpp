/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Sphere
*/
#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <vector>
#include "AObject.hpp"
#include "IHittable.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Interval.hpp"
#include "AMaterial.hpp"
#include <memory>

class Sphere : public AObject {
    public:
        Sphere(const Point3D& center, double radius, std::shared_ptr<AMaterial> mat);
        ~Sphere();
        bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
    private:
        Point3D center;
        double radius;
        std::shared_ptr<AMaterial> _mat;
};

#endif