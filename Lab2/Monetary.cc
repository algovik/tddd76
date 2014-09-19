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

    // Money::Money(){
    //     curr = "";
    //     unit = 0;
    //     cunit = 0;
    // }

    // Money::Money(string s){
    //     curr = s;
    //     unit = 0;
    //     cunit = 0;
    // }
    //
    // Money::Money(int x, int y){
    //     curr = "";
    //     unit = x;
    //     cunit = y;
    // }

    Money::Money(const string s, const int x = 0, const int y = 0){
        curr = s;
        unit = x;
        cunit = y;
    }

    void Money::print(ostream& out){
        if(curr == ""){
            out << unit << "." << cunit << endl;
        } else {
            out << curr << " " << unit << "." << cunit << endl;
        }
    }

    string Money::currency(){
        return curr;
    }

    void Money::setcurrency(string s){
    	curr = s;
    }

    void Money::setunit(int x, int y){
    	unit = x;
    	cunit = y;
    }

    // const Money Money::operator+(const Money& rhs){
    //     Money res{unit+rhs.unit,cunit+rhs.cunit};
    //     return res;
    // }
    //
    // const Money Money::operator-(const Money& rhs){
    //     Money res{unit-rhs.unit,cunit-rhs.cunit};
    //     return res;
    // }

    std::ostream& operator<< (std::ostream& out, Money const& money){
        if(money.curr == ""){
            return out << money.unit << "." << money.cunit;
        } else {
            return out << money.curr << " " << money.unit << "." << money.cunit;
        }
    }
}
