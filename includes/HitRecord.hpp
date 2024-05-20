/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** HitRecord
*/

#ifndef HITRECORD_HPP_
#define HITRECORD_HPP_

#include "Vector3D.hpp"
#include "Ray.hpp"
#include <memory>

class AMaterial;

class HitRecord {
    public:
        HitRecord();
        ~HitRecord();

        // Getters and Setters for positionshared_ptr<material> mat;
        Point3D getPosition() const;
        void setPosition(const Point3D pos);

        // Getters and Setters for normal
        Vector3D getNormal() const;
        void setNormal(const Vector3D normal);

        // Getters and Setters for t
        double getTranslation() const;
        void setTranslation(const double translation);

        // Getters and Setters for frontFace
        bool getFrontFace() const;
        void setFrontFace(const bool frontFace);

        void setFaceNormal(const Ray& rayon, const Vector3D& outward_normal);

        void setMat(std::shared_ptr<AMaterial> mat);

        std::shared_ptr<AMaterial> getMat() const;

    private:
        Point3D _position;
        Vector3D _normal;
        double _translation;
        bool _frontFace;
        std::shared_ptr<AMaterial> _mat;
};

#endif /* !HITRECORD_HPP_ */
