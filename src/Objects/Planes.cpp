/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Planes
*/

#include "Planes.hpp"

/**
 * @brief Construct a new Planes object
 * @param center The center of the plane
 * @param radius The radius of the plane
*/
Planes::Planes(const Point3D& center, double radius) : center(center), radius(fmax(0,radius))
{
    setIsHittable(true);
}


/**
 * @brief Destroy the Planes object
*/
Planes::~Planes()
{
}

/**
 * @brief Get the center of the plane
 * @return Point3D The center of the plane
*/
bool Planes::hit(const Ray& r, Interval ray_t, HitRecord& rec) const
{
    if (!getIsHittable()) //TODO decorateur
        return false;
    Vector3D oc = center - r.getOrigin();
    auto a = r.getDirection().lengthSquared();
    auto h = dot(r.getDirection(), oc);
    auto c = oc.lengthSquared() - radius*radius;
    auto discriminant = h*h - a*c;

    if (discriminant < 0)
        return false;

    auto sqrtd = std::sqrt(discriminant);
    auto root = (h - sqrtd) / a;

    if (!ray_t.srds(root)) {
        root = (h + sqrtd) / a;
        if (!ray_t.srds(root))
            return false;
    }

    rec.setTranslation(root);
    rec.setPosition(r.at(rec.getTranslation()));
    Vector3D outwardNormal = (rec.getPosition() - center) / radius;
    rec.setFaceNormal(r, outwardNormal);
    return true;
}
