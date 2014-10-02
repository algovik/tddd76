/**
 * Filename: Monetary.cc
 * Lab: Lab2 - Klass, operatoröverlagring, undantag
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date:031014
 * Description: The implementation file with the sourcecode for
 * the class Money and all function needed to complete Lab2.
 */

#include "Monetary.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace monetary{

    /**
    * A constructor for a object of the class Money
    * @param   s  The currency of the Monetary object
    *          x  The value for the number of units in the Monetary object
    *          y  The value for the number of hundredhs on teh Monetary objct
    */
    Money::Money(const string s, const int x, const int y)
        :curr{s}, unit{x}, cunit{y} {}

    /**
    * A constructor for a object of the class Money
    * @param   x  The value for the number of units in the Monetary object
    *          y  The value for the number of hundredhs on teh Monetary objct
    */    
    Money::Money(const int x, const int y)
        :curr{""}, unit{x}, cunit{y} {}

    
    /**
    * A deconstructor for a object of the class Money
    */
    Money::~Money(){
    }

    /**
    * A helpfunction for printing for a object of the class Money
    * @param   out  The outstream used for printing       
    */     
    void Money::print(ostream& out){
        out << *this << endl;
    }

    /**
    * Gives the currenecy of the Money object
    * @return a string with the currency of the object     
    */ 
    string Money::currency(){
        return curr;
    }

    /**
    * Operator overloading of + for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    * @return  a Money object whose value has been added   
    */
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

    /**
    * Operator overloading of - for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    * @return  a Money object whose value has been subtracted   
    */
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

    /**
    * Operator overloading of = for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    */
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

    /**
    * Operator overloading of << for printing for the Money class 
    * @param   money the object that should be printed 
    *          out  the outstream used for printing 
    * @return  the outream that should be printed 
    */
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

    /**
    * Operator overloading of == for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    *          lhs the money object on the left hand side of the operator 
    * @return  true if the objects are equal, false otherwise
    */
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

    /**
    * Operator overloading of < for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    *          lhs the money object on the left hand side of the operator
    * @return  true if the lhs object are smaller then the rhs, false otherwise 
    */
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

    /**
    * Operator overloading of > for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    *          lhs the money object on the left hand side of the operator
    * @return  true if the lhs object are bigger then the rhs, false otherwise 
    */
    bool operator>(const Money& lhs, const Money& rhs){
        return operator<(rhs,lhs);
    }

    /**
    * Operator overloading of <= for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    *          lhs the money object on the left hand side of the operator
    * @return  true if the lhs object are bigger or equal to the rhs, false otherwise 
    */
    bool operator<=(const Money& lhs, const Money& rhs){
        return !operator>(lhs,rhs);
    }

    /**
    * Operator overloading of >= for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    *          lhs the money object on the left hand side of the operator
    * @return  true if the lhs object are smaller or equal to the rhs, false otherwise 
    */
    bool operator>=(const Money& lhs, const Money& rhs){
        return !operator<(lhs,rhs);
    }

    /**
    * Operator overloading of >= for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    *          lhs the money object on the left hand side of the operator
    * @return  true if the lhs objects are not equal, false otherwise 
    */
    bool operator!=(const Money& lhs, const Money& rhs){
        return !operator==(lhs,rhs);
    }

    /**
    * Operator overloading of ++ for the Money class
    * @return  the object after 0.01 has been added to it
    */
    Money& Money::operator++(){
        cunit+=1;
        if(cunit>=100){
            cunit -= 100;
            unit += 1;
        }
        return *this;
    }

    /**
    * Operator overloading of ++ for the Money class
    * @param   int 
    * @return  the object before 0.01 has been added to it
    */
    Money Money::operator++(int){
        Money tmp{*this};
        operator++();
        return tmp;
    }

    /**
    * Operator overloading of --for the Money class
    * @return  the object after 0.01 has been subtracted from it
    */
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

    /**
    * Operator overloading of --for the Money class
    * @param   int 
    * @return  the object before 0.01 has been removed fro it
    */
    Money Money::operator--(int){
        Money tmp{*this};
        operator--();
        return tmp;
    }

    /**
    * Operator overloading of += for the Money class
    * @param   rhs the money object on the right hand side of the operator  
    */
    void Money::operator+=(const Money& rhs){
        operator=(operator+(rhs));
    }

    /**
    * Operator overloading of -= for the Money class
    * @param   rhs the money object on the right hand side of the operator   
    */
    void Money::operator-=(const Money& rhs){
        operator=(operator-(rhs));
    }
}
