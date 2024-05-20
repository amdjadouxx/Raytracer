
/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** IObjects
*/
#ifndef AOBJECTS_HPP
#define AOBJECTS_HPP

#include "IHittable.hpp"

class AObject : public IHittable {
    public:
        AObject();
        ~AObject();

        //for hittable properties
        virtual bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override = 0;
        bool getIsHittable() const;
        void setIsHittable(const bool isHittable);

    private:
        bool _isHittable;
};

#endif /* !AOBJECTS_HPP */