//
// Created by Om K. on 2/21/2023.
//

#ifndef RAYTRACER_VEC_H
#define RAYTRACER_VEC_H


#include "point.h"

class vec: public tuple {
    public:
        vec(const tuple& t) : tuple(t.getX(), t.getY(), t.getZ(), 0) {}
        vec(point origin, point tail) : tuple(tail.getX()-origin.getX(), tail.getY()-origin.getY(), tail.getZ()-origin.getZ(), 0){}
        vec(double x, double y, double z) : tuple(x, y, z, 0) {};
        static double dotProduct(vec &a, vec &b);
        static vec crossProduct(vec &a, vec &b);
        double magnitude();
        vec unitVector();
};


#endif //RAYTRACER_VEC_H
