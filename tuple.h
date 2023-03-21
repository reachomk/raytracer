//
// Created by Om K. on 2/21/2023.
//

#ifndef TUPLE_H
#define TUPLE_H

class tuple {

    protected:
        int type; 	// initialized to -1 for color, 0 for vec, 1 for point
        double x;
        double y;
        double z;
    public:
        tuple(double x, double y, double z, int type);
        tuple(tuple& t): x(t.getX()), y(t.getY()), z(t.getZ()), type(t.getType()){}
        int getType() const;
        double getX() const;
        double getY() const;
        double getZ() const;

};


tuple operator+(const tuple &a, const tuple &b);
tuple operator-(const tuple &a, const tuple &b);
tuple operator*(const tuple &a, double multiplier);
tuple operator*(double multiplier, const tuple &a);
tuple operator/(tuple &a, double denominator);


#endif