//
// Created by Om K. on 2/21/2023.
//

// tests a variety of matrix functions including the constructor, multiplication, and inversion.

#include <iostream>
#include "matrix.h"

using std::cout;


int main(int argc, char const *argv[])
{
    int x[4][4] = {{9, 3, 0 ,9},
                   {-5, -2, -6, -3},
                   {-4, 9, 6, 4},
                   {-7, 6, 6, 2}};

    auto a = matrix(4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a.set(i, j, x[i][j]);
        }
    }

    int y[4][4] = {{8, 2, 2 ,2},
                   {3, -1, 7, 0},
                   {7, 0, 5, 4},
                   {6, -2, 0, 5}};

    auto b =  matrix(4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            b.set(i, j, y[i][j]);
        }
    }


    matrix c = *(a*b);
    matrix invb = *(b.inverse());
    matrix* out = c*invb;
    cout<<"\n";
    out -> print();
    cout<<"\n";
    a.print();

    matrix inva = *(a.inverse());
    inva.print();

    matrix iden = *(a*inva);
    iden.print();
    return 0;
}
