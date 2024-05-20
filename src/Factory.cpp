/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Factory
*/
#include "Factory.hpp"
#include "Parser.hpp"

Factory::Factory()
{
    initializeComponentMap();
}

Factory::~Factory()
{
}

void Factory::create_sphere(std::any arg)
{
    auto params = std::any_cast<std::tuple<double , double, double, double, int, double, double, double, double>>(arg);
    double x = std::get<0>(params);
    double y = std::get<1>(params);
    double z = std::get<2>(params);
    Point3D center(x, y, z);
    double radius = std::get<3>(params);
    int material = std::get<4>(params);
    double colorX = std::get<5>(params);
    double colorY = std::get<6>(params);
    double colorZ = std::get<7>(params);
    double fuzz = std::get<8>(params);
    if (material == 1) {
        auto Material = std::make_shared<Lambertian>(Color(colorX, colorY, colorZ));
        _world.add(std::make_shared<Sphere>(center, radius, Material));
    } else if (material == 2) {
        auto Material = std::make_shared<Metal>(Color(colorX, colorY, colorZ), fuzz);
        _world.add(std::make_shared<Sphere>(center, radius, Material));
    } else if (material == 3) {
        auto Material = std::make_shared<Dielectric>(fuzz);
        _world.add(std::make_shared<Sphere>(center, radius, Material));
    }
}

void Factory::create_planes(std::any arg)
{
    auto params = std::any_cast<std::tuple<double , double, double, double, int, double, double, double, double>>(arg);
    double x = std::get<0>(params);
    double y = std::get<1>(params);
    double z = std::get<2>(params);
    Point3D center(x, y, z);
    double radius = std::get<3>(params);
    int material = std::get<4>(params);
    double colorX = std::get<5>(params);
    double colorY = std::get<6>(params);
    double colorZ = std::get<7>(params);
    double fuzz = std::get<8>(params);
    if (material == 1) {
        auto Material = std::make_shared<Lambertian>(Color(colorX, colorY, colorZ));
        _world.add(std::make_shared<Sphere>(center, radius, Material));
    } else if (material == 2) {
        auto Material = std::make_shared<Metal>(Color(colorX, colorY, colorZ), fuzz);
        _world.add(std::make_shared<Sphere>(center, radius, Material));
    } else if (material == 3) {
        auto Material = std::make_shared<Dielectric>(colorX);
        _world.add(std::make_shared<Sphere>(center, radius, Material));
    }
}

void Factory::create_camera(std::any arg)
{
    auto params = std::any_cast<std::tuple<int, double, int, int, double, Point3D, Point3D, Vector3D>>(arg);
    int width = std::get<0>(params);
    double aspectRatio = std::get<1>(params);
    int samplesPerPixel = std::get<2>(params);
    int maxDepth = std::get<3>(params);
    double vfov = std::get<4>(params);
    Point3D lookfrom = std::get<5>(params);
    Point3D lookat = std::get<6>(params);
    Vector3D vec = std::get<6>(params);
    _camera.init(width, aspectRatio, samplesPerPixel, maxDepth, vfov, lookfrom, lookat, vec);
}

void Factory::initializeComponentMap()
{
    componentMap_["sphere"] = std::bind(&Factory::create_sphere, this, std::placeholders::_1);
    componentMap_["camera"] = std::bind(&Factory::create_camera, this, std::placeholders::_1);
    componentMap_["plane"] = std::bind(&Factory::create_planes, this, std::placeholders::_1);
}

void Factory::createComponent(std::string type, std::any arg)
{
    auto it = componentMap_.find(type);
    if (it != componentMap_.end()) {
        return it->second(arg);
    } else {
        return;
    }
}

HittableList &Factory::getWorld()
{
    return _world;
}

Camera &Factory::getCamera()
{
    return _camera;
}