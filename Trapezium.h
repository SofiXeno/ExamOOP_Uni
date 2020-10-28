//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#ifndef EXAM_XENOFONTOVA_TRAPEZIUM_H
#define EXAM_XENOFONTOVA_TRAPEZIUM_H

#include "Segment.h"

using namespace std;

class Trapezium {
public:
    class BadTrapezium;

    Trapezium() {};

    ~Trapezium() {};


    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual double getMidline() const = 0;


    virtual Trapezium *X_AxesRotation() const = 0;

    virtual Trapezium *Y_AxesRotation() const = 0;

    virtual Trapezium *OriginRotation(double &) const = 0;

    virtual const Point A() const = 0;

    virtual const Point B() const = 0;

    virtual const Point C() const = 0;

    virtual const Point D() const = 0;


    virtual const Segment AB() const = 0;

    virtual const Segment BC() const = 0;

    virtual const Segment CD() const = 0;

    virtual const Segment AD() const = 0;


};

ostream &operator<<(ostream &, const Trapezium &);

class  Trapezium::BadTrapezium
{
public:
    string _msg;
    BadTrapezium(string msg) : _msg(msg){
        cout<<msg<<endl;
    };
};
#endif //EXAM_XENOFONTOVA_TRAPEZIUM_H
