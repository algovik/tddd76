/**
 * Filename: lab2.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date:031014
 * Description: A test program for objects of the
 * class Money as part of Lab2.
 */

#include <iostream>
#include "Monetary.h"

using namespace std;

int main(){

    monetary::Money def;
    def.print(cout);

    monetary::Money svensk{"SEK"};
    svensk.print(cout);

    monetary::Money tysk{"EUR",6,20};
    tysk.print(cout);


    monetary::Money fransk{"EUR",3,99};
    cout << fransk << endl;

    monetary::Money fransk2{fransk};
    cout << "fransk2: " << fransk2 << endl;

    monetary::Money dansk{4,2};
    cout << dansk << endl;

    monetary::Money finsk{4,2};
    cout << finsk << endl;

    cout << "Plussat: " << tysk+fransk << endl;
    cout << "Minusat: " << tysk-fransk << endl;

    string valuta{svensk.currency()};
    cout << valuta << endl;

    monetary::Money spansk=tysk=fransk;
    cout << "Tysk: " << tysk << " Spansk: " << spansk << " Fransk: " << fransk << endl;

    if(fransk < tysk){cout << "Frankrike är sämst!" << endl;}
    if(dansk < finsk){cout << "Finland kan inte dricka!" << endl;}

    cout << ++fransk << endl;
    fransk.print(cout);

    cout << fransk++ << endl;
    fransk.print(cout);

    cout << --fransk << endl;
    fransk.print(cout);

    cout << fransk-- << endl;
    fransk.print(cout);

    tysk -= fransk;
    cout << tysk << endl;

    monetary::Money x;
    cin >> x;
    x.print(cout);

    return 0;
}
