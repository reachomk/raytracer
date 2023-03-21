//
// Created by Om K. on 3/6/2023.
//

#include "transformations.h"
#include <cmath>

matrix transformations::translation_matrix(double x, double y, double z) {
    matrix out = matrix::identity(4);
    out.set(0, 3, x);
    out.set(1, 3, y);
    out.set(2, 3, z);
    return out;
}

matrix transformations::scaling_matrix(double x, double y, double z) {
    matrix out = matrix::identity(4);
    out.set(0, 0, x);
    out.set(1, 1, y);
    out.set(2, 2, z);
    return out;
}

matrix transformations::rotational_x_matrix(double theta) {
    matrix out = matrix::identity(4);
    out.set(1, 1, cos(theta));
    out.set(2, 1, sin(theta));
    out.set(1, 2, -sin(theta));
    out.set(2, 2, cos(theta));
    return out;
}

matrix transformations::rotational_y_matrix(double theta) {
    matrix out = matrix::identity(4);
    out.set(0, 0, cos(theta));
    out.set(0, 2, sin(theta));
    out.set(2, 0, -sin(theta));
    out.set(2, 2, cos(theta));
    return out;
}

matrix transformations::rotational_z_matrix(double theta) {
    matrix out = matrix::identity(4);
    out.set(0, 0, cos(theta));
    out.set(1, 0, sin(theta));
    out.set(0, 1, -sin(theta));
    out.set(1, 1, cos(theta));
    return out;
}


