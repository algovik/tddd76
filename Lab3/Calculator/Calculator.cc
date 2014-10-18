/*
 * Calculator.cc
 */
#include "Calculator.h"
#include "Expression.h"
#include "Variable_Table.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

const string Calculator::valid_cmds_("?HUBPILTNARVXS");

/**
 * run: Huvudfunktionen för kalkylatorn. Skriver ut hjälpinformation
 * och läser sedan sedan in ett kommando i taget och utför det.
 */
void
Calculator::
run()
{
   cout << "Välkommen till Kalkylatorn!\n\n";
   print_help();


   do
   {
      try
      {
	 get_command();
	 if (valid_command()) execute_command();
      }
      catch (const exception& e)
      {
	 cout << e.what() << '\n';
      }
      // Oförutsedda undantag avbryter programkörningen, via main().
   }
   while (command_ != 'S');
}

/**
 * print_help: Skriver ut kommandorepertoaren.
 */
void
Calculator::
print_help()
{
   cout << "  H, ?  Skriv ut denna information\n";
   cout << "  U     Mata in ett nytt uttryck\n";
   cout << "  B     Beräkna aktuellt uttryck\n";
   cout << "  B n   Beräkna uttryck n\n";                      //finns ej
   cout << "  P     Visa aktuellt uttryck som postfix\n";
   cout << "  P n   Visa uttryck n som postfix\n";             //finns ej
   cout << "  I     Visa aktuellt uttryck som infix\n";        
   cout << "  I n   Visa uttryck n som infix\n";               //finns ej
   cout << "  L     Lista alla uttryck som infix\n";           //finns ej              
   cout << "  T     Visa aktuellt uttryck som träd\n";
   cout << "  T n   Visa uttryck n som ett träd\n";            //finns ej
   cout << "  N     Visa antal lagrade uttryck\n";             //finns ej
   cout << "  A n   Gör uttryck n till aktuellt uttryck\n";    //finns ej
   cout << "  R     Radera aktuellt uttryck\n";                //finns ej
   cout << "  R n   Radera uttryck n\n";                       //finns ej
   cout << "  V     Lista alla variabler\n";                   //finns ej
   cout << "  X     Radera alla variabler\n";                  //finns ej
   cout << "  S     Avsluta kalkylatorn\n";
}

/**
 * get_command: Läser ett kommando (ett tecken), gör om till versal och lagrar
 * kommandot i medlemmen command_, för vidare behandling av andra operationer.
 * Ingen kontroll görs om det skrivits mer, i så fall skräp, på kommandoraden.
 */
void
Calculator::
get_command()
{
   cout << ">> ";
   cin >> command_;
   command_ = toupper(command_);

   cin >> ws;
   command_2 = cin.peek();
   if(isdigit(command_2)){
     cin>>command_2;
   }else{
        command_2=0;
     }
   cout << "Input: " << command_ << " " << command_2 << endl;
 }

/**
 * valid_command: Kontrollerar om kommandot som finns i medlemmen command_
 * tillhör den tillåtna kommandorepertoraren och returnerar antingen true
 * (giltigt kommando) eller false (ogiltigt kommando).
 */
bool
Calculator::
valid_command() const
{
   if (valid_cmds_.find(command_) == string::npos)
   {
      cout << "Otillåtet kommando: " << command_ << "\n";
      return false;
   }
   return true;
}

/**
 * execute_command: Utför kommandot som finns i medlemmen command_. Kommandot
 * förutsätts ha kontrollerats med valid_command() och alltså är ett giltigt
 * kommando.
 */
void
Calculator::
execute_command()
{
   if (command_ == 'H' || command_ == '?'){
      print_help();
   }else if (command_ == 'U'){
      read_expression(cin);
   }else if (command_ == 'B'){
      cout << current_expression_.evaluate() << "\n";
   //else if (command_.size()==3 && command_.at(0) == 'B')
   //   Beräkna uttryck n 
   }else if (command_ == 'P'){

      //if(command_2!=0){
      //   Visa uttryck n som postfix
      //}else{
      cout << current_expression_.get_postfix() << "\n";
      //}
  
   }else if (command_ == 'I'){
         // if(command_2!=0){
         //   Visa uttryck n=command_2 som infix 
         // }else{
            cout << current_expression_.get_infix();
         // }    
   //else if (command_ == 'L')
   //   Lista alla uttryck som infix
    }else if (command_ == 'T'){
   //    if(command_2!=0){
   //       Visa uttryck n=command_2 som ett träd
   //    }else{
       cout << "i träet";
       current_expression_.print_tree(cout);
   //    }
   
   //else if (command_ == 'N')
   //   Visa antal lagrade uttryck
   //else if (command_ == 'A')
   //   Gör uttryck n till aktuellt uttryck
   //else if (command_ == 'R')
         // if(command_2!=0){
         //    Radera uttryck n=command_2
         // }else{
         //  Radera aktuellt uttryck
         // } 
   //else if (command_ == 'V')
   //Lista alla variabler
   //else if (command_ == 'X')
   // Radera alla variabler
   }else if (command_ == 'S'){
      cout << "Kalkylatorn avlutas, välkommen åter!\n";
   }else{
      cout << "Detta ska inte hända!\n";
   }
}

/**
 * read_expression: läser ett infixuttryck från inströmmen is och ger detta
 * till funktionen make_expression() som returnerar ett objekt av typen
 * Expression, vilket lagras som "aktuellt uttryck" i current_expression_.
 */
void
Calculator::
read_expression(istream& is)
{
   string infix;

   is >> ws;

   if (getline(is, infix))
   {
      current_expression_ = make_expression(infix);
   }
   else
   {
      cout << "Felaktig inmatning!\n";
   }
}
