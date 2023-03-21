//
// Created by reach on 3/17/2023.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H


#include "point.h"
#include "color.h"

class light {
    point position;
    color intensity;
    public:
        light(point p, color i) : position(p), intensity(i) {}
        color getIntensity() {
            return intensity;
        }
        point getPosition() {
            return position;
        }
};


#endif //RAYTRACER_LIGHT_H
