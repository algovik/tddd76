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

    // monetary::Money* svensk = new monetary::Money();
    monetary::Money svensk;
    svensk.print(cout);

    cout << svensk << endl;

    monetary::Money tysk{"EUR",5,0};
    tysk.print(cout);

    cout << tysk << endl;

    monetary::Money britt{4,0};
    britt.print(cout);

    monetary::Money ryss{"RUB"};
    ryss.print(cout);

    int i;
    i = tysk + ryss;
    cout << i << endl;

    string s{ryss.currency()};
    cout << s << endl;

    return 0;
}
