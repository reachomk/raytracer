//
// Created by Om K. on 2/22/2023.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H


#include "tuple.h"

class matrix {
    double** matrixArr;
    int rowsVal, colsVal;
    public:
        matrix(int rows, int cols);
        static matrix identity(int rowsAndCols);
        int rows() const;
        int cols() const;
        double get(int rows, int cols) const;
        bool set(int rows, int cols, double value);
        matrix* transpose();
        matrix* submatrix(int row, int col);
        void print() const;
        double minor(int row, int col);
        double cofactor(int row, int col);
        double determinant();
        matrix* inverse();
};

matrix* operator*(matrix& a, matrix& b);
matrix* operator*(matrix& a, double& d);
tuple operator*(matrix& a, tuple& t);
matrix* operator/(matrix&a, double& d);

#endif //RAYTRACER_MATRIX_H
