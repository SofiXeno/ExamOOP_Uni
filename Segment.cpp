//
// Created by Софія Ксенофонтова  on 2020-01-29.
//



#include "Segment.h"
#include <cmath>
#include <iostream>
using namespace std;



int Segment::_freeID = 1;

Segment::Segment(const double x1, const double y1, const double x2, const double y2) :
        _a(x1, y1), _b(x2, y2), _myId(_freeID++) {
#ifndef NDEBUG
    // cout << "Segment number " << _myId << ": created  " << *this << endl;
#endif
}


Segment::Segment(const Point &start, const Point &end) :
        _a(start), _b(end), _myId(_freeID++) {
#ifndef NDEBUG
    // cout << "Segment number " << _myId << ": created " << *this << endl;
#endif
}


Segment::Segment(const Segment &segment) :
        _a(segment._a), _b(segment._b), _myId(_freeID++) {
#ifndef NDEBUG
    // cout << "Segment number " << _myId << ": was copied from Segment � " << segment._myId << " " << *this << endl;
#endif
}


Segment::~Segment() {
#ifndef NDEBUG
    // cout << "Segment number " << _myId << " " << *this << ": was deleted " << endl;
#endif
};


Segment &Segment::operator=(const Segment &segment) {
    if (this == &segment)
        return *this;

    _a = segment._a;
    _b = segment._b;

    return *this;
}


double Segment::length() const {
    return sqrt(pow((_a.x() - _b.x()), 2) + pow((_a.y() - _b.y()), 2));
}


double Segment::distance(const Point &p) const {

    return abs(
            (_b.y() - _a.y()) * p.x() - (_b.x() - _a.x()) * p.y() + _b.x() * _a.y() - _b.y() * _a.x()
    ) / length();
}


ostream &operator<<(ostream &os, const Segment &segment) {
    os << "Segment with coordinates" << "( " << segment.start() << " ; " << segment.end() << " )";
    return os;
}


double distance(const Segment &segment, const Point &p) {
    return abs(
            (segment.endY() - segment.startY()) * p.x() - (segment.endX() - segment.startX()) * p.y() +
            segment.endX() * segment.startY() - segment.endY() * segment.startX()
    ) / segment.length();
}

const Segment OriginRotationSegment(const Segment &s, double &alpha) {

    Point _newStart= OriginRotation(s.start(),alpha);
    Point _newEnd= OriginRotation(s.end(),alpha);

    return Segment(_newStart,_newEnd);
}

const Segment X_AxesRotationSegment(const Segment &s) {
    return Segment(s.startX(), -s.startY(), s.endX(), -s.endY());
}

const Segment Y_AxesRotationSegment(const Segment &s) {
    return Segment(-s.startX(), s.startY(), -s.endX(), s.endY());
}

//const double koefK(const double &x1, const double &y1, const double &x2, const double &y2) {
//    return -((y1-y2)/(x2-x1));
//}

const double koefK(const Point &p1, const Point &p2) {
    return (-(p1.y()-p2.y())/(p2.x()-p1.x()));
};
