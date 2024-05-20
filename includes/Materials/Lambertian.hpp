/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Lambertian
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "HitRecord.hpp"
#include "AMaterial.hpp"

class Lambertian : public AMaterial {
    public:
        Lambertian(const Color& albedo);
        ~Lambertian();
        bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;

    private:
        Color _albedo;
};

#endif /* !LAMBERTIAN_HPP_ */
