//
// Created by Om K. on 3/11/2023.
//

#include "ray.h"

point ray::locationAt(double time) {
    return orig + (time * dir);
}

point ray::origin() {
    return orig;
}

vec ray::direction() {
    return dir;
}

ray ray::transform(matrix transformMatrix) {
    point newPoint = (transformMatrix*orig);
    point newDir = (transformMatrix*dir);
    return ray(newPoint, newDir);
}
