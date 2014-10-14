/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <sstream>

// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;


/**
 * Class: Binary_Operator
 */

Binary_Operator::Binary_Operator(Expression_Tree* left, Expression_Tree* right)
    :left(left), right(right) {

}

void Binary_Operator::print(std::ostream& out) const {
    out << "Binary_Operator tree" << endl;
}


std::string Binary_Operator::str() const{
    return s_rep;
}

std::string Binary_Operator::get_postfix() const {
    std::ostringstream sstream;
    sstream << left->get_postfix() << " " << right->get_postfix() << " " << str();
    return sstream.str();
}

// Expression_Tree* Binary_Operator::clone() const {
//     Expression_Tree* p = new Binary_Operator{left->clone(),right->clone()};
//     return p;
// }


/**
 * Class: Operand
 */

void Operand::print(std::ostream& out) const {
    out << "Operand tree" << endl;
}

std::string Operand::str() const {
    std::ostringstream sstream;
    sstream << evaluate();
    return sstream.str();
}

std::string Operand::get_postfix() const {
    std::ostringstream sstream;
    sstream << evaluate();
    return sstream.str();
}
//
// Expression_Tree* Operand::clone() const {
//     Expression_Tree* p = new Operand{evaluate()};
//     return p;
// }


/**
 * Class: Integer
 */

// Integer::Integer(int val) : value{val}{
//
// }

// long double Integer::evaluate() const {
//     return (long double) value;
// }

// void Integer::print(std::ostream& out) const {
//     out << value << endl;
// }


/**
 * Class: Real
 */

// Real::Real(long double val) : value{val}{
//
// }

// long double Real::evaluate() const {
//     return value;
// }

// void Real::print(std::ostream& out) const {
//     out << value << endl;
// }


/**
 * Class: Plus
 */

long double Plus::evaluate() const {
    return left->evaluate()+right->evaluate();
}

// void Plus::print(std::ostream& out) const {
//     out << left->evaluate() << " + " << right->evaluate() << endl;
// }

/**
 * Class: Minus
 */

long double Minus::evaluate() const {
    return left->evaluate()-right->evaluate();
}

// void Minus::print(std::ostream& out) const {
//     out << left->evaluate() << " - " << right->evaluate() << endl;
// }

/**
 * Class: Times
 */

long double Times::evaluate() const {
    return left->evaluate()*right->evaluate();
}

/**
 * Class: Divide
 */

long double Divide::evaluate() const {
    return left->evaluate()/right->evaluate();
}

/**
 * Class: Power
 */

long double Power::evaluate() const{
    return pow(left->evaluate(),right->evaluate());
}
