//
// Created by Om K. on 3/11/2023.
//

#include "sphere.h"
#include "vec.h"
#include "transformations.h"
#include <cfloat>
#include <cmath>
#include <iostream>



// https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
array<double, 2> sphere::intersectionTimes(ray rayToSphere) {
    ray r = rayToSphere.transform(transformMatrix);

    array<double, 2> out = {-DBL_MAX, -DBL_MAX};
    vec origin = vec(r.origin());
    vec direction = r.direction();
    double a = vec::dotProduct(direction, direction);
    double b = 2*(vec::dotProduct(direction, origin));
    double c = vec::dotProduct(origin, origin) - 1;

    double discriminant =  (b*b)-4*a*c;
  //  std::cout << a << "\n";
    if(discriminant < 0) {
        return out;
    }
  //  std::cout << "red\n";
    double sol1 = (-b + sqrt(discriminant))/(2*a);
    double sol2 = (-b - sqrt(discriminant))/(2*a);
    out = {sol1, sol2};
    return out;
}

matrix sphere::getTransformMatrix() {
    return transformMatrix;
}

void sphere::translate(double x, double y, double z) {
    matrix transform = transformations::translation_matrix(x, y, z);
    transformMatrix = *(transform*transformMatrix);
}

void sphere::scale(double x, double y, double z) {
    matrix transform = transformations::scaling_matrix(x, y, z);
    transformMatrix = *(*(transform.inverse())*transformMatrix);
}

vec sphere::normalAt(point& p) {
    point pointOnUnitSphere = (*(transformMatrix.inverse())*p);
    vec unitSphereNormal = pointOnUnitSphere-point(0,0,0);
    vec translatedNormal = *(transformMatrix.inverse()->transpose()) * unitSphereNormal;
    return translatedNormal.unitVector();
}

vec sphere::reflectionVector(vec& lightVec, vec& normal) {
    return lightVec-normal*2*vec::dotProduct(lightVec, normal);
}

color sphere::lighting(light &lighting, point& p, vec& cameraLight, vec& normal) {
    color effectiveColor = objectMaterial.materialColor*lighting.getIntensity();
    vec lightVector = vec(lighting.getPosition()-p).unitVector();
    color ambient = effectiveColor*objectMaterial.ambient;
    double cosLightVecAndNormal = vec::dotProduct(lightVector, normal);
    color black = color(0, 0, 0);
    color diffuse, specular;
    if (cosLightVecAndNormal < 0) {
         diffuse = black;
         specular = black;
    }
    else {
        diffuse = cosLightVecAndNormal*objectMaterial.materialColor*effectiveColor;
        vec negLightVec = -1*lightVector;
        vec reflectVector = reflectionVector(negLightVec, normal);
        double cosReflectAndCamera = vec::dotProduct(reflectVector, cameraLight);
        if (cosReflectAndCamera < 0) {
            specular = black;
        }
        else {
            double factor = pow(cosReflectAndCamera, objectMaterial.shininess);
            specular = lighting.getIntensity()*objectMaterial.specular*factor;
        }
    }

    color out = ambient+specular+diffuse;

    if (out.getX() > 1) out.setX(1);
    if (out.getY() > 1) out.setY(1);
    if (out.getZ() > 1) out.setZ(1);

   /* std::string outString = std::to_string(out.getX()) + " " + std::to_string(out.getY()) + " " + std::to_string(out.getZ()) + "\n";
    if (out.getX() > 1 || out.getY() > 1 || out.getZ() > 1) {
        std::cout << outString;
    } */

    return out;
}
