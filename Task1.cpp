//
// Created by Софія Ксенофонтова  on 2020-04-13.
//

#include "Task1.h"

#include <cmath>
#include <iostream>




int Register::freeID = 1;

void Register::swap(RegisterSelector rs1, RegisterSelector rs2) {

    if (rs1 != rs2) {
        unsigned int temp = get(*this, rs1);
        set(*this, rs1, get(*this, rs2));
        set(*this, rs2, temp);
    }

}

Register::Register(const unsigned int a, const unsigned int b, const unsigned int x, const unsigned int y) : RegisterID(
        freeID++), _a(a), _b(b), _x(x), _y(y) {

#ifndef NDEBUG
    cout << "Register number " << getID() << ": created  " << *this << endl;
#endif

}

Register::~Register() {
#ifndef NDEBUG
    cout << "Register number " << getID() << " " << *this << ": was deleted " << endl;
#endif
}

ostream &operator<<(ostream &os, Register &reg) {
    os << "Register: a = " << get(reg,reg.get_a()) << "; b = " << get(reg,reg.get_b()) << "; x = "<<get(reg,reg.get_x())<<"; y = "<<get(reg,reg.get_y());
    return os;
}
