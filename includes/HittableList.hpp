/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** HittableList
*/

#ifndef HITTABLELIST_HPP_
#define HITTABLELIST_HPP_

#include "IHittable.hpp"
#include "Interval.hpp"
#include "Ray.hpp"
#include <memory>
#include <vector>

class HittableList : public IHittable {
    public:
        HittableList();
        HittableList(std::shared_ptr<IHittable> object);
        ~HittableList() = default;

        void clear();
        void add(std::shared_ptr<IHittable> object);

        bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

        std::vector<std::shared_ptr<IHittable>> getObjects() const;

    private:
        std::vector<std::shared_ptr<IHittable>> objects;
};

#endif /* !HITTABLELIST_HPP_ */