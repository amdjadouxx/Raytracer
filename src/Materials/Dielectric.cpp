/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Dielectric
*/

/**
 * @file Dielectric.cpp
 * @brief Implementation of the Dielectric class
 */

#include "Dielectric.hpp"


/**
 * @brief Construct a new Dielectric object
 * 
 * @param refractionIndex The refraction index of the dielectric material
 */
Dielectric::Dielectric(double refractionIndex) : _refractionIndex(refractionIndex) {}

/**
 * @brief Determines how a ray scatters when it hits this dielectric material
 * 
 * @param r_in The incoming ray
 * @param rec The hit record containing details of the ray-object intersection
 * @param attenuation The amount by which the ray's intensity is reduced
 * @param scattered The scattered ray after hitting the object
 * @return true Always returns true indicating that scattering always occurs
 */
bool Dielectric::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const
{
    Vector3D utils;
    Random random;
    attenuation = Color(1.0, 1.0, 1.0);
    double ri = rec.getFrontFace() ? (1.0/_refractionIndex) : _refractionIndex;
    Vector3D unitDirection = utils.unitVector(r_in.getDirection());
    double cos_theta = fmin(dot(-unitDirection, rec.getNormal()), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

    bool cannot_refract = ri * sin_theta > 1.0;

    Vector3D direction;
    if (cannot_refract || direction.reflectance(cos_theta, ri) > random.randomDouble())
        direction = direction.reflect(unitDirection, rec.getNormal());
    else
        direction = direction.refract(unitDirection, rec.getNormal(), ri);
    scattered = Ray(rec.getPosition(), direction);
    return true;
}

/**
 * @brief Get the Refraction Index of the dielectric material
 * 
 * @return double The refraction index
 */
double Dielectric::getRefractionIndex() const
{
    return _refractionIndex;
}