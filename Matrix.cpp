//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#include "Matrix.h"
#include <iostream>

int Matrix::freeID = 1;

Matrix::Matrix(double _x11, double _x12, double _x21, double _x22) : MatrixID(freeID++), _x11(_x11), _x12(_x12),
                                                                     _x21(_x21), _x22(_x22) {

#ifndef NDEBUG
    cout << "Matrix number " << MatrixID << ": created \n" << *this << endl;
#endif

}

Matrix::Matrix(const Matrix &matrix) : MatrixID(freeID++), _x11(matrix._x11), _x12(matrix._x12),
                                       _x21(matrix._x21), _x22(matrix._x22) {
#ifndef NDEBUG
    cout << "Matrix number " << MatrixID << ": was copied from Matrix number " << matrix.MatrixID << "\n" << *this
         << endl;
#endif
}

Matrix::~Matrix() {
#ifndef NDEBUG
    cout << "Matrix number " << MatrixID << " \n" << *this << ": was deleted " << endl;
#endif
}

const Matrix Matrix::addition(Matrix &F) {
    return Matrix(x11() + F.x11(), x12() + F.x12(), x21() + F.x21(), x22() + F.x22());
}

const Matrix Matrix::subtraction(Matrix &F) {
    return Matrix(x11() - F.x11(), x12() - F.x12(), x21() - F.x21(), x22() - F.x22());
}

const Matrix Matrix::multiplication(Matrix &F) {
    double new_11 = x11() * F.x11() + x12() * F.x21();
    double new_12 = x11() * F.x12() + x12() * F.x22();
    double new_21 = x21() * F.x11() + x22() * F.x21();
    double new_22 = x21() * F.x12() + x22() * F.x22();

    return Matrix(new_11, new_12, new_21, new_22);
}


ostream &operator<<(ostream &os, const Matrix &matrix) {
    os << "| " << matrix.x11() << "  " << matrix.x12() << " |\n";
    os << "| " << matrix.x21() << "  " << matrix.x22() << " |\n";
    return os;

}
