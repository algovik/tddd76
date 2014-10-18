/**
 * Filename: Expression_Tree.h
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * The interface declaration file listing all the function
 * that exist in Expression_Tree.cc.
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
class expression_error : public std::logic_error {
    public:
        explicit expression_error(const std::string& whatarg) noexcept
            : logic_error{whatarg} {}

        explicit expression_error(const char* whatarg) noexcept
            : logic_error{whatarg} {}
    };

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */
class Expression_Tree
{
public:
    virtual ~Expression_Tree() = default;
    virtual long double      evaluate() const = 0;
    virtual std::string      get_postfix() const = 0;
    virtual std::string      str() const = 0;
    virtual void             print(std::ostream&, int=16) const = 0;
    virtual Expression_Tree* clone() const = 0;
    virtual std::string      get_infix() const = 0;

};

/*
 * Binary_Operator class one of the two main catagories of Expression_Tree
 */
class Binary_Operator : public Expression_Tree
{
protected:
    Expression_Tree* left;
    Expression_Tree* right;
    std::string s_rep = " ";
public:
    Binary_Operator(Expression_Tree*, Expression_Tree*);
    ~Binary_Operator();
    virtual std::string get_postfix() const override;
    virtual std::string get_infix() const override;
    virtual std::string str() const override;
    virtual void print(std::ostream&, int) const override;
};

/*
 * Operand class one of the two main catagories of Expression_Tree
 */
class Operand : public Expression_Tree
{
public:
    ~Operand() = default;
    std::string get_postfix() const override;
    virtual std::string get_infix() const override;
    virtual std::string str() const override;
    virtual void print(std::ostream&, int) const;
};

/*
 * A class for the object Assign a subclass to Binary_Operator
 */
class Assign : public Binary_Operator
{
public:
    Assign(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "=";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;

};

/*
 * A class for the object Plus a subclass to Binary_Operator
 */
class Plus : public Binary_Operator
{
public:
    Plus(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "+";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Minus a subclass to Binary_Operator
 */
class Minus : public Binary_Operator
{
public:
    Minus(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "-";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Times a subclass to Binary_Operator
 */
class Times : public Binary_Operator
{
public:
    Times(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "*";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Divide a subclass to Binary_Operator
 */
class Divide : public Binary_Operator
{
public:
    Divide(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "/";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Power a subclass to Binary_Operator
 */
class Power: public Binary_Operator
{
public:
    Power(Expression_Tree* left, Expression_Tree* right)
        : Binary_Operator{left, right}{ s_rep = "^";};
    long double evaluate() const override;
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Integer a subclass to Operand
 */
class Integer : public Operand
{
private:
    int value;
public:
    Integer(const int val) : value{val} {};
    long double evaluate() const override{return (long double) value;};
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Real a subclass to Operand
 */
class Real : public Operand
{
private:
    long double value;
public:
    Real(const long double val) : value{val} {};
    long double evaluate() const override{return value;};
    Expression_Tree* clone() const override;
};

/*
 * A class for the object Power a subclass to Operand
 */
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
