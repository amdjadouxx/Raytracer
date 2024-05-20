/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray() : _orig(Point3D(0, 0, 0)), _dir(Vector3D(0, 0, 0))

{

}

Ray::Ray(const Point3D& origin, const Vector3D& direction) : _orig(origin), _dir(direction)
{

}

Ray::~Ray()
{

}

const Point3D& Ray::getOrigin() const
{
    return _orig;
}

Point3D Ray::at(double t) const
{
    return _orig + t*_dir;
}

const Vector3D& Ray::getDirection() const
{
    return _dir;
}

void Ray::setOrigin(const Point3D& origin)
{
    _orig = origin;
}

void Ray::setDirection(const Vector3D& direction)
{
    _dir = direction;
}