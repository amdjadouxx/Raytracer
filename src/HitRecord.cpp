/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** HitRecord
*/

#include "HitRecord.hpp"

HitRecord::HitRecord()
{
}

HitRecord::~HitRecord()
{
}

// Getters and Setters for position
Point3D HitRecord::getPosition() const
{
    return _position;
}

void HitRecord::setPosition(Point3D pos)
{
    _position = pos;
}

// Getters and Setters for normal
Vector3D HitRecord::getNormal() const
{
    return _normal;
}

void HitRecord::setNormal(const Vector3D normal)
{
    _normal = normal;
}

// Getters and Setters for translation
double HitRecord::getTranslation() const
{
    return _translation;
}

void HitRecord::setTranslation(const double translation)
{
    _translation = translation;
}

// Getters and Setters for front face
bool HitRecord::getFrontFace() const
{
    return _frontFace;
}

void HitRecord::setFrontFace(const bool ff)
{
    _frontFace = ff;
}

void HitRecord::setFaceNormal(const Ray& r, const Vector3D& outward_normal) {
    _frontFace = dot(r.getDirection(), outward_normal) < 0;
    _normal = _frontFace ? outward_normal : -outward_normal;
}

void HitRecord::setMat(std::shared_ptr<AMaterial> mat)
{
    _mat = mat;
}

std::shared_ptr<AMaterial> HitRecord::getMat() const
{
    return _mat;
}