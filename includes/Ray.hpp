/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Ray
*/
#ifndef RAY_HPP
#define RAY_HPP
#include "Vector3D.hpp"

class Ray {
    public:
        Ray();
        Ray(const Point3D& origin, const Vector3D& direction);
        ~Ray();
        const Point3D& getOrigin() const;
        const Vector3D& getDirection() const;
        void setOrigin(const Point3D& origin);
        void setDirection(const Vector3D& direction);
        Point3D at(double t) const;

    private:
        Point3D _orig;
        Vector3D _dir;
};

#endif /* !RAY_HPP */
