/*
 * Calculator.cc
 */
#include "Calculator.h"
#include "Expression.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>

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
   cout << "  B n   Beräkna uttryck n\n";
   cout << "  P     Visa aktuellt uttryck som postfix\n";
   cout << "  P n   Visa uttryck n som postfix\n";
   cout << "  I     Visa aktuellt uttryck som infix\n";        
   cout << "  I n   Visa uttryck n som infix\n";
   cout << "  L     Lista alla uttryck som infix\n";
   cout << "  T     Visa aktuellt uttryck som träd\n";
   cout << "  T n   Visa uttryck n som ett träd\n";
   cout << "  N     Visa antal lagrade uttryck\n";
   cout << "  A n   Gör uttryck n till aktuellt uttryck\n";
   cout << "  R     Radera aktuellt uttryck\n";
   cout << "  R n   Radera uttryck n\n";
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
//{
//   cout << ">> ";
//   cin >> command_;
//    command_ = toupper(command_);

//    cin >> ws;
//    command_2 = cin.peek();
//    if(isdigit(command_2)){
//      cin>>command_2;
//    }else{
//         command_2=0;
//      }
//    cout << "Input: " << command_ << " " << command_2 << endl;
// }

{
  cout << ">> ";
  cin >> command_;
  command_ = toupper(command_);
  command_2=0;

  if(cin.peek()!='\n'){
    cin >> ws;
    if(isdigit(cin.peek())){
      cin>>command_2;
    }else{
      //kasta fel h�r?
    }
  }
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

       if(command_2!=0){
          temporary_expression_ = list.at(command_2-1);
          cout << temporary_expression_.evaluate(table) << "\n";
       }else{
          cout << current_expression_.evaluate(table) << "\n";
       }

   }else if (command_ == 'P'){

      if(command_2!=0){
        temporary_expression_ = list.at(command_2-1);
        cout << temporary_expression_.get_postfix() << "\n";
      }else{
        cout << current_expression_.get_postfix() << "\n";
      }
  
   }else if (command_ == 'I'){

          if(command_2!=0){
           temporary_expression_ = list.at(command_2-1);
           cout << temporary_expression_.get_infix() << "\n";
          }else{
            cout << current_expression_.get_infix() << "\n";
          }  

   }else if (command_ == 'L'){
          for(vector<Expression>::iterator it = list.begin(); it != list.end(); ++it) {
              cout << it-list.begin()+1 << ": " << it->get_infix() << endl;
          }
    }else if (command_ == 'T'){
       if(command_2!=0){
         temporary_expression_ = list.at(command_2-1);
         temporary_expression_.print_tree(cout);
	 cout << "\n";
       }else{
            current_expression_.print_tree(cout);
	    cout << "\n";
       }
   
   }else if (command_ == 'N'){
      cout << list.size() << endl;
   }else if (command_ == 'A'){
      current_expression_ = list.at(command_2-1);       //Gör uttryck n till aktuellt uttryck
      current_expression_index_ = command_2-1;
   }else if (command_ == 'R'){

          if(command_2!=0){
            list.erase(list.begin()+command_2-1);  
          }else{
            list.erase(list.begin()+current_expression_index_);
          } 

   }else if (command_ == 'V'){
      table.list(cout);          //Lista alla variabler
   }else if (command_ == 'X'){
      table.clear();             // Radera alla variabler
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
     try{
       current_expression_ = make_expression(infix);
       list.push_back(current_expression_);
       current_expression_index_=list.size()-1;
     }catch (const exception& e){
       cout << "Undantag f�ngat: " << e.what();
     }
   }
   else
   {
      cout << "Felaktig inmatning!\n";
   }
}

