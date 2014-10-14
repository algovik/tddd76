/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>

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
   // virtual std::string      get_postfix() const = 0;
   // virtual std::string      str() const = 0;
   // virtual void             print(std::ostream&) const = 0;
   // virtual Expression_Tree* clone() const = 0;
};

class Binary_Operator : public Expression_Tree
{

private:
    Expression_Tree* left;
    Expression_Tree* right;
public:
    Binary_Operator(Expression_Tree* l, Expression_Tree* r);
    virtual long double evaluate() const;
    // std::string get_postfix();
    // std::string str();
    // void print(std::ostream& out);
    // Expression_Tree* clone();

};

class Operand : public Expression_Tree
{
public:
    // Operand(long double val);
    // Operand() = default;
    virtual long double evaluate() const;
    // std::string get_postfix();
    // std::string str();
    // void print(std::ostream& out);
    // Expression_Tree* clone();
};

class Assign : public Binary_Operator
{
};

class Plus : public Binary_Operator
{
private:
    Expression_Tree* left;
    Expression_Tree* right;
public:
    using Binary_Operator::Binary_Operator;
    long double evaluate();
};

// class Minus : public Binary_Operator
// {
//     long double evaluate() override;
// };
//
// class Times : public Binary_Operator
// {
//     long double evaluate() override;
// };
//
// class Divide : public Binary_Operator
// {
//     long double evaluate() override;
// };
//
// class Power: public Binary_Operator
// {
//     long double evaluate() override;
// };

class Integer : public Operand
{
private:
    int value;
public:
    Integer(const int val);
    virtual long double evaluate();

};

class Real : public Operand
{
private:
    long double value;
public:
    Real(const long double val);
    virtual long double evalute();
};

// class Variable : public Operand
// {
// };

#endif
