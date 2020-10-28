//
// Created by Софія Ксенофонтова  on 2020-04-13.
//

#ifndef EXAM_XENOFONTOVA_TASK1_H
#define EXAM_XENOFONTOVA_TASK1_H

#include <iostream>
using namespace std;



class Register {

public:
    typedef unsigned int Register::* RegisterSelector;

    Register(const unsigned int a = 0, const unsigned int b = 0, const unsigned int x = 0,
             const unsigned int y = 0);

    ~Register();

    void swap(RegisterSelector , RegisterSelector ) ;

    RegisterSelector get_a() {
        return &Register::_a;
    }

    RegisterSelector get_b() {
        return &Register::_b;
    }

    RegisterSelector get_x() {
        return &Register::_x;
    }

    RegisterSelector get_y() {
        return &Register::_y;
    }

    const int getID() const {
        return RegisterID;
    }

private:
    unsigned int _a, _b, _x, _y;
    static int freeID;

    const int RegisterID;


};

inline unsigned int get(const Register &reg,
                 Register::RegisterSelector rs) {
    return reg.*rs;
}

inline unsigned int set(Register &reg,
                 Register::RegisterSelector rs, unsigned int new_rs) {
    return (reg.*rs = new_rs);
}

ostream &operator<<(ostream &, Register &);

#endif //EXAM_XENOFONTOVA_TASK1_H
