#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "Point.h"
#include "Segment.h"
#include "TrapeziumAxes.h"
#include "TrapeziumBase.h"
#include "Task1.h"

using namespace std;

int main() {
    cout << endl;
    cout << "Developed by Xenofontova Sofia IPZ-2 \n" << endl;

    cout << "START: \n" << endl;


    cout << "********* Testing TASK 1 ******** \n" << endl;

    Register r1(1, 2, 3, 4);
    Register r2(5, 6, 7, 8);
    cout << endl;
    cout << "Checking register swap \n" << endl;
    r1.swap(r1.get_y(), r1.get_a());
    cout << "Register number " << r1.getID() << "after swap of y <=> a : " << r1 << endl << endl;

    cout << "Checking register set and get \n" << endl;
    set(r2, r2.get_b(), 9999999);
    cout << "Register number " << r2.getID() << "after set b = 9999999 : " << r2 << endl << endl;
    cout << "Register number " << r1.getID() << " get: a = " << get(r1, r1.get_a()) << " b = " << get(r1, r1.get_b())
         << " x = " << get(r1, r1.get_x()) << " y = " << get(r1, r1.get_y()) << endl;
    cout << endl;

    cout << "********* Testing TASK 3 Matrix 2x2 ******** \n" << endl;

    Matrix M1(3, 4, 5, 6);
    Matrix M2(1, 2, 3, 4);
    Matrix M3 = M1.addition(M2);

    cout << "Sum of Matrix --> Matrix number: " << M1.getID() << " + Matrix number: " << M2.getID() << " = \n" << M1
         << " + \n" << M2 << " = \n" << M3 << endl;
    Matrix M4 = M1.subtraction(M2);
    cout << "Subtraction of Matrix --> Matrix number: " << M1.getID() << " - Matrix number: " << M2.getID() << " = \n"
         << M1 << " - \n" << M2 << " = \n" << M4 << endl;
    Matrix M5 = M1.multiplication(M2);
    cout << "Multiplication of Matrix --> Matrix number: " << M1.getID() << " * Matrix number: " << M2.getID()
         << " = \n" << M1 << " * \n" << M2 << " = \n" << M5 << endl;
    cout << " Deleting of all Matrices " << endl;
    cout << endl;

    cout << "********* Testing TASK 4 Point ******** \n" << endl;

    Point p1(2, 3);
    Point p2(6, 7);
    Point p3(10, 10);
    double alpha = M_PI / 2;

    cout << endl;

    cout << "X axes Point number " << p1.getID() << " reflection --> " << X_AxesRotation(p1) << endl;
    cout << "Y axes Point number " << p2.getID() << " reflection --> " << Y_AxesRotation(p2) << "\n" << endl;

    cout << " (0,0) Point number " << p2.getID() << "; alpha = " << alpha << "; rotation --> "
         << OriginRotation(p3, alpha) << "\n" << endl;
    cout << " Deleting of all Points " << endl;
    cout << endl;

    cout << "********* Testing TASK 5 ******** \n" << endl;

    Segment s1(p1, p3);
    Segment s2(3, 3, 3, -8);
    Segment s3(6, 6, -10, 6);
    Segment s4(2, 2, 9, 9);

    cout << endl;

    cout << "X axes Segment number " << s1.getID() << " reflection --> " << X_AxesRotationSegment(s1) << endl;
    cout << "Y axes Segment number " << s1.getID() << " reflection --> " << Y_AxesRotationSegment(s1) << "\n" << endl;

    cout << "X axes Segment number " << s2.getID() << " reflection --> " << X_AxesRotationSegment(s2) << endl;
    cout << "Y axes Segment number " << s3.getID() << " reflection --> " << Y_AxesRotationSegment(s3) << "\n" << endl;

    cout << " (0,0) Segment number " << s4.getID() << "; alpha = " << alpha << "; rotation --> "
         << OriginRotationSegment(s4, alpha) << "\n" << endl;

    cout << " Deleting of all " << endl;
    cout << endl;
    cout << "********* Testing TASK 6 9 10 TrapeziumAxes ******** \n" << endl;
    Point tap1(3, 1);
    Point tap2(3, 4);
    Point tap3(6, 4);
    Point tap4(9, 1);

    double alpha2 = M_PI / 4;
    double alpha2_0 = M_PI / 6;

    TrapeziumAxes ta1(tap1, tap2, tap3, tap4);
    cout << endl;
    cout << "X axes TrapeziumAxes number " << ta1.getID() << " reflection --> " << ta1.X_AxesRotation() << endl;
    cout << "Y axes TrapeziumAxes number " << ta1.getID() << " reflection --> " << ta1.Y_AxesRotation() << endl;
    cout << "(0,0) TrapeziumAxes number " << ta1.getID() << "; alpha = " << alpha2 << "; rotation --> "
         << ta1.OriginRotation(alpha2) << endl;
    cout << endl;
    TrapeziumAxes ta2(2, 1, 4, 5, 9, 5, 13, 1);
    cout << endl;
    cout << "X axes TrapeziumAxes number " << ta2.getID() << " reflection --> " << ta2.X_AxesRotation() << endl;
    cout << "Y axes TrapeziumAxes number " << ta2.getID() << " reflection --> " << ta2.Y_AxesRotation() << endl;
    cout << "(0,0) TrapeziumAxes number " << ta2.getID() << "; alpha = " << alpha2_0 << "; rotation --> "
         << ta2.OriginRotation(alpha2_0) << endl;


    cout << endl;

    cout << "********* Testing TASK 7 9 10 TrapeziumBase ******** \n" << endl;

    Segment bc1(-8, 6, -4, 6);
    Segment ad1(-14, 1, 2, 1);

    double alpha3 = M_PI / 6;
    double alpha4 = M_PI;

    TrapeziumBase tb1(bc1, ad1);
    cout << endl;
    cout << "X axes TrapeziumBase number " << tb1.getID() << " reflection --> " << tb1.X_AxesRotation() << endl;
    cout << "Y axes TrapeziumBase number " << tb1.getID() << " reflection --> " << tb1.Y_AxesRotation() << endl;
    cout << "(0,0) TrapeziumBase number " << tb1.getID() << "; alpha = " << alpha3 << "; rotation --> "
         << tb1.OriginRotation(alpha3) << endl;
    cout << endl;
    Segment bc2(-2, -4, -2, -6);
    Segment ad2(-8, -10, -8, -15);
    TrapeziumBase tb2(bc2, ad2);
    cout << endl;
    cout << "X axes TrapeziumBase number " << tb2.getID() << " reflection --> " << tb2.X_AxesRotation() << endl;
    cout << "Y axes TrapeziumBase number " << tb2.getID() << " reflection --> " << tb2.Y_AxesRotation() << endl;
    cout << "(0,0) TrapeziumBase number " << tb2.getID() << "; alpha = " << alpha4 << "; rotation --> "
         << tb2.OriginRotation(alpha4) << endl;

    cout << endl;


    cout << "********* Testing TASK 8 TrapeziumAxes <=> TrapeziumBase converter ******** \n" << endl;

    TrapeziumBase tb3(ta2);

    cout << "TrapeziumAxes number " << ta2.getID() << " successfully converted to TrapeziumBase number " << tb3.getID()
         << endl
         << endl;

    TrapeziumAxes ta3(tb1);
    cout << "TrapeziumBase number " << tb1.getID() << " successfully converted to TrapeziumAxes number " << ta3.getID()
         << endl
         << endl << endl;


    cout << "END " << endl << endl;
    cout << " Deleting... \n" << endl;


    return 0;
}