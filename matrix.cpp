//
// Created by Om K. on 2/22/2023.
//

#include <cstdlib>
#include <iostream>
#include <cfloat>
#include <cmath>
#include "matrix.h"

int matrix::rows() const {
    return rowsVal;
}

int matrix::cols() const {
    return colsVal;
}

double matrix::get(int rows, int cols) const {
    if (rows < 0 || cols < 0 || rows > rowsVal-1 || cols > colsVal - 1) return DBL_MAX;
    return matrixArr[rows][cols];
}

bool matrix::set(int rows, int cols, double value) {
    if (rows < 0 || cols < 0 || rows > rowsVal-1 || cols > colsVal - 1) return false;
    matrixArr[rows][cols] = value;
    return true;
}

matrix matrix::identity(int rowsAndCols) {
    matrix out (rowsAndCols, rowsAndCols);
    for (int i = 0; i < rowsAndCols; ++i) {
        out.set(i, i, 1);
    }
    return out;
}

matrix::matrix(int rows, int cols) {
    matrixArr = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrixArr[i] = new double[cols];
    }
    colsVal = cols;
    rowsVal = rows;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixArr[i][j] = 0.0;
        }
    }
}

matrix* matrix::transpose() {
    matrix* out = new matrix(rowsVal, colsVal);
    for (int i = 0; i < rowsVal; ++i) {
        for (int j = 0; j < colsVal; ++j) {
            out->set(j, i, matrixArr[i][j]);
        }
    }
    return out;
}


matrix* matrix::submatrix(int row, int col) {
    matrix* out = new matrix(this->rowsVal-1, this->colsVal-1);
    for (int i = 0; i < this->rowsVal; ++i) {
        if (i != row) {
            for (int j = 0; j < this -> colsVal; ++j) {
                if (j != col) {
                    int newRow = i;
                    int newCol = j;
                    if (newRow > row) newRow--;
                    if (newCol > col) newCol--;
                    out->set(newRow, newCol, this->get(i, j));
                }
            }
        }
    }
    return out;
}

void matrix::print() const {
    for (int i = 0; i < this->rowsVal; ++i) {
        for (int j = 0; j < colsVal; ++j) {
            std::cout << "| " << this->get(i, j) << " ";
        }
        std::cout << "|\n";
    }
}

double matrix::minor(int row, int col) {
    return submatrix(row, col)->determinant();
}

double matrix::cofactor(int row, int col) {
    return minor(row, col) * pow(-1, row+col);
}

double matrix::determinant() {
    double out = 0;
    if (rowsVal == 2 && colsVal == 2) {
        return matrixArr[0][0]*matrixArr[1][1] - matrixArr[0][1]*matrixArr[1][0];
    }
    else {
        for (int i = 0; i < colsVal; ++i) {
            out += (matrixArr[0][i] * this->cofactor(0, i));
        }
    }

    return out;
}

matrix *matrix::inverse() {
    matrix* out = new matrix(rowsVal, colsVal);
    for (int i = 0; i < rowsVal; ++i) {
        for (int j = 0; j < colsVal; ++j) {
            out->set(i, j, cofactor(i, j));
        }
    }
    out = out-> transpose();
    double det = determinant();
    out = *(out)/det;
    return out;
}


matrix* operator*(matrix &a, matrix &b) {
    if (a.cols() != b.rows()) {
        std::cerr << "Incorrect dimensions for matrix multiplication. a.cols() is " << a.cols()
        << "while b.rows() is " << b.rows() << "These  should be equal. \n";
        exit(1);
    }
    matrix* out = new matrix(a.rows(),  b.cols());
    for (int i = 0; i < a.rows(); ++i) {
        for (int j = 0; j < b.cols(); ++j) {
            double dotProduct = 0;
            for (int k = 0; k < b.rows(); ++k) {
                dotProduct+=a.get(i, k)*b.get(k, j);
            }
            if (std::abs(dotProduct - round(dotProduct)) < 0.000001) dotProduct = round(dotProduct);
            bool success = out->set(i, j, dotProduct);
            if(!success) {
                std::cerr<<"operator*: something wrong happened when setting. \n";
            }
        }
    }
    return out;
}

matrix* operator*(matrix &a, double &d) {
    matrix* out = &a;
    for (int i = 0; i < a.rows(); ++i) {
        for (int j = 0; j < a.cols(); ++j) {
            out->set(i, j, d*a.get(i, j));
        }
    }
    return out;
}

tuple operator*(matrix &a, tuple &t) {
    matrix* tAsMatrix = new matrix(4, 1);
    tAsMatrix->set(0, 0, t.getX());
    tAsMatrix->set(1, 0, t.getY());
    tAsMatrix->set(2, 0, t.getZ());
    tAsMatrix->set(3, 0, (double)t.getType());
    matrix *temp =  a* * tAsMatrix;
    return tuple(temp->get(0, 0), temp->get(1,0), temp->get(2, 0), temp->get(3, 0));
}

matrix* operator/(matrix &a, double &d) {
    double b = 1/d;
    return a*b;
}
