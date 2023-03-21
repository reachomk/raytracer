//
// Created by Om K. on 3/11/2023.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include <array>
#include "ray.h"
#include "object.h"
#include "matrix.h"
#include "light.h"

using std::array;

class sphere : public object {
    matrix transformMatrix = matrix::identity(4);
    public:
        sphere() : object(0) {}
        array<double, 2> intersectionTimes(ray rayToSphere);
        void translate(double x, double y, double z);
        void scale(double x, double y, double z);
        vec normalAt(point& p);
        matrix getTransformMatrix();
        static vec reflectionVector(vec& lightVec, vec& normal);
        color lighting(light &lighting, point& p, vec& cameraLight, vec& normal);
};


#endif //RAYTRACER_SPHERE_H
