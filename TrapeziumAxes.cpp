//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#include "TrapeziumAxes.h"
#include "TrapeziumBase.h"
#include <cmath>

using namespace std;


int TrapeziumAxes::freeID = 1;

TrapeziumAxes::TrapeziumAxes(const Point &A, const Point &B, const Point &C, const Point &D) : TrapeziumAxesID(
        freeID++), _A(A), _B(B), _C(C), _D(D) {
    double k1 = koefK(_B.x(),_B.y(), _C.x(),_C.y());
    double k2 = koefK(_A.x(),_A.y(), _D.x(),_D.y());
    double n_koef = (_A.x() - _D.x()) / (_C.x() - _B.x());

    if ((k1 != k2) && (n_koef<0)) throw Trapezium::BadTrapezium("Error! Object is not trapezium");
#ifndef NDEBUG
    cout << "TrapeziumAxes(where BC//AD) number " << getID() << ": created from Points --> " << *this << endl;
#endif

}

TrapeziumAxes::TrapeziumAxes(const double &ax, const double &ay, const double &bx, const double &by, const double &cx,
                             const double &cy, const double &dx, const double &dy) : TrapeziumAxesID(
        freeID++), _A(ax, ay), _B(bx, by), _C(cx, cy), _D(dx,dy) {

    double k1 = koefK(_B, _C);
    double k2 = koefK(_A, _D);
    double n_koef = (_A.x() - _D.x()) / (_C.x() - _B.x());

    if ((k1 != k2) && (n_koef<0)) throw Trapezium::BadTrapezium("Error! Object is not trapezium");
#ifndef NDEBUG
    cout << "TrapeziumAxes(where BC//AD) number " << getID() << ": created from coordinates  --> " << *this << endl;
#endif
}

TrapeziumAxes::TrapeziumAxes(const TrapeziumBase &tbase) : TrapeziumAxesID(
        freeID++), _A(tbase.A()), _B(tbase.B()), _C(tbase.C()), _D(tbase.D()) {

    double k1 = koefK(_B, _C);
    double k2 = koefK(_A, _D);
    double n_koef = (_A.x() - _D.x()) / (_C.x() - _B.x());

    if ((k1 != k2) && (n_koef<0)) throw Trapezium::BadTrapezium("Error! Object is not trapezium");
#ifndef NDEBUG
    cout << "TrapeziumAxes(where BC//AD) number " << getID()  <<" --> " <<*this<< ": converted from TrapeziumBase" << endl;
#endif

}

TrapeziumAxes::~TrapeziumAxes() {
#ifndef NDEBUG
    cout << "TrapeziumAxes(where BC//AD) number " << getID() << " " << ": was deleted " << endl;
#endif
}

double TrapeziumAxes::getMidline() const {

    double XmidAB = (A().x() + B().x()) / 2;
    double YmidAB = (A().y() + B().y()) / 2;

    double XmidCD = (C().x() + D().x()) / 2;
    double YmidCD = (C().y() + D().y()) / 2;

    return sqrt(pow((XmidAB - XmidCD), 2) + pow((YmidAB - YmidCD), 2));;
}

TrapeziumAxes *TrapeziumAxes::X_AxesRotation() const {

    Point newA = ::X_AxesRotation(A());
    Point newB = ::X_AxesRotation(B());
    Point newC = ::X_AxesRotation(C());
    Point newD = ::X_AxesRotation(D());

    return new TrapeziumAxes(newA, newB, newC, newD);
}

TrapeziumAxes *TrapeziumAxes::Y_AxesRotation() const {

    Point newA = ::Y_AxesRotation(A());
    Point newB = ::Y_AxesRotation(B());
    Point newC = ::Y_AxesRotation(C());
    Point newD = ::Y_AxesRotation(D());

    return new TrapeziumAxes(newA, newB, newC, newD);
}

TrapeziumAxes *TrapeziumAxes::OriginRotation(double &alpha) const {
    Point newA = ::OriginRotation(A(), alpha);
    Point newB = ::OriginRotation(B(), alpha);
    Point newC = ::OriginRotation(C(), alpha);
    Point newD = ::OriginRotation(D(), alpha);

    return new TrapeziumAxes(newA, newB, newC, newD);
}


ostream &operator<<(ostream &os, const TrapeziumAxes &t_axes) {
    os << " with coords A = " << t_axes.A() << "; B = " << t_axes.B() << "; C = " << t_axes.C() << "; D = "
       << t_axes.D() << "\n";
    os << "TrapeziumAxes number " << t_axes.getID() <<" --> S = " << t_axes.getArea() << "; P = " << t_axes.getPerimeter() << "; Midline = "
       << t_axes.getMidline() << "; H = " << t_axes.getH();
    return os;

}
