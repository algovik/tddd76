/**
 * Filename: Variable_Table.h
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * The interface declaration file listing all the function
 * that exist in Variable_Table.cc.
 */

#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H
#include <map>
#include <iosfwd>


/**
* A exception class for errors in regards to the Variable_Table class.
*/
class variable_table_error : public std::logic_error {
public:
	explicit variable_table_error(const std::string& whatarg) noexcept
		: logic_error{whatarg} {}

	explicit variable_table_error(const char* whatarg) noexcept
		: logic_error{whatarg} {}
};

/**
* A class for the object Variable_Table
*/
class Variable_Table
{

	protected:
		std::map<std::string,long double> table;
	public:
		Variable_Table();
		void insert(std::string name, long double value);
		void remove(std::string name);
		bool find(std::string name);
		void set_value(std::string name, long double value);
		long double get_value(std::string name);
		void list(std::ostream& out);
		void clear();
		bool empty();

};

#endif
