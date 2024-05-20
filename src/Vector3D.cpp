/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <cmath>

Vector3D::Vector3D()
{
    _pos[0] = 0;
    _pos[1] = 0;
    _pos[2] = 0;
}

Vector3D::Vector3D(double e0, double e1, double e2)
{
    _pos[0] = e0;
    _pos[1] = e1;
    _pos[2] = e2;
}

double Vector3D::getX() const
{
    return _pos[0];
}

double Vector3D::getY() const
{
    return _pos[1];
}

double Vector3D::getZ() const
{
    return _pos[2];
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-_pos[0], -_pos[1], -_pos[2]);
}

double Vector3D::operator[](int i) const
{
    return _pos[i];
}

double& Vector3D::operator[](int i)
{
    return _pos[i];
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
    _pos[0] += v.getX();
    _pos[1] += v.getY();
    _pos[2] += v.getZ();
    return *this;
}

Vector3D& Vector3D::operator*=(double t)
{
    _pos[0] *= t;
    _pos[1] *= t;
    _pos[2] *= t;
    return *this;
}

Vector3D& Vector3D::operator/=(double t)
{
    return *this *= 1/t;
}

double Vector3D::length() const
{
    return sqrt(lengthSquared());
}

double Vector3D::lengthSquared() const
{
    return _pos[0]*_pos[0] + _pos[1]*_pos[1] + _pos[2]*_pos[2];
}



// TODO
std::ostream& operator<<(std::ostream& out, const Vector3D& v)
{
    return out << v.getX() << ' ' << v.getY() << ' ' << v.getZ();
}

Vector3D operator+(const Vector3D& u, const Vector3D& v)
{
    return Vector3D(u.getX() + v.getX(), u.getY() + v.getY(), u.getZ() + v.getZ());
}

Vector3D operator-(const Vector3D& u, const Vector3D& v)
{
    return Vector3D(u.getX() - v.getX(), u.getY() - v.getY(), u.getZ() - v.getZ());
}

Vector3D operator*(const Vector3D& u, const Vector3D& v)
{
    return Vector3D(u.getX() * v.getX(), u.getY() * v.getY(), u.getZ() * v.getZ());
}

Vector3D operator*(double t, const Vector3D& v)
{
    return Vector3D(t*v.getX(), t*v.getY(), t*v.getZ());
}

Vector3D operator*(const Vector3D& v, double t)
{
    return t * v;
}

Vector3D operator/(const Vector3D& v, double t)
{
    return (1/t) * v;
}

double dot(const Vector3D& u, const Vector3D& v)
{
    return u.getX() * v.getX()
         + u.getY() * v.getY()
         + u.getZ() * v.getZ();
}

Vector3D cross(const Vector3D& u, const Vector3D& v)
{
    return Vector3D(u.getY() * v.getZ() - u.getZ() * v.getY(),
                     u.getZ() * v.getX() - u.getX() * v.getZ(),
                     u.getX() * v.getY() - u.getY() * v.getX());
}

Vector3D unitVector(const Vector3D& v)
{
    return v / v.length();
}

Vector3D Vector3D::random()
{
    Random random;
    return Vector3D(random.randomDouble(), random.randomDouble(), random.randomDouble());
}

Vector3D Vector3D::random (double min, double max) {
    Random random;
    return Vector3D(random.randomDouble(min,max), random.randomDouble(min,max), random.randomDouble(min,max));
}

Vector3D Vector3D::unitVector(const Vector3D& v) {
    return v / v.length();
}

Vector3D Vector3D::randomInUnitSphere() {
    while (true) {
        auto p = Vector3D::random(-1,1);
        if (p.lengthSquared() < 1)
            return p;
    }
}

Vector3D Vector3D::randomUnitVector() {
    return unitVector(randomInUnitSphere());
}

Vector3D Vector3D::randomOnHemisphere(const Vector3D& normal) {
    Vector3D onUnitSphere = randomUnitVector();
    if (dot(onUnitSphere, normal) > 0.0)
        return onUnitSphere;
    else
        return -onUnitSphere;
}

bool Vector3D::nearZero() const {
    const auto s = 1e-8;
    return (std::fabs(_pos[0]) < s) && (std::fabs(_pos[1]) < s) && (std::fabs(_pos[2]) < s);
}

Vector3D Vector3D::reflect(const Vector3D& v, const Vector3D& n) {
    return v - 2*dot(v,n)*n;
}

Vector3D Vector3D::refract(const Vector3D& uv, const Vector3D& n, double etaiOverState) {
    auto cosTheta = fmin(dot(-uv, n), 1.0);
    Vector3D rOutPerp =  etaiOverState * (uv + cosTheta*n);
    Vector3D rOutParallel = -std::sqrt(std::fabs(1.0 - rOutPerp.lengthSquared())) * n;
    return rOutPerp + rOutParallel;
}

double Vector3D::reflectance(double cosine, double refraction_index)
{
    auto r0 = (1 - refraction_index) / (1 + refraction_index);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}

double Vector3D::degreesToRadians(double degrees)
{
    return degrees * getPi() / 180.0;
}

double Vector3D::getPi() const
{
    return _pi;
}

Vector3D Vector3D::randomInUnitDisk() {
    Random _random;
    while (true) {
        auto p = Vector3D(_random.randomDouble(-1,1), _random.randomDouble(-1,1), 0);
        if (p.lengthSquared() < 1)
            return p;
    }
}