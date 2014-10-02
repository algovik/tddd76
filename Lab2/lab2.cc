/**
 * Filename: lab2.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date:
 * Description:
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


    monetary::Money fransk{"EUR",3,90};
    cout << fransk << endl;

    monetary::Money dansk{4,2};
    cout << dansk << endl;

    monetary::Money finsk{4,2};
    cout << finsk << endl;

    cout << "Plussat: " << tysk+fransk << endl;
    cout << "Minusat: " << tysk-fransk << endl;

    string valuta{svensk.currency()};
    cout << valuta << endl;

    // cout << "Tilldelning: " << tysk=fransk;
    // cout << tysk << endl;

    if(fransk == tysk){cout << "Tyskarna kommer!" << endl;}
    if(dansk == finsk){cout << "Danskjävel!" << endl;}

    if(fransk < tysk){cout << "Frankrike är sämst!" << endl;}
    if(dansk < finsk){cout << "Finland kan inte dricka!" << endl;}
    if(fransk < svensk){cout << "Sverige är bäst!" << endl;}


    return 0;
}
