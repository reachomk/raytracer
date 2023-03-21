//
// Created by Om K. on 2/21/2023.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


#include "tuple.h"

// assume x is r, y is g, and z is b
class color : public tuple {
    public:
        color(double r, double g, double b) :  tuple(r, g, b, -1){}
        color(const tuple& t) : tuple(t.getX(), t.getY(), t.getZ(), -1) {}
        color() : tuple(0, 0.08, 0, -1){}
        static color hadamardProduct(color a, color b);

        void setX(double val);
        void setY(double val);
        void setZ(double val);
};

color operator*(const color &a, const color &b);


#endif //RAYTRACER_COLOR_H
