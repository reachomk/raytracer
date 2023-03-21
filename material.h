//
// Created by reach on 3/17/2023.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "color.h"

class material {
    public:
        color materialColor;
        double ambient, diffuse, specular, shininess;
        material() {
            materialColor = color(1, 1 ,1);
            ambient = 0.1;
            diffuse = 0.9;
            specular = 0.9;
            shininess = 200;
        }

};


#endif //RAYTRACER_MATERIAL_H
