//
// Created by Om K. on 2/21/2023.
//

#include "vec.h"
#include <cmath>

double vec::magnitude() {
    double xSq = (this->x)*(this->x);
    double ySq = (this->y)*(this->y);
    double zSq = (this->z)*(this->z);
    return sqrt(xSq+ySq+zSq);
}

double vec::dotProduct(vec &a, vec &b) {
    return (a.getX()*b.getX())+(a.getY()*b.getY())+(a.getZ()*b.getZ());
}

vec vec::crossProduct(vec &a, vec &b) {

    double x = (a.getY() * b.getZ()) - (a.getZ()* b.getY());
    double y = (a.getZ() * b.getX()) - (a.getX()* b.getZ());
    double z = (a.getX() * b.getY()) - (a.getY()* b.getX());

    return vec(x, y, z);
}

vec vec::unitVector() {
    double mg = this->magnitude();
    double newX = this->getX()/mg;
    double newY = this->getY()/mg;
    double newZ = this->getZ()/mg;
    return vec(newX, newY, newZ);
}




