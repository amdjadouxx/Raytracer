/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** HittableList
*/

#include "HittableList.hpp"

HittableList::HittableList()
{

}

HittableList::HittableList(std::shared_ptr<IHittable> object)
{
    add(object);
}

void HittableList::clear()
{
    objects.clear();
}

void HittableList::add(std::shared_ptr<IHittable> object)
{
    objects.push_back(object);
}

bool HittableList::hit(const Ray& r, Interval ray_t, HitRecord& rec) const
{
    HitRecord temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.getMax();

        for (const auto& object : objects) {
            if (object->hit(r, Interval(ray_t.getMin(), closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.getTranslation();
                rec = temp_rec;
            }
        }

        return hit_anything;
}

std::vector<std::shared_ptr<IHittable>> HittableList::getObjects() const
{
    return objects;
}