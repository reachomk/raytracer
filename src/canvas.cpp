//
// Created by Om K. on 2/21/2023.
//

#include "canvas.h"
#include "color.h"
#include <string>
#include <fstream>
#include <iostream>

using std::cout;
using std::ofstream;
using std::string;
using std::to_string;
using std::cerr;

bool canvas::writeColor(color c, int widthAt, int heightAt) {
    if (widthAt >= 0 && widthAt < this->width && heightAt >= 0 && heightAt < this->height) {
        pixelCanvas[heightAt][widthAt] = c;
        return true;
    } else {
     //   cerr << "Out of bounds error in writeColor: " << widthAt << " " << heightAt << "\n";
        return false;
    }
}

color canvas::pixelAt(int widthAt, int heightAt) {
    if (widthAt >= 0 && widthAt < this->width && heightAt >= 0 && heightAt < this->height) {
        return pixelCanvas[this->height - heightAt][widthAt];
    } else {
        cerr << "Out of bounds error in pixelAt: " << widthAt << " " << heightAt << "\n";
        exit(1);
    }
}

canvas::canvas(const int widthInput, const int heightInput) {

    pixelCanvas = new color*[heightInput];
    for (int i = 0; i < heightInput; ++i) {
        pixelCanvas[i] = new color[widthInput];
    }
    width = widthInput;
    height = heightInput;
}

void canvas::writeToPPM() {
    cerr << "Writing image...\n";
    string *fileText = new string("P3\n");
	*fileText += to_string(this->width) + " " + to_string(this->height) + "\n";
	*fileText += "255\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; ++j) {
            color c = pixelCanvas[i][j];
            *fileText += to_string((int) (255.999*c.getX())) + " "
                    + to_string((int) (255.99*c.getY())) + " "
                    + to_string((int) (255.99*c.getZ())) + "\n";
        }
    }

    ofstream outputFile("img.ppm");
    outputFile << *fileText;
    outputFile.close();
}

int canvas::getHeight() const {
    return this->height;
}

int canvas::getWidth() const {
    return this->width;
}
