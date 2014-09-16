/**
 * Filename: lab1-3.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik		890718-0031	I5
 *			Elisabeth Hanning	900419-2325	I5
 * Date: 160914
 * Description: Counts the number of times different types of signs appear in an inputted string.
 */

#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;

int main(){

	int alpha=0, digit=0, punct=0, space=0, total=0;
	char c;

	while(cin.get(c)){
		if(isalpha(c)){
			++alpha;
		}else if(isdigit(c)){
			++digit;
		}else if(ispunct(c)){
			++punct;
		}else if(isspace(c)){
			++space;
		}
		++total;
	}

	cout << "Indata innehöll: " << endl << endl
	<< setw(6) << alpha << " alfabetiska tecken" << endl
	<< setw(6) << digit << " siffertecken" << endl
	<< setw(6) << punct << " interpunktionstecken" << endl
	<< setw(6) << space << " vita tecken" << endl
	<< setw(6) << total << " tecken totalt" <<endl;

	return 0;
}
