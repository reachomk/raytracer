//
// Created by Om K. on 2/21/2023.
//

#include "tuple.h"

tuple::tuple(double x, double y, double z, int type) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->type = type;
}

int tuple::getType() const {
	return type;
}

double tuple::getX() const {
	return x;
}

double tuple::getY() const {
	return y;
}

double tuple::getZ() const {
	return z;
}

tuple operator+(const tuple &a, const tuple &b) {
	double newX = a.getX() + b.getX();
	double newY = a.getY() + b.getY();
	double newZ = a.getZ() + b.getZ();
	int newType = a.getType() + b.getType();
	return tuple(newX, newY, newZ, newType);
}

tuple operator-(const tuple &a, const tuple &b) {
	double newX = a.getX() - b.getX();
	double newY = a.getY() - b.getY();
	double newZ = a.getZ() - b.getZ();
	int newType = a.getType() - b.getType();
	return tuple(newX, newY, newZ, newType);
}


tuple operator*(const tuple &a, double multiplier) {
	double newX = a.getX() * multiplier;
	double newY = a.getY() * multiplier;
	double newZ = a.getZ() * multiplier;
	int newType = a.getType() * multiplier;
	return tuple(newX, newY, newZ, newType);
}

tuple operator*(double multiplier, const tuple &a) {
    return a*multiplier;
}

tuple operator/(const tuple &a, double denominator) {
	double newX = a.getX() / denominator;
	double newY = a.getY() / denominator;
	double newZ = a.getZ() / denominator;
	int newType = a.getType() / denominator;
	return tuple(newX, newY, newZ, newType);
}



