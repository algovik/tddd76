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

    // monetary::Money tysk{"EUR",5,0};
    // tysk.print(cout);
    // cout << tysk << endl;
    //
    // monetary::Money fransk{"EUR",3,2};
    // cout << fransk << endl;
    //
    // cout << "Plussat: " << tysk+fransk << endl;
    // cout << "Minusat: " << tysk-fransk << endl;
    //
    // monetary::Money britt{4,0};
    // britt.print(cout);
    //
    // monetary::Money ryss{"RUB"};
    // ryss.print(cout);
    //
    // string s{ryss.currency()};
    // cout << s << endl;

    return 0;
}
