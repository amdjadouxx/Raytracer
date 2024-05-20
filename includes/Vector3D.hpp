/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <cmath>
#include <ostream>
#include "Random.hpp"


class Vector3D {
    public:
        Vector3D();
        Vector3D(double e0, double e1, double e2);

        double getX() const;
        double getY() const;
        double getZ() const;

        Vector3D operator-() const;
        double operator[](int i) const;
        double& operator[](int i);

        Vector3D& operator+=(const Vector3D& v);
        Vector3D& operator*=(double t);
        Vector3D& operator/=(double t);

        Vector3D random();
        Vector3D random (double min, double max);
        Vector3D unitVector(const Vector3D& v);
        Vector3D randomInUnitSphere();
        Vector3D randomUnitVector();
        Vector3D randomOnHemisphere(const Vector3D& normal);

        double length() const;
        double lengthSquared() const;

        bool nearZero() const;

        Vector3D reflect(const Vector3D& v, const Vector3D& n);
        Vector3D refract(const Vector3D& uv, const Vector3D& n, double etaiOverState);
        static double reflectance(double cosine, double refraction_index);
        double degreesToRadians(double degrees);
        double getPi() const;

        Vector3D randomInUnitDisk();

    private:
        double _pos[3];
        double _pi = 3.1415926535897932385;
};

using Point3D = Vector3D;
using Color = Vector3D;

std::ostream& operator<<(std::ostream& out, const Vector3D& v);
Vector3D operator+(const Vector3D& u, const Vector3D& v);
Vector3D operator-(const Vector3D& u, const Vector3D& v);
Vector3D operator*(const Vector3D& u, const Vector3D& v);
Vector3D operator*(double t, const Vector3D& v);
Vector3D operator*(const Vector3D& v, double t);
Vector3D operator/(const Vector3D& v, double t);
double dot(const Vector3D& u, const Vector3D& v);
Vector3D cross(const Vector3D& u, const Vector3D& v);
Vector3D unitVector(const Vector3D& v);

#endif