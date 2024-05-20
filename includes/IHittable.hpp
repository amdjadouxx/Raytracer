/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** IHitable
*/
#ifndef IHITABLE_HPP
#define IHITABLE_HPP

#include "Ray.hpp"
#include "HitRecord.hpp"
#include "Interval.hpp"


class IHittable {
    public:
        virtual ~IHittable() = default;
        virtual bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const = 0;
};

#endif /* !IHITABLE_HPP */
