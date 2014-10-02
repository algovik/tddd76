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
        :curr{s}, unit{x}, cunit{y} {}

    Money::Money(const int x, const int y)
        :curr{""}, unit{x}, cunit{y} {}

    Money::~Money(){
        // cout << "Deconstructing" << endl;
    }


    // void Money::print(ostream& out){
    //     if(curr == ""){
    //         out << unit << ".";
    //         if(cunit<10){
    //             out << "0" << cunit << endl;
    //         }else{
    //             out << cunit << endl;
    //         }
    //     }else{
    //         out << curr << " " << unit << ".";
    //         if(cunit<10){
    //             out << "0" << cunit << endl;
    //         }else{
    //             out << cunit << endl;
    //         }
    //     }
    // }

    void Money::print(ostream& out){
        out << *this << endl;
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
            if(res.cunit<0){
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

    void Money::operator=(const Money& rhs){
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

    std::ostream& operator<<(std::ostream& out, Money const& money){
        if(money.curr == ""){
            if(money.cunit<10){
                return out << money.unit << ".0" << money.cunit;
            }else{
                return out << money.unit << "." << money.cunit;
            }
        }else{
            if(money.cunit<10){
                return out << money.curr << " " << money.unit << ".0" << money.cunit;
            }else{
                return out << money.curr << " " << money.unit << "." << money.cunit;
            }
        }
    }

    bool operator==(const Money& lhs, const Money& rhs){
        if(lhs.curr==rhs.curr || rhs.curr.empty() || lhs.curr.empty()){
            if(lhs.unit==rhs.unit && lhs.cunit==rhs.cunit){
                return true;
            }else{
                return false;
            }
        }else{
            throw monetaryerror("Can't compare two different currencies.");
        }
    }

    bool operator<(const Money& lhs, const Money& rhs){
        if(lhs.curr==rhs.curr || rhs.curr.empty() || lhs.curr.empty()){
            if(lhs.unit<rhs.unit){
                return true;
            }else if(lhs.unit==rhs.unit && lhs.cunit<rhs.cunit){
                return true;
            }else{
                return false;
            }
        }else{
            throw monetaryerror("Can't compare two different currencies.");
        }
    }

    bool operator>(const Money& lhs, const Money& rhs){
        // if(lhs<rhs || lhs==rhs){
        //     return false;
        // }else{
        //     return true;
        // }
        return operator<(rhs,lhs);
    }

    bool operator<=(const Money& lhs, const Money& rhs){
        // if(lhs<rhs || lhs==rhs){
        //     return true;
        // }else{
        //     return false;
        // }
        return !operator>(lhs,rhs);
    }

    bool operator>=(const Money& lhs, const Money& rhs){
        // if(lhs<rhs){
        //     return false;
        // }else{
        //     return true;
        // }
        return !operator<(lhs,rhs);
    }

    bool operator!=(const Money& lhs, const Money& rhs){
        // if(lhs==rhs){
        //     return false;
        // }else{
        //     return true;
        // }
        return !operator==(lhs,rhs);
    }

    Money& Money::operator++(){
        cunit+=1;
        if(cunit>=100){
            cunit -= 100;
            unit += 1;
        }
        return *this;
    }

    Money Money::operator++(int){
        Money tmp{*this};
        operator++();
        return tmp;
    }

    Money& Money::operator--(){
        cunit-=1;
        if(cunit<0){
            cunit += 100;
            unit -= 1;
        }
        if(unit<0){
            throw monetaryerror("The resulting value can't be negative.");
        }
        return *this;
    }

    Money Money::operator--(int){
        Money tmp{*this};
        operator--();
        return tmp;
    }

}
