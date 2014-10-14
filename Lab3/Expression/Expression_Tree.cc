/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

Binary_Operator::Binary_Operator(Expression_Tree* l, Expression_Tree* r) : left{l}, right{r}{

}

Operand::Operand(long double val) : value{val}{

}

Integer::Integer(int val) : value{val}{

}

long double Operand::evaluate(){
    return (long double) value;
}

long double Plus::evaluate(){
    return right.evaluate()+left.evaluate();
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
