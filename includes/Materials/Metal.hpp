/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include "AMaterial.hpp"

class Metal : public AMaterial {
  public:
    Metal(const Color& albedo, double fuzz);

    ~Metal();

    bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;

  private:
    Color _albedo;
    double _fuzz;
};

#endif /* !METAL_HPP_ */
