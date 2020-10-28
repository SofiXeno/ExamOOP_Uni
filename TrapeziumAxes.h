//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#ifndef EXAM_XENOFONTOVA_TRAPEZIUMAXES_H
#define EXAM_XENOFONTOVA_TRAPEZIUMAXES_H

#include "Trapezium.h"

#include "TrapeziumBase.h"


using namespace std;
class TrapeziumBase;
class TrapeziumAxes : public Trapezium {
public:

    TrapeziumAxes(const Point &, const Point &, const Point &, const Point &);

    TrapeziumAxes(const double &, const double &, const double &, const double &, const double &, const double &,
                  const double &, const double &);

   TrapeziumAxes(const TrapeziumBase &);

    ~TrapeziumAxes();

    double getArea() const override {
        return getMidline() * getH();
    }

    double getPerimeter() const override {
        return AB().length() + BC().length() + CD().length() + AD().length();
    }

    double getMidline() const override;

    TrapeziumAxes *X_AxesRotation() const override;

    TrapeziumAxes *Y_AxesRotation() const override;

    TrapeziumAxes *OriginRotation(double &) const override;


    const Point A() const override {
        return _A;
    }

    const Point B() const override {
        return _B;
    }

    const Point C() const override {
        return _C;
    }

    const Point D() const override {
        return _D;
    }


    const Segment AB() const override {
        return Segment(_A, _B);
    }

    const Segment BC() const override {
        return Segment(_B, _C);
    }

    const Segment CD() const override {
        return Segment(_C, _D);
    }

    const Segment AD() const override {
        return Segment(_A, _D);
    }

    double getH() const {
        return BC().distance(AD().start());
    }

    const int getID() const {
        return TrapeziumAxesID;
    }

private:
    Point _A, _B, _C, _D;
    static int freeID;

    const int TrapeziumAxesID;
};

ostream &operator<<(ostream &, const TrapeziumAxes &);


#endif //EXAM_XENOFONTOVA_TRAPEZIUMAXES_H
