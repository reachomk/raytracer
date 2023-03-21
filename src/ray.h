//
// Created by Om K. on 3/11/2023.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "vec.h"
#include "point.h"
#include "matrix.h"

class ray {
    private:
        point orig;
        vec dir;
    public:
        ray(point origin, vec direction): orig(origin), dir(direction) {}
        point origin();
        vec direction();
        point locationAt(double time);

        ray transform(matrix transformMatrix);
};


#endif //RAYTRACER_RAY_H
