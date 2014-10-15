/**
 * Filename: lab2.cc
 * Lab: Lab2 - Classes, operator overloading, exceptions
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 031014
 * Description: A test program for objects of the
 * class Money as part of Lab2.
 */

#include <iostream>
#include "Monetary.h"

using namespace std;
using namespace monetary;

int main(){

    Money def;
    def.print(cout);

    Money svensk{"SEK"};
    svensk.print(cout);

    Money tysk{"EUR",6,20};
    tysk.print(cout);


    Money fransk{"EUR",3,99};
    cout << fransk << endl;

    Money fransk2{fransk};
    cout << "fransk2: " << fransk2 << endl;

    Money dansk{4,2};
    cout << dansk << endl;
    Money finsk{4};
    cout << finsk << endl;

    cout << "Plussat: " << tysk+fransk << endl;
    cout << "Minusat: " << tysk-fransk << endl;

    string valuta{svensk.currency()};
    cout << valuta << endl;

    Money spansk=tysk=fransk;
    cout << "Tysk: " << tysk << " Spansk: " << spansk << " Fransk: " << fransk << endl;

    if(fransk <= tysk){cout << "Frankrike är mindre än Tyskland." << endl;}
    if(dansk > finsk){cout << "Danmark är större än Finland." << endl;}

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

    cout << "Skriv in en valuta: ";
    Money x, x1;
    cin >> x;
    cin >> x1;
    x.print(cout);
    cout << endl;
    x1.print(cout);  

    return 0;
}
