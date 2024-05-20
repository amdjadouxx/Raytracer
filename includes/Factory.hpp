/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Factory
*/
#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include <iostream>
#include <map>
#include <string>
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Planes.hpp"
#include <unordered_map>
#include <functional>
#include <any>
#include <memory>
#include <vector>
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"
#include "HittableList.hpp"


class Factory {
public:
    Factory();
    ~Factory();
    void createComponent(std::string type, std::any arg = std::any());
    using ComponentCreatorFunc = std::function<void(std::any)>;
    std::unordered_map<std::string, ComponentCreatorFunc> componentMap_;
    void create_sphere(std::any arg);
    void create_planes(std::any arg);
    void create_camera(std::any arg);
    void initializeComponentMap();
    HittableList &getWorld();
    Camera &getCamera();

protected:
private:
    HittableList _world;
    Camera _camera;
};

#endif /* !FACTORY_HPP_ */