//
// Created by Om K. on 2/21/2023.
//

#ifndef RAYTRACER_CANVAS_H
#define RAYTRACER_CANVAS_H


#include "color.h"

class canvas {
    color **pixelCanvas;
    int width, height;
    public:
        canvas(int width, int height);
        color pixelAt(int widthAt, int heightAt);
        bool writeColor(color c, int widthAt, int heightAt);
        void writeToPPM();
        int getHeight() const;
        int getWidth() const;
};


#endif //RAYTRACER_CANVAS_H
