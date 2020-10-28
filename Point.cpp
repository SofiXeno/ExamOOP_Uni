


#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;



//*******************************************

//Every point posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a point created or resp. deleted

//Developed by Софія Ксенофонтова

//on 2020-01-26.

//Version 1.0

//*******************************************


int Point::freeID = 1;

Point::Point(double x, double y) :
        _x(x), _y(y), pointID(freeID++) {
#ifndef NDEBUG
   //  cout << "Point number " << pointID << ": created  " << *this << endl;
#endif
};


Point::Point(const Point &p) :
        _x(p._x),
        _y(p._y),
        pointID(freeID++) {
#ifndef NDEBUG
    // cout << "Point number " << pointID << ": was copied from Point � "<< p.pointID<< " " <<*this << endl;
#endif

};


Point::~Point() {
#ifndef NDEBUG
   //  cout << "Point number " << pointID <<" "<< *this<< ": was deleted " << endl;
#endif
};


Point &Point::operator=(const Point &p) {
    if (this == &p)
        return *this;

    _x = p._x;
    _y = p._y;

    return *this;
}

double &Point::x() {
    return _x;
};


double &Point::y() {
    return _y;
};


const double &Point::x() const {
    return _x;
}

const double &Point::y() const {
    return _y;
}

const int Point::getID() const {
    return pointID;
}


ostream &operator<<(ostream &os, const Point &u) {
    os << "Point (" << u.x() << ',' << u.y() << ')';
    return os;
}


const Point operator+(const Point &u, const Point &v) {
    return Point(u.x() + v.x(), u.y() + v.y());
}


Point &operator+=(Point &u, const Point &v) {
    u.x() = u.x() + v.x();
    u.y() = u.y() + v.y();
    return u;

}

bool operator==(const Point &u, const Point &v) {
    return (u.x() == v.x()) && (u.y() == v.y());
}

bool operator!=(const Point &u, const Point &v) {
    return !((u.x() == v.x()) && (u.y() == v.y()));
}

const Point X_AxesRotation(const Point &p) {
    return Point(p.x(), -p.y());
}

const Point Y_AxesRotation(const Point &p) {
    return Point(-p.x(), p.y());
}

const Point OriginRotation(const Point &p, double &alpha) {

    double _newX = p.x() * cos(alpha) - p.y() * sin(alpha);
    double _newY = p.x() * sin(alpha) + p.y() * cos(alpha);

    return Point(_newX, _newY);
}

//const double koefK(const Point &p1, const Point &p2) {
//    return -((p1.y()-p2.y())/(p2.x()-p1.x()));
//};

const double koefK(const double &x1, const double &y1, const double &x2, const double &y2) {
    return ((y2-y1)/(x2-x1));
}

