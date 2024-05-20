/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Sphere
*/

#include "Sphere.hpp"

/**
 * @brief Construct a new Sphere object
 * @param center The center of the sphere
 * @param radius The radius of the sphere
 * @param mat The material of the sphere
*/
Sphere::Sphere(const Point3D& center, double radius, std::shared_ptr<AMaterial> mat) : center(center), radius(fmax(0, radius)), _mat(mat)
{
    setIsHittable(true);
}

/**
 * @brief Destroy the Sphere object
*/
Sphere::~Sphere()
{
}

/**
 * @brief Check if a ray hits the sphere
 * @param r The ray to check
 * @param ray_t The interval of the ray
 * @param rec The hit record to fill
 * @return true If the ray hits the sphere
 * @return false Otherwise
*/
bool Sphere::hit(const Ray& r, Interval ray_t, HitRecord& rec) const
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
    rec.setMat(_mat);
    return true;
}
