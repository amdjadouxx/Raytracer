/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Lambertian
*/

#include "Lambertian.hpp"

/**
 * @brief Get the Refraction Index of the dielectric material
 * 
 * @return double The refraction index
 */
Lambertian::Lambertian(const Color &albedo) : _albedo(albedo)
{
}

/**
 * @brief Destroy the Lambertian object
 */
Lambertian::~Lambertian()
{
}

/**
 * @brief Determines how a ray scatters when it hits this Lambertian material
 * 
 * @param r_in The incoming ray
 * @param rec The hit record containing details of the ray-object intersection
 * @param attenuation The amount by which the ray's intensity is reduced
 * @param scattered The scattered ray after hitting the object
 * @return true Always returns true indicating that scattering always occurs
 */
bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const
{
    (void)r_in;
    Vector3D utils;
    auto scatter_direction = rec.getNormal() + utils.randomUnitVector();
    if (scatter_direction.nearZero())
        scatter_direction = rec.getNormal();
    scattered = Ray(rec.getPosition(), scatter_direction);
    attenuation = _albedo;
    return true;
}