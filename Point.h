//
// Created by Софія Ксенофонтова  on 2020-01-26.
//

#ifndef _POINT_H_
#define _POINT_H_



#include <iostream>
using namespace std;
#pragma once

class Point {

private:

    static int freeID;

    const int pointID;

    double _x;

    double _y;

public:

    Point(double x = 0, double y = 0);

    Point(const Point &);

    ~Point();

    Point &operator=(const Point &);

    double &x();

    double &y();

    const double &x() const;

    const double &y() const;


    const int getID() const;

    static int amount() {
        return freeID;
    }

};

const Point X_AxesRotation(const Point &);

const Point Y_AxesRotation(const Point &);

const Point OriginRotation(const Point &, double &);

const double koefK(const double &, const double &, const double &, const double &);

ostream &operator<<(ostream &, const Point &);

const Point operator+(const Point &u, const Point &v);

Point &operator+=(Point &, const Point &);

bool operator==(const Point &u, const Point &v);

bool operator!=(const Point &u, const Point &v);


#endif