//
// Created by Om K. on 3/13/2023.
//

#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H


#include "material.h"

class object {
    protected:
        int type;
        material objectMaterial;
    public:
        object(int type) : type(type) {
            objectMaterial = material();
            objectMaterial.materialColor = color(1, 0, 0);
        }
        int getType() const {
            return type;
        }
};


#endif //RAYTRACER_OBJECT_H
