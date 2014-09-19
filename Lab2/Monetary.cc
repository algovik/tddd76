/**
 * Filename: Monetary.cc
 * Lab: Lab2 - Klass, operatoröverlagring, undantag
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 
 * Description: 
 */

#include "Monetary.h"
#include <iostream>
using namespace std;

namespace monetary{

void Money::print()
{
    cout << Money->currency << Money->unit << "." << Money->cunit << endl;
}

void setcurrency(string s){
	currency = s;
}

void setunit(int x, int y){
	unit = x;
	cunit = y;
}
}