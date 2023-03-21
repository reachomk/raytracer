//
// Created by Om K. on 3/14/2023.
//

#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H


#include "object.h"

class intersection {
    object obj;
    double time;
    public:
        intersection(object o, double t) : obj(o), time(t) {}
        double getTime() const {
            return time;
        }
        object getObject() {
            return obj;
        }
};


#endif //RAYTRACER_INTERSECTION_H
