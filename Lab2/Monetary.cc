/**
 * Filename: Monetary.cc
 * Lab: Lab2 - Classes, operator overloading, exceptions
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 031014
 * Description: The implementation file with the sourcecode for
 * the class Money and all function needed to complete Lab2.
 */

#include "Monetary.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

namespace monetary{

    /**
     * A constructor for an object of the class Money
     * @param   s  The currency of the Money object
     *          x  The value for the number of units in the Money object
     *          y  The value for the number of hundredths on the Money object
     */
    Money::Money(const string s, const int x, const int y)
        :curr{s}, unit{x}, cunit{y} {
            checkformat();
        }

    /**
     * A constructor for an object of the class Money
     * @param   x  The value for the number of units in the Money object
     *          y  The value for the number of hundredhs on teh Money obejct
     */
    Money::Money(const int x, const int y)
        :curr{""}, unit{x}, cunit{y} {
            checkformat();
        }


    /**
     * A destructor for an object of the class Money
     */
    Money::~Money(){}

    /**
     * A member function for printing an object of the class Money
     * @param   out  The outstream used for printing
     */
    void Money::print(ostream& out) const{
        if(curr == ""){
            if(cunit<10){
                out << unit << ".0" << cunit;
            }else{
                out << unit << "." << cunit;
            }
        }else{
            if(cunit<10){
                out << curr << " " << unit << ".0" << cunit;
            }else{
                out << curr << " " << unit << "." << cunit;
            }
        }
    }

    /**
     * Gives the currenecy of the Money object
     * @return a string with the currency of the object
     */
    string Money::currency(){
        return curr;
    }

    /**
     * Checks the format of the data in the Money class and throws
     * exceptions if the format is invalid.
     */
    void Money::checkformat(){
        if(!curr.empty() && curr.length()!=3){
            throw monetaryerror("Bad currency format.");
        }
        if(unit<0 || cunit<0 || cunit>99){
            cout << unit << "." << cunit << endl;
            throw monetaryerror("Invalid amount.");
        }
    }

    /**
     * Operator overloading of + for the Money class
     * @param   rhs the money object on the right hand side of the operator
     * @return  a Money object whose value has been added
     */
    Money Money::operator+(const Money& rhs){
        int resunit, rescunit;
        string rescurr;

        if(curr==rhs.curr || curr.empty()){
            rescurr = rhs.curr;
        }else if(rhs.curr.empty()){
            rescurr = curr;
        }else{
            throw monetaryerror("Can't add two different currencies.");
        }
        resunit = unit+rhs.unit;
        rescunit = cunit+rhs.cunit;
        if(rescunit>=100){
            rescunit -= 100;
            resunit += 1;
        }
        Money res{rescurr,resunit,rescunit};
        return res;
    }

    /**
     * Operator overloading of - for the Money class
     * @param   rhs the money object on the right hand side of the operator
     * @return  a Money object whose value has been subtracted
     */
    Money Money::operator-(const Money& rhs){
        int resunit, rescunit;
        string rescurr;

        if(curr==rhs.curr || curr.empty()){
            rescurr = rhs.curr;
        }else if(rhs.curr.empty()){
            rescurr = curr;
        }else{
            throw monetaryerror("Can't subtract two different currencies.");
        }
        resunit = unit-rhs.unit;
        rescunit = cunit-rhs.cunit;
        if(rescunit<0){
            rescunit += 100;
            resunit -= 1;
        }
        // if(resunit<0){
        //     throw monetaryerror("The resulting value can't be negative.");
        // }

        Money res{rescurr,resunit,rescunit}; //Sign of result is controlled at initiation
        return res;
    }

    /**
     * Operator overloading of = for the Money class
     * @param   rhs the money object on the right hand side of the operator
     */
    Money Money::operator=(const Money& rhs){
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
        return *this;
    }

    /**
     * Operator overloading of << for printing for the Money class
     * @param   out   the outstream used for printing
     *          money the object that should be printed
     * @return  the outream that should be printed
     */
    std::ostream& operator<<(std::ostream& out, Money const& money){
        money.print(out);
        return out;
    }

    /**
     * Operator overloading of >> for reading Money class objects
     * @param   in      the instream read from
     *          money   the object in which to save the data
     * @return  the instream from which is being reaa
     */
    std::istream& operator>>(std::istream& in, Money& money){
        string curr = "";
        int unit = 0;
        int cunit = 0;
        double cunit2 = 0;
        bool b = false;
        char c;

        while(in){

            c = in.peek();

            if(c==' ' || c=='.'){
                in.get();
            }else if(isalpha(c)){
                in >> curr;
            // }else if(isdigit(c) && b){
            //     in >> cunit;
            //     if(c!='0' && cunit<10){
            //         cunit = cunit*10;
            //     }else if(cunit>99){
            //         throw monetaryerror("Bad input.");
            //     }
            //     break;
            // }else if(b){
            //     break;
            }else if(isdigit(c)){

                in >> cunit2;
                unit = floor(cunit2);
                float f = (cunit2-unit)*100;
                cunit = round((cunit2-unit)*100);
                   
                if((f- cunit)>0){
                    throw monetaryerror("To many decimals");
                }

                break;
            }else{
                throw monetaryerror("Bad input.");
            }
        }
        money.curr=curr; money.unit=unit; money.cunit=cunit;
        money.checkformat();
        return in;
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
     * @return  true if the lhs object is bigger then the rhs, false otherwise
     */
    bool operator>(const Money& lhs, const Money& rhs){
        return operator<(rhs,lhs);
    }

    /**
     * Operator overloading of <= for the Money class
     * @param   rhs the money object on the right hand side of the operator
     *          lhs the money object on the left hand side of the operator
     * @return  true if the lhs object is bigger or equal to the rhs, false otherwise
     */
    bool operator<=(const Money& lhs, const Money& rhs){
        return !operator>(lhs,rhs);
    }

    /**
     * Operator overloading of >= for the Money class
     * @param   rhs the money object on the right hand side of the operator
     *          lhs the money object on the left hand side of the operator
     * @return  true if the lhs object is smaller or equal to the rhs, false otherwise
     */
    bool operator>=(const Money& lhs, const Money& rhs){
        return !operator<(lhs,rhs);
    }

    /**
     * Operator overloading of != for the Money class
     * @param   rhs the money object on the right hand side of the operator
     *          lhs the money object on the left hand side of the operator
     * @return  true if the lhs objects is not equal, false otherwise
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
     * Operator overloading of -- for the Money class
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
     * Operator overloading of -- for the Money class
     * @param   int
     * @return  the object before 0.01 has been removed from it
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
