//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#ifndef EXAM_XENOFONTOVA_TRAPEZIUMBASE_H
#define EXAM_XENOFONTOVA_TRAPEZIUMBASE_H

//             I have realized trapezium where always BC//AD and AB not // CD and
//             the Area of ABCD != 0 (the condition that the shape is trapezium)


//         B__________C                 B___________C
//        /            \                |           \
//      /               \               |            \
//    /                  \              |             \
//  /                     \             |              \
// A_______________________D            A_______________D

//
//                     A             Also my trapezium can be turned
//                   /   \
//                  /     \
//                 /       \
//                /         B
//               /         /
//              /         /
//             /         /
//            D_________C

#include"Trapezium.h"
#include "TrapeziumAxes.h"
using namespace std;

class TrapeziumAxes;
class TrapeziumBase : public Trapezium {
public:


    TrapeziumBase(const Segment &, const Segment &);

    TrapeziumBase(const TrapeziumAxes &);

    ~TrapeziumBase();

    double getArea() const override {
        return getMidline() * getH();
    }

    double getPerimeter() const override {
        return AB().length() + BC().length() + CD().length() + AD().length();
    }

    double getMidline() const override {
        return (_BC.length() + _AD.length()) / 2;
    }

    TrapeziumBase *X_AxesRotation() const override;

    TrapeziumBase *Y_AxesRotation() const override;

    TrapeziumBase *OriginRotation(double &) const override;


    const Point A() const override {
        return _AD.start();
    }

    const Point B() const override {
        return _BC.start();
    }

    const Point C() const override {
        return _BC.end();
    }

    const Point D() const override {
        return _AD.end();
    }


    const Segment AB() const override {
        return Segment(_AD.start(), _BC.start());
    }

    const Segment BC() const override {
        return _BC;
    }

    const Segment CD() const override {
        return Segment(_BC.end(), _AD.end());
    }

    const Segment AD() const override {
        return _AD;
    }

    double getH() const {
        return _BC.distance(_AD.start());
    }

    const int getID() const {
        return TrapeziumBaseID;
    }

private:
    Segment _BC, _AD;
    static int freeID;

    const int TrapeziumBaseID;
};

ostream &operator<<(ostream &, const TrapeziumBase &);


#endif //EXAM_XENOFONTOVA_TRAPEZIUMBASE_H
