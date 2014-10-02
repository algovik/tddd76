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
#include <stdexcept>

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

    Money::Money(const string s, const int x, const int y)
        :curr{s}, unit{x}, cunit{y}
    {}

    Money::Money(const int x, const int y)
        :curr{""}, unit{x}, cunit{y}
    {}


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


    const Money Money::operator+(const Money& rhs){

        if(curr==rhs.curr){
            Money res{curr,unit+rhs.unit,cunit+rhs.cunit};
            if(res.cunit>=100){
                res.cunit -= 100;
                res.unit += 1;
            }
            return res;
        }else{
            throw monetaryerror("Can't add two different currencies.");
        }
    }

    const Money Money::operator-(const Money& rhs){
        if(curr==rhs.curr){
            Money res{curr, unit-rhs.unit,cunit-rhs.cunit};
            if(res.cunit<=0){
                res.cunit += 100;
                res.unit -= 1;
            }
            if(res.unit<0){
                throw monetaryerror("The resulting value can't be negative.");
            }
            return res;
        }else{
            throw monetaryerror("Can't subtract two different currencies.");
        }
    }


    Money& Money::operator=(const Money& rhs){
        if(curr==rhs.curr || rhs.curr.empty()){
            unit=rhs.unit;
            cunit=rhs.cunit;
        }else if(curr.empty()){
            curr=rhs.curr;
            unit=rhs.unit;
            cunit=rhs.cunit;
        }else{
            throw monetaryerror("A specified currency can't be changed.");
        }
    }

    std::ostream& operator<< (std::ostream& out, Money const& money){
        if(money.curr == ""){
            return out << money.unit << "." << money.cunit;
        } else {
            return out << money.curr << " " << money.unit << "." << money.cunit;
        }
    }

    bool Money::operator==(const Money& rhs){
        if(curr==rhs.curr || rhs.curr.empty() || curr.empty()){
            if(unit==rhs.unit && cunit==rhs.cunit){
                return true;
            }else{
                return false;
            }
        }else{
            throw monetaryerror("Can't compare two different currencies.");
        }
    }

    bool Money::operator<(const Money& rhs){
        if(curr==rhs.curr || rhs.curr.empty() || curr.empty()){
            if(unit<rhs.unit){
                return true;
            }else if(unit==rhs.unit && cunit<rhs.cunit){
                return true;
            }else{
                return false;
            }
        }else{
            throw monetaryerror("Can't compare two different currencies.");
        }
    }

    bool Money::operator<=(const Money& rhs){
        if(*this<rhs || *this==rhs){
            return true;
        }else{
            return false;
        }
    }

    bool Money::operator>(const Money& rhs){
        if(*this<rhs || *this==rhs){
            return false;
        }else{
            return true;
        }
    }

    bool Money::operator>=(const Money& rhs){
        if(*this<rhs){
            return false;
        }else{
            return true;
        }
    }

    bool Money::operator!=(const Money& rhs){
        if(*this==rhs){
            return false;
        }else{
            return true;
        }
    }
}
