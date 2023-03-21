//
// Created by Om K. on 2/21/2023.
//

#include "color.h"


color color::hadamardProduct(color a, color b) {
    return a*b;
}

void color::setX(double val) {
    if (val > 1) {
        x = 1.0;
    } else x = val;
}

void color::setY(double val) {
    if (val > 1) {
        y = 1.0;
    } else y = val;
}

void color::setZ(double val) {
    if (val > 1) {
        z = 1.0;
    } else z = val;
}


color operator*(const color &a, const color &b) {
    double newX = a.getX() * b.getX();
    double newY = a.getY() * b.getY();
    double newZ = a.getZ() * b.getZ();
    return color(newX, newY, newZ);
}

