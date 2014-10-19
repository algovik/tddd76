/**
 * Filename: Expression_Tree.cc
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * Description: The implementation file with the sourcecode for
 * the class Expression_Tree
 */
#include "Expression_Tree.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <typeinfo>

using namespace std;

/**
 * Class: Binary_Operator
 */

Binary_Operator::Binary_Operator(Expression_Tree* left, Expression_Tree* right)
    :left(left), right(right) {

}

Binary_Operator::~Binary_Operator(){
    delete left;
    delete right;
}

void Binary_Operator::print(std::ostream& out, int i) const {
    if(right == nullptr || left == nullptr){
        throw expression_error("Branch does not exist.");
    }
    out << setw(i);
    right->print(out, i+2);
    out << endl << setw(i-1) << "/" << endl
    << setw(i-2) << str() << endl
    << setw(i-1) << "\\" << endl << setw(i);
    left->print(out, i+2);
}


std::string Binary_Operator::str() const{
    return s_rep;
}

std::string Binary_Operator::get_postfix() const {
    if(right == nullptr || left == nullptr){
        throw expression_error("Branch does not exist.");
    }
    std::stringstream sstream;
    sstream << left->get_postfix() << " " << right->get_postfix() << " " << str();
    return sstream.str();
}

std::string Binary_Operator::get_infix() const {
    if(right == nullptr || left == nullptr){
        throw expression_error("Branch does not exist.");
    }
    std::stringstream sstream;
    if(typeid(*this) != typeid(Assign)){
       sstream << "(";
    }
    sstream << left->get_infix() << " " << str() << " " << right->get_infix();
    if(typeid(*this) != typeid(Assign)){
       sstream << ")";
    }
    return sstream.str();
}

/**
 * Class: Operand
 */

void Operand::print(std::ostream& out, int i) const {
    i = i+1;
    out << str();
}

// std::string Operand::str() const {
//     std::stringstream sstream;
//     sstream << value;
//     return sstream.str();
// }

std::string Operand::get_postfix() const {
    return str();
}
std::string Operand::get_infix() const {
    return str();
}

// void Operand::clear() const {
//
// }

/**
 * Class: Integer
 */

Expression_Tree* Integer::clone() const {
    Expression_Tree* p = new Integer{value};
    return p;
}

std::string Integer::str() const {
    std::stringstream sstream;
    sstream << value;
    return sstream.str();
}

/**
 * Class: Real
 */

Expression_Tree* Real::clone() const {
    Expression_Tree* p = new Real{value};
    return p;
}

std::string Real::str() const {
    std::stringstream sstream;
    sstream << value;
    return sstream.str();
}

/**
 * Class: Variable
 */

long double Variable::evaluate(Variable_Table& table) const {
  return get_value(table);
}

long double Variable::get_value(Variable_Table& table) const {
  if(table.find(name)){
    return table.get_value(name);
  }else{
    throw variable_table_error("Variable does not exist");
  }
}

void Variable::set_value(const long double val, Variable_Table& table){
  if(table.find(name)){
    table.set_value(name, val);
  }else{
    table.insert(name,val);
  }
}

Expression_Tree* Variable::clone() const {
    Expression_Tree* p = new Variable{name,value};
    return p;
}

/**
 * Class: Assign
 */

long double Assign::evaluate(Variable_Table& table) const {
    long double tmp{right->evaluate(table)};
    Variable* p = dynamic_cast<Variable*>(left);
    p->set_value(tmp, table);
    return tmp;
}

Expression_Tree* Assign::clone() const {
    Expression_Tree* p = new Assign{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Plus
 */

long double Plus::evaluate(Variable_Table& table) const {
    return left->evaluate(table)+right->evaluate(table);
}

Expression_Tree* Plus::clone() const {
    Expression_Tree* p = new Plus{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Minus
 */

long double Minus::evaluate(Variable_Table& table) const {
    return left->evaluate(table)-right->evaluate(table);
}

Expression_Tree* Minus::clone() const {
    Expression_Tree* p = new Minus{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Times
 */

long double Times::evaluate(Variable_Table& table) const {
    return left->evaluate(table)*right->evaluate(table);
}

Expression_Tree* Times::clone() const {
    Expression_Tree* p = new Times{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Divide
 */

long double Divide::evaluate(Variable_Table& table) const {
    return left->evaluate(table)/right->evaluate(table);
}

Expression_Tree* Divide::clone() const {
    Expression_Tree* p = new Divide{left->clone(), right->clone()};
    return p;
}

/**
 * Class: Power
 */

long double Power::evaluate(Variable_Table& table) const{
    return pow(left->evaluate(table),right->evaluate(table));
}

Expression_Tree* Power::clone() const {
    Expression_Tree* p = new Power{left->clone(), right->clone()};
    return p;
}
