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
 	map<string, int> table;
}

/**
* Insert a new variable and its value in the table
* @param a string containg the name of the variable
* @param a int containing the value of the variable
*/
void Variable_Table::insert(string name, int value){
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
        table.erase(name);
    }
 	
}

/**
* Search the table after the given name
* @param a string containg the named looked for
* @return a boolean, true if the value exist otherwise false
*/
bool Variable_Table::find(std::string name){
	 if(table.empty()){
         throw variable_table_error("Table is empty");
    }else{
        return table.find(name) != table.end();
    }
	
}

/**
* Sets a new value to the variable
* @param a string containg the name of the variable
* @param a int containing the new value of the variable
*/
void Variable_Table::set_value(string name, int value){

   if(table.empty()){
       throw variable_table_error("Table is empty"); 
   }else if(table.find(name) != table.end()){
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
int Variable_Table::get_value(std::string name){
	if(table.empty()){
 		throw variable_table_error("Table is empty");
 	}else{	
 		return table.find(name)->second;
 	}	
}

/**
* Prints out the whole table
* @param a oustream for printing
*/
void Variable_Table::list(std::ostream& out){
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
bool Variable_Table::empty(){
	return table.empty();
}