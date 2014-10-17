/**
 * Filename: Variable_Table-test.h
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck 
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * A test file for the file Variable_Test.cc
 */
#include "Variable_Table.h"
#include <iostream>
#include <stdexcept>


using namespace std;

int main()
{

	Variable_Table t;
	t.insert("Anna",10);
	t.insert("Bertil",15);
	t.insert("Cesar",15);
	
	
	cout << t.get_value("Anna");

	//t.remove("Anna");
	t.set_value("Anna",12);
	//t.set_value("Fia",16); //Error

	if(t.find("Ann")){
		cout << "Finns ej" << endl;
	}else if(t.find("Anna")){
		cout << "Finns" << endl;
	}

	cout << endl << t.get_value("Anna")<< endl;

	t.list(cout);

	if(!t.empty()){
		cout << "Listan finns" <<endl;
	}
	t.clear();
	
	if(t.empty()){
		cout << "Listan är tom" <<endl;
	}
	
	return 0;
}