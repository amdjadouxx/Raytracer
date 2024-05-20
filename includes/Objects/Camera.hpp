/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <iostream>
#include <vector>
#include "AObject.hpp"
#include "IHittable.hpp"
#include "HittableList.hpp"
#include "Interval.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include "AMaterial.hpp"
#include <fstream>
#include "Random.hpp"

class Camera : public AObject {
    public:
        Camera();
        Camera(int width, double aspectRatio, int samplesPerPix, int maxDepth, double vfov, Point3D lookfrom, Point3D lookat, Vector3D vup);
        void init(int width, double aspectRatio, int samplesPerPix, int maxDepth, double vfov, Point3D lookfrom, Point3D lookat, Vector3D vup);
        ~Camera();
        bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
        void render(const IHittable& world);
        void generatePPM(const std::string& filename, const HittableList& world);
        Color rayColorAttribute(const Ray& r, const IHittable& world) const;
        double linearToGamma(double linear_component);
        void writeColor(std::ostream& out, const Color& pixel_color);
        Ray getRay(int i, int j) const;
        Vector3D sampleSquare() const;
        Color rayColor(const Ray& r, int depth, const HittableList& world) const;
        Point3D getCenter() const;
        Point3D defocusDiskSample() const;
    private:
        double _vfov;
        int _height;
        double _aspectRatio;
        int _width;
        int _samplesPerPix;
        int _maxDepth;
        double _pixSampleScale;
        Point3D _center;
        Point3D _pixel00;
        Vector3D _delta_u;
        Vector3D _delta_v;
        Point3D _lookfrom;
        Point3D _lookat;
        Vector3D _vup;
        Vector3D _u, _v, _w;
        double _defocusAngle = 10.0;
        double _focusDist = 3.4;
        Vector3D _defocusDiskU;
        Vector3D _defocusDiskV;
};
#endif /* !CAMERA_HPP_ */
