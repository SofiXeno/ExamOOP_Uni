//
// Created by Софія Ксенофонтова  on 2020-04-11.
//

#include "TrapeziumBase.h"
#include <cmath>
#include <stdexcept>


#include <iostream>

using namespace std;


int TrapeziumBase::freeID = 1;

TrapeziumBase::TrapeziumBase(const Segment &BC, const Segment &AD) : TrapeziumBaseID(freeID++), _AD(AD), _BC(BC) {
    double k1 = koefK(_BC.start(), _BC.end());
    double k2 = koefK(_AD.start(), _AD.end());
    double n_koef = (_AD.startX() - _AD.endX()) / (_BC.endX() - _BC.startX());

    if ((k1 != k2) && (n_koef<0)) throw Trapezium::BadTrapezium("Error! Object is not trapezium");
#ifndef NDEBUG
    cout << "TrapeziumBase(where BC//AD) number " << getID() << ": created from Segments --> " << *this << endl;
#endif

}

TrapeziumBase::TrapeziumBase(const TrapeziumAxes &t_axes) : TrapeziumBaseID(freeID++), _AD(t_axes.A(), t_axes.D()),
                                                            _BC(t_axes.B(), t_axes.C()) {
    double k1 = koefK(_BC.start(), _BC.end());
    double k2 = koefK(_AD.start(), _AD.end());
    double n_koef = (_AD.startX() - _AD.endX()) / (_BC.endX() - _BC.startX());

    if ((k1 != k2) && (n_koef<0)) throw Trapezium::BadTrapezium("Error! Object is not trapezium");
#ifndef NDEBUG
    cout << "TrapeziumBase(where BC//AD) number " << getID() << " --> " << *this << ": converted from TrapeziumAxes"
         << endl;
#endif
}

TrapeziumBase::~TrapeziumBase() {
#ifndef NDEBUG
    cout << "TrapeziumBase(where BC//AD) number " << getID() << " " << ": was deleted " << endl;
#endif
}

TrapeziumBase *TrapeziumBase::X_AxesRotation() const {
    Segment newBC = X_AxesRotationSegment(BC());
    Segment newAD = X_AxesRotationSegment(AD());

    return new TrapeziumBase(newBC, newAD);
}

TrapeziumBase *TrapeziumBase::Y_AxesRotation() const {
    Segment newBC = Y_AxesRotationSegment(BC());
    Segment newAD = Y_AxesRotationSegment(AD());

    return new TrapeziumBase(newBC, newAD);
}

TrapeziumBase *TrapeziumBase::OriginRotation(double &alpha) const {
    Segment newBC = OriginRotationSegment(BC(), alpha);
    Segment newAD = OriginRotationSegment(AD(), alpha);
    return new TrapeziumBase(newBC, newAD);

}


ostream &operator<<(ostream &os, const TrapeziumBase &tbase) {
    os << " with bases BC = " << tbase.BC() << "; AD = " << tbase.AD() << "\n";
    os << "TrapeziumBase number " << tbase.getID() <<" --> S = " << tbase.getArea() << "; P = " << tbase.getPerimeter() << "; Midline = "
       << tbase.getMidline() << "; H = " << tbase.getH();
    return os;

}
