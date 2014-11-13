/**
 * Filename: Variable_Table.cc
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * Description: The implementation file with the sourcecode for
 * the class Variable_Table.
 */
#include "Variable_Table.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
* A constructor for an object of the class Variable_Table
* which create a map named table
*/
Variable_Table::Variable_Table(){
 	map<string, long double> table;
}

/**
* Insert a new variable and its value in the table
* @param a string containg the name of the variable
* @param a int containing the value of the variable
*/
void Variable_Table::insert(string name, long double value){
 	table[name]=value;
}

/**
* Removes the variable with the given value from the table
* @param a string containg the name of the variable
*/
void Variable_Table::remove(string name){
  if(table.empty()){
    throw variable_table_error("Table is empty");
  }else{
    if(find(name)){
      table.erase(name);
    }else{
      throw variable_table_error("Variable does not exist");
    }
  } 
}

/**
* Search the table after the given name
* @param a string containg the named looked for
* @return a boolean, true if the value exist otherwise false
*/
bool Variable_Table::find(std::string name) const {
  if(table.empty()){
	   return false; //throw variable_table_error("Table is empty");
    }else{
        return table.find(name) != table.end();
    }
}

/**
* Sets a new value to the variable
* @param a string containg the name of the variable
* @param a int containing the new value of the variable
*/
void Variable_Table::set_value(string name, long double value){
   if(find(name)){
        table.at(name) = value;
    }else{
        throw variable_table_error("Can't update a nonexisting variable");
    }
}

/**
* Gets the  value to the variable in the table
* @param a string containg the name of the variable
* @return a int containing the value of the variable
*/
long double Variable_Table::get_value(std::string name) const {
  if(table.empty()){
    throw variable_table_error("Table is empty");
  }else{
    if(find(name)){
      return table.find(name)->second;
    }else{
      throw variable_table_error("Variable does not exist");
    }
  }
}

/**
* Prints out the whole table
* @param a oustream for printing
*/
void Variable_Table::list(std::ostream& out) const {
	if(table.empty()){
 		throw variable_table_error("Table is empty");
 	}else{
 		for (auto t : table)
    	out << t.first << ": " << t.second << "\n";
 	}

}

/**
* Clears the whole table from all variables
*/
void Variable_Table::clear(){
	if(table.empty()){
 		throw variable_table_error("Table is empty");
 	}else{
 		table.clear();
 	}
}

/**
* Checks if there are any variables in the table
* @return a boolean true if the table is empty, false otherwise
*/
bool Variable_Table::empty() const {
	return table.empty();
}
