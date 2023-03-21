//
// Created by Om K. on 2/21/2023.
//

#ifndef RAYTRACER_POINT_H
#define RAYTRACER_POINT_H


#include "tuple.h"

class point : public tuple {
public:
    point(const tuple& t) : tuple(t.getX(), t.getY(), t.getZ(), 1) {}
    point(double x, double y, double z) : tuple(x, y, z, 1) {}
};


#endif //RAYTRACER_POINT_H
