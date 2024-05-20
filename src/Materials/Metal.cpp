/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Metal
*/

#include "Metal.hpp"

/**
 * @brief Construct a new Metal object
 * 
 * @param albedo The color of the Metal object
 * @param fuzz The fuzziness of the Metal object, capped at 1
 */
Metal::Metal(const Color &albedo, const double fuzz) : _albedo(albedo), _fuzz(fuzz < 1 ? fuzz : 1) {}

/**
 * @brief Destroy the Metal object
 * 
 */
Metal::~Metal() {}

/**
 * @brief Determines if a ray scatters off the Metal object
 * 
 * @param r_in The incoming ray
 * @param rec The hit record containing details of the ray-object intersection
 * @param attenuation The attenuation of the ray after scattering
 * @param scattered The scattered ray after hitting the object
 * @return true If the ray scatters (i.e., the angle between the scattered ray and the normal is greater than 0)
 * @return false Otherwise
 */
bool Metal::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vector3D reflected = reflected.reflect(r_in.getDirection(), rec.getNormal());
    reflected = reflected.unitVector(reflected) + (_fuzz * reflected.randomUnitVector());
    scattered = Ray(rec.getPosition(), reflected);
    attenuation = _albedo;
    return (dot(scattered.getDirection(), rec.getNormal()) > 0);
}