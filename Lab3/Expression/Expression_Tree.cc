/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include <iostream>
// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

Binary_Operator::Binary_Operator(Expression_Tree* l, Expression_Tree* r)
    :left(l), right(r) {

}

// Operand::Operand(long double val)
//     :value{val}{
//
// }

Integer::Integer(int val) : value{val}{

}

long double Integer::evaluate() const {
    return (long double) value;
}

void Integer::print(std::ostream& out) const {
    out << value << endl;
}

Real::Real(long double val) : value{val}{

}

long double Real::evalute(){
    return value;
}


long double Plus::evaluate() const {
    return right->evaluate()+left->evaluate();
}

void Plus::print(std::ostream& out) const {
    out << left << " + " << right << endl;
}

// Minus::evaluate(){
//     return right.evaluate()-left.evaluate();
// }
//
// Times::evaluate(){
//     return right.evaluate()*left.evaluate();
// }
//
// Divide::evaluate(){
//     return right.evaluate()/left.evaluate();
// }
