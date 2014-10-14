/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>
#include <iostream>
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
    //virtual std::string      get_postfix() const = 0;
    virtual std::string      str() const = 0;
    virtual void             print(std::ostream&) const = 0;
   // virtual Expression_Tree* clone() const = 0;
};

class Binary_Operator : public Expression_Tree
{

protected:
    Expression_Tree* left;
    Expression_Tree* right;
    char c_rep = ' ';       
public:

    Binary_Operator(Expression_Tree* left, Expression_Tree* right);
    std::string get_postfix() const;
    //virtual long double evaluate() const;
    std::string str() const override;
    virtual void print(std::ostream& out) const override;
    // Expression_Tree* clone();

};

class Operand : public Expression_Tree
{
public:
    // std::string get_postfix();
    // std::string str();
    virtual void print(std::ostream& out) const;
    // Expression_Tree* clone();
};

class Assign : public Binary_Operator
{
};

class Plus : public Binary_Operator
{
public:
    //using Binary_Operator::Binary_Operator;
    Plus(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{left, right}{ c_rep = '+';};
    long double evaluate() const override;
    // void print(std::ostream&) const override;
};

class Minus : public Binary_Operator
{
public:
    //using Binary_Operator::Binary_Operator;
    Minus(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{left, right}{ c_rep = '-';};
    long double evaluate() const override;
    // void print(std::ostream&) const override;
};

class Times : public Binary_Operator
{
public:
    Times(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{left, right}{ c_rep = '*';};
    //using Binary_Operator::Binary_Operator;
    long double evaluate() const override;
};

class Divide : public Binary_Operator
{
public:
    Divide(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{left, right}{ c_rep = '/';};
    //using Binary_Operator::Binary_Operator;
    long double evaluate() const override;
};
//
// class Power: public Binary_Operator
// {
//     long double evaluate() const override;
// };

class Integer : public Operand
{
private:
    int value;
public:
    Integer(const int);
    long double evaluate() const override;
    // void print(std::ostream&) const override;
};

class Real : public Operand
{
private:
    long double value;
public:
    Real(const long double);
    long double evaluate() const override;
    // void print(std::ostream&) const override;
};

// class Variable : public Operand
// {
// };

#endif
