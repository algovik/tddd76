/**
 * Filename: Expression.h
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * The interface declaration file listing all the function
 * that exist in Expression.cc.
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Expression_Tree.h"
#include <iosfwd>
#include <stdexcept>
#include <string>

/**
* expression_error: kastas om fel inträffar i en Expression- operation;
* ett diagnostiskt meddelande ska skickas med.
*/
// class expression_error : public std::logic_error {
// 	public:
// 		explicit expression_error(const std::string& whatarg) noexcept
// 			: logic_error{whatarg} {}
//
// 		explicit expression_error(const char* whatarg) noexcept
// 			: logic_error{whatarg} {}
// 	};


/**
* Expression: Klass för att representera ett enkelt aritmetiskt uttryck.
*/
class Expression
{
private:
    Expression_Tree* root=nullptr;

public:

   Expression(Expression_Tree* tree = nullptr) : root{tree} {}
   Expression(const Expression& orig);
   Expression(Expression&& orig) noexcept {swap(orig);}
   ~Expression(){delete root;}

   Expression& operator=(const Expression&);
   Expression& operator=(Expression&&);
   Expression& operator=(std::nullptr_t);

   long double evaluate(Variable_Table&) const;
   std::string get_postfix() const;
   std::string get_infix() const;
   bool        empty() const;
   void        print_tree(std::ostream&) const;
   void        swap(Expression&);

   //Helper Functions
   Expression_Tree* copy() const;
   Expression_Tree* get_tree() const {return root;}
   void set_tree(Expression_Tree* tree){root=tree;}
};

/**
* swap: Byter innehåll på två Expression-objekt.
*/
void swap(Expression&, Expression&);

/**
* make_expression: Hjälpfunktion för att skapa ett Expression-objekt, givet
* ett infixuttryck i form av en sträng.
*/
Expression make_expression(const std::string& infix);

#endif
