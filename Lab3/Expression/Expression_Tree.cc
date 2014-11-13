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

    if(typeid(*this) == typeid(Assign)){
      sstream << left->get_infix() << " " << str() << " " << right->get_infix();
    }else if(typeid(*this) == typeid(Times) ||
	     typeid(*this) == typeid(Divide) ||
	     typeid(*this) == typeid(Power)){
      if(typeid(*left) == typeid(Plus) ||
	 typeid(*left) == typeid(Minus)){
	sstream << "(" << left->get_infix() << ") ";
      }else{
	sstream  << left->get_infix() << " ";
      }
      sstream << str();
      if(typeid(*right) == typeid(Plus) ||
	 typeid(*right) == typeid(Minus)){
	sstream << " (" << right->get_infix() << ")";
      }else{
	sstream << " " << right->get_infix();
      }
    }else{
      sstream << left->get_infix() << " " << str() << " " << right->get_infix();
    // if((typeid(*left) == typeid(Operand) && typeid(*right) == typeid(Operand)) ||
    //    typeid(*this) == typeid(Assign)){
    //   sstream << left->get_infix() << " " << str() << " " << right->get_infix();
    // }else if((typeid(*this) == typeid(Times) && typeid(*left) == typeid(Plus)) ||
    // 	     (typeid(*this) == typeid(Times) && typeid(*left) == typeid(Minus))){
    //   sstream << "(" << left->get_infix() << ") " << str() << right->get_infix();
    // }else{
    //   sstream << left->get_infix() << " " << str() << " (" << right->get_infix() << ")";
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
    long double tmp = right->evaluate(table);

    if(typeid(*left)==typeid(Variable)){
      Variable* p = dynamic_cast<Variable*>(left);
      p->set_value(tmp, table);
    }else{
      throw expression_error("Cannot assign a non variable");
    }
    return tmp;
}

Expression_Tree* Assign::clone() const {
  Expression_Tree* p = nullptr;
  Expression_Tree* lhs = nullptr;
  Expression_Tree* rhs = nullptr;
  try{
    lhs = left->clone();
    rhs = right->clone();
    p = new Assign{lhs,rhs};
    return p;
  } catch (exception& e){
    delete lhs;
    delete rhs;
    throw;
  }
}

/**
 * Class: Plus
 */

long double Plus::evaluate(Variable_Table& table) const {
    return left->evaluate(table)+right->evaluate(table);
}

Expression_Tree* Plus::clone() const {
  Expression_Tree* p = nullptr;
  Expression_Tree* lhs = nullptr;
  Expression_Tree* rhs = nullptr;
  try{
    lhs = left->clone();
    rhs = right->clone();
    p = new Plus{lhs,rhs};
    return p;
  } catch (exception& e){
    delete lhs;
    delete rhs;
    throw;
  }
}

/**
 * Class: Minus
 */

long double Minus::evaluate(Variable_Table& table) const {
    return left->evaluate(table)-right->evaluate(table);
}

Expression_Tree* Minus::clone() const {
  Expression_Tree* p = nullptr;
  Expression_Tree* lhs = nullptr;
  Expression_Tree* rhs = nullptr;
  try{
    lhs = left->clone();
    rhs = right->clone();
    p = new Minus{lhs,rhs};
    return p;
  } catch (exception& e){
    delete lhs;
    delete rhs;
    throw;
  }
}

/**
 * Class: Times
 */

long double Times::evaluate(Variable_Table& table) const {
    return left->evaluate(table)*right->evaluate(table);
}

Expression_Tree* Times::clone() const {
  Expression_Tree* p = nullptr;
  Expression_Tree* lhs = nullptr;
  Expression_Tree* rhs = nullptr;
  try{
    lhs = left->clone();
    rhs = right->clone();
    p = new Times{lhs,rhs};
    return p;
  } catch (exception& e){
    delete lhs;
    delete rhs;
    throw;
  }
}

/**
 * Class: Divide
 */

long double Divide::evaluate(Variable_Table& table) const {
  if(right->evaluate(table) == 0){
    throw logic_error ("Cannot divide by zero");
  }
  return left->evaluate(table)/right->evaluate(table);
}

Expression_Tree* Divide::clone() const {
  Expression_Tree* p = nullptr;
  Expression_Tree* lhs = nullptr;
  Expression_Tree* rhs = nullptr;
  try{
    lhs = left->clone();
    rhs = right->clone();
    p = new Divide{lhs,rhs};
    return p;
  } catch (exception& e){
    delete lhs;
    delete rhs;
    throw;
  }
}

/**
 * Class: Power
 */

long double Power::evaluate(Variable_Table& table) const{
    return pow(left->evaluate(table),right->evaluate(table));
}

Expression_Tree* Power::clone() const {
  Expression_Tree* p = nullptr;
  Expression_Tree* lhs = nullptr;
  Expression_Tree* rhs = nullptr;
  try{
    lhs = left->clone();
    rhs = right->clone();
    p = new Power{lhs,rhs};
    return p;
  } catch (exception& e){
    delete lhs;
    delete rhs;
    throw;
  }
}
