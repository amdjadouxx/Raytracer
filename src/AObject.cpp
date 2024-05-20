/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AObject
*/

#include "AObject.hpp"

AObject::AObject()
{
}

AObject::~AObject()
{
}


// Getters and Setters for IsHittable
bool AObject::getIsHittable() const
{
    return _isHittable;
}

void AObject::setIsHittable(const bool isHittable)
{
    _isHittable = isHittable;
}
