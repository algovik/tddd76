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
    std::stringstream sstream;
    sstream << left->get_postfix() << " " << right->get_postfix() << " " << str();
    return sstream.str();
}

/**
 * Class: Operand
 */

void Operand::print(std::ostream& out) const {
    out << "Operand tree" << endl;
}

std::string Operand::str() const {
    std::stringstream sstream;
    sstream << evaluate();
    return sstream.str();
}

std::string Operand::get_postfix() const {
    std::stringstream sstream;
    sstream << evaluate();
    return sstream.str();
}

/**
 * Class: Integer
 */

// Integer::Integer(int val) : value{val}{
//
// }

// long double Integer::evaluate() const {
//     return (long double) value;
// }

Expression_Tree* Integer::clone() const {
    Expression_Tree* p = new Integer{value};
    return p;
}

/**
 * Class: Real
 */

// Real::Real(long double val) : value{val}{
//
// }

// long double Real::evaluate() const {
//     return value;
// }

Expression_Tree* Real::clone() const {
    Expression_Tree* p = new Real{value};
    return p;
}

/**
 * Class: Variable
 */

Expression_Tree* Variable::clone() const {
    Expression_Tree* p = new Variable{name,value};
    return p;
}


/**
 * Class: Assign
 */

long double Assign::evaluate() const {
    long double tmp{right->evaluate()};
    Variable* p = dynamic_cast<Variable*>(left);
    p->set_value(tmp);
    return tmp;
}

Expression_Tree* Assign::clone() const {
    return 0;
}

/**
 * Class: Plus
 */

long double Plus::evaluate() const {
    return left->evaluate()+right->evaluate();
}

Expression_Tree* Plus::clone() const {
    Expression_Tree* p = new Plus{left->clone(), right->clone()};
    return p;
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

Expression_Tree* Minus::clone() const {
    Expression_Tree* p = new Minus{left->clone(), right->clone()};
    return p;
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

Expression_Tree* Times::clone() const {
    Expression_Tree* p = new Times{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Divide
 */

long double Divide::evaluate() const {
    return left->evaluate()/right->evaluate();
}

Expression_Tree* Divide::clone() const {
    Expression_Tree* p = new Divide{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Power
 */

long double Power::evaluate() const{
    return pow(left->evaluate(),right->evaluate());
}

Expression_Tree* Power::clone() const {
    Expression_Tree* p = new Power{left->clone(), right->clone()};
    return p;
}
