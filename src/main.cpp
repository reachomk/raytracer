//
// Created by Om K. on 2/21/2023.
//

#include <iostream>
#include <cfloat>
#include "sphere.h"
#include "canvas.h"
#include "transformations.h"


using std::cout;

/* void printCircle() {
    const int height = 200;
    const int width = 200;
    sphere s = sphere(point(0, 0, 0), 1);
    canvas c = canvas(width, height);
    point camera = point(0, 0, -5);
    point wall = point(0, 0, 10);
    color red(1, 0, 0);
    color black(0, 0, 0);


    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            point pixel = wall + point((-width/2.0)+j, (height/2.0)+i, 0);
            vec v = vec(camera, pixel);
            ray r = ray(camera, v.unitVector());
            if (s.intersectionTimes(r)[0] == -DBL_MAX) {
                c.writeColor(black, j, i);
            }
            else{
                c.writeColor(red, j, i);
            }
        }
    }
    c.writeToPPM();
} */


void bookCircle() {
    const int canvasDims = 500;
    sphere s = sphere();
    s.scale(3, 1, 1);
    s.translate(-1, 1, 0);
    canvas c = canvas(canvasDims, canvasDims);
    point camera = point(0, 0, -10);
    point wall = point(0, 0, 0);
    color red(1, 0, 0);
    color black(0, 0, 0);
    double pixelToCoord = 10.0/canvasDims;

    for (int i = 0; i < canvasDims; ++i) {
        for (int j = 0; j < canvasDims; ++j) {
            double world_y = (10.0/2.0) - (pixelToCoord*i);
            double world_x = (-10.0/2.0) + (pixelToCoord*j);
            point pixel = wall + point(world_x, world_y, 0);

            vec direction = pixel-camera;

            ray r = ray(camera, direction.unitVector());
            std::array<double, 2> ints = s.intersectionTimes(r);
            if (ints[0] == -DBL_MAX) {
                c.writeColor(black, j, i);
            }
            else{
                c.writeColor(red, j, i);
            }
        }
    }
    c.writeToPPM();
}

void reflectingCircle() {
    const int canvasDims = 500;
    sphere s = sphere();
    s.scale(3, 3, 3);
    //s.translate(-1, 1, 0);
    canvas c = canvas(canvasDims, canvasDims);
    point camera = point(0, 0, -10);
    point wall = point(0, 0, 0);
    color black(0, 0, 0);
    double pixelToCoord = 10.0/canvasDims;

    light lighting = light(point(-10, 10, -10), color(1, 1, 1));


    for (int i = 0; i < canvasDims; ++i) {
        for (int j = 0; j < canvasDims; ++j) {
            double world_y = (10.0/2.0) - (pixelToCoord*i);
            double world_x = (-10.0/2.0) + (pixelToCoord*j);
            point pixel = wall + point(world_x, world_y, 0);

            vec direction = pixel-camera;

            ray r = ray(camera, direction.unitVector());
            std::array<double, 2> ints = s.intersectionTimes(r);



            if (ints[0] == -DBL_MAX) {
                c.writeColor(black, j, i);
            }
            else{

                double closerTime = std::min(ints[0], ints[1]);
                point pos = r.locationAt(closerTime);
                vec normal = s.normalAt(pos);
                vec camLight = -1*r.direction();

                color sphereColor = s.lighting(lighting, pos, camLight, normal);
                c.writeColor(sphereColor, j, i);
            }
        }
    }
    c.writeToPPM();
}

int main(int argc, char const *argv[])
{
    //bookCircle();

    //TODO: test normal calculation w/ tests on pg 100

    reflectingCircle();

    /*ray r = ray(point(0, 0, 5), vec(0, 0, 1));
    sphere s(point(0, 0, 0), 1);
    std::array<double, 2> pts = s.intersectionTimes(r);
    cout << pts[0] << " " << pts[1];


    ray r = ray(point(1, 2, 3), vec(0, 1, 0));
    ray newRay = r.transform(transformations::scaling_matrix(2, 3, 4));
    cout << newRay.origin().getX() << " " << newRay.origin().getY() << " " << newRay.origin().getZ() << "\n";
    cout << newRay.direction().getX() << " " << newRay.direction().getY() << " " << newRay.direction().getZ() << "\n";
    return 0; */
}
