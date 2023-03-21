//
// Created by Om K. on 3/6/2023.
//

#ifndef RAYTRACER_TRANSFORMATIONS_H
#define RAYTRACER_TRANSFORMATIONS_H


#include "matrix.h"

class transformations {
    public:
        static matrix translation_matrix(double x, double y, double z);
        static matrix scaling_matrix(double x, double y, double z);
        static matrix rotational_x_matrix(double theta); // theta MUST be in radians
        static matrix rotational_y_matrix(double theta); // theta MUST be in radians
        static matrix rotational_z_matrix(double theta); // theta MUST be in radians


};


#endif //RAYTRACER_TRANSFORMATIONS_H
