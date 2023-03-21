//
// Created by Om K. on 2/21/2023.
//

// tests the canvas setup and tuple implementations by simulating projectile motion

#include <iostream>
#include "tuple.h"
#include "point.h"
#include "vec.h"
#include "canvas.h"

using std::cout;

const color red = color(1,0,0);

struct obj {
    point pos;
    vec velocity;
};

obj tick(point pos, vec v, vec g, vec wr) {
    pos = pos + v;
    v = (v + g) + wr;
    obj out = {pos, v};
    return out;
}

void projectileMotion(canvas imgCanvas) {
    point position(0, 1, 0);
    vec velocity( 1, 1.8, 0);
    vec gravity(0, -0.15, 0);
    vec windResistance(-0.07, 0, 0);
    while(position.getY() > 0) {
        obj object = tick(position, velocity.unitVector()*9, gravity, windResistance);
        position = object.pos;
        velocity = object.velocity;
        bool success = imgCanvas.writeColor(red, (int) position.getX(), (int)position.getY());
        if(!success) break;
    }
    imgCanvas.writeToPPM();
} 


int main(int argc, char const *argv[])
{
    canvas imgCanvas = canvas(1920, 1080);
    projectileMotion(imgCanvas);

    return 0;
}
