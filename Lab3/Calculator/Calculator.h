/*
 * Calculator.h
 */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Expression.h"
#include <iosfwd>
#include <vector>
#include <iomanip>


/**
 * Calculator: klass för att läsa in, lagra och bearbeta enkla aritmetiska
 * uttryck. För att använda kalylatorn - skapa ett Calculator-objekt och 
 * anropa run().
 *
 * Anm: move-konstruktorn och move-illdelningsoperatorn genereras inte om
 * en destruktor, kopieringskonstruktor eller kopieringstilldelnings-
 * operator deklareras.
 */
class Calculator
{
public:
   Calculator() = default;
   ~Calculator() = default;

   Calculator(const Calculator&) = delete;
   Calculator& operator=(const Calculator&) = delete;
   
   Variable_Table table;

   void run();

private:
   static const std::string valid_cmds_;
   static const std::string valid_cmds_second_;

   Expression current_expression_;
   Expression temporary_expression_;
   int current_expression_index_;
   std::vector<Expression> list;
   
   char command_;
   int command_2 = 0; 

   static void print_help();

   void get_command();
   bool valid_command() const;
   void execute_command();

   void read_expression(std::istream&);
};

#endif
