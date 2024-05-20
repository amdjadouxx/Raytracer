/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Dielectric
*/

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_
#include "AMaterial.hpp"
#include "HitRecord.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

class Dielectric : public AMaterial {
    public:
        Dielectric(double refractionIndex);

        ~Dielectric() = default;

        bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;

        double getRefractionIndex() const;

  private:
    double _refractionIndex;
};
#endif /* !DIELECTRIC_HPP_ */
