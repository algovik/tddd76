/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
/*
 * expression_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!
// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */

class Expression_Tree
{
public:
    virtual long double      evaluate() const = 0;
    virtual std::string      get_postfix() const = 0;
    virtual std::string      str() const = 0;
    virtual void             print(std::ostream&, int=16) const = 0;
    virtual Expression_Tree* clone() const = 0;
    virtual std::string      get_infix() const = 0;

};

class Binary_Operator : public Expression_Tree
{

protected:
    Expression_Tree* left;
    Expression_Tree* right;
    std::string s_rep = " ";
public:
    Binary_Operator(Expression_Tree*, Expression_Tree*);
    // ~Binary_Operator();
    virtual std::string get_postfix() const override;
    virtual std::string get_infix() const override;
    virtual std::string str() const override;
    virtual void print(std::ostream&, int) const override;
};

class Operand : public Expression_Tree
{
public:
    std::string get_postfix() const override;
    virtual std::string get_infix() const override;
    virtual std::string str() const override;
    virtual void print(std::ostream&, int) const;
};

class Assign : public Binary_Operator
{
public:
    Assign(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "=";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;

};

class Plus : public Binary_Operator
{
public:
    Plus(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "+";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

class Minus : public Binary_Operator
{
public:
    Minus(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "-";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

class Times : public Binary_Operator
{
public:
    Times(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "*";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

class Divide : public Binary_Operator
{
public:
    Divide(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "/";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

class Power: public Binary_Operator
{
public:
    Power(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "^";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

class Integer : public Operand
{
private:
    int value;
public:
    Integer(const int val) : value{val} {};
    long double evaluate() const override{return (long double) value;};
    Expression_Tree* clone() const override;
    // void print(std::ostream&) const override;
};

class Real : public Operand
{
private:
    long double value;
public:
    Real(const long double val) : value{val} {};
    long double evaluate() const override{return value;};
    Expression_Tree* clone() const override;
    // void print(std::ostream&) const override;
};

class Variable : public Operand
{
private:
    std::string name;
    long double value;
public:
Variable(std::string s, const long double val=0) : name{s}, value{val} {};
    long double evaluate() const override{return value;};
    std::string str() const override {return name;};
    Expression_Tree* clone() const override;
    void set_value(const long double val){value=val;};
    long double get_value(){return value;};
};

#endif
