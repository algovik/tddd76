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


//OBS!!!!!!!!!!
// Plus::Plus(Expression_Tree*, Expression_Tree*) : Binary_Operator{left, right} {
//     c_rep = '+';
// }

void Binary_Operator::print(std::ostream& out) const {
    out << "Binary_Operator tree" << endl;
}


void Operand::print(std::ostream& out) const {
    out << "Operand tree" << endl;
}

Integer::Integer(int val) : value{val}{

}

long double Integer::evaluate() const {
    return (long double) value;
}

// void Integer::print(std::ostream& out) const {
//     out << value << endl;
// }

Real::Real(long double val) : value{val}{

}

long double Real::evaluate() const {
    return value;
}

// void Real::print(std::ostream& out) const {
//     out << value << endl;
// }

long double Plus::evaluate() const {
    return left->evaluate()+right->evaluate();
}

// void Plus::print(std::ostream& out) const {
//     out << left->evaluate() << " + " << right->evaluate() << endl;
// }

long double Minus::evaluate() const {
    return left->evaluate()-right->evaluate();
}

// void Minus::print(std::ostream& out) const {
//     out << left->evaluate() << " - " << right->evaluate() << endl;
// }

long double Times::evaluate() const {
    return left->evaluate()*right->evaluate();
}

long double Divide::evaluate() const {
    return left->evaluate()/right->evaluate();
}
