//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#ifndef EXAM_XENOFONTOVA_MATRIX_H
#define EXAM_XENOFONTOVA_MATRIX_H


#include <iostream>



#pragma once

using namespace std;

class Matrix {
public:

//    | _x11  _x21 |
//    | _x21  _x22 |

    Matrix(double _x11 = 0, double _x12 = 0, double _x21 = 0, double _x22 = 0);

    Matrix(const Matrix &);

    ~Matrix();

    const Matrix addition( Matrix &);

    const Matrix multiplication( Matrix &);

    const Matrix subtraction( Matrix &);

    double & x11(){
        return _x11;
    }

    double & x12(){
        return _x12;
    }

    const double &x11() const{
        return _x11;
    }

    const double &x12() const{
        return _x12;
    }

    double &x21(){
        return _x21;
    }

    double &x22(){
        return _x22;
    }

    const double &x21() const{
        return _x21;
    }

    const double &x22() const{
        return _x22;
    }



    const int getID() const {
        return MatrixID;
    }

private:
    double _x11, _x12, _x21, _x22;
    static int freeID;
    const int MatrixID;

};

ostream &operator<<(ostream &, const Matrix &);


#endif //EXAM_XENOFONTOVA_MATRIX_H
