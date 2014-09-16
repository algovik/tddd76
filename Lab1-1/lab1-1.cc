/*
 * Filename: lab1-1.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik		890718-0031	I5
 *			Elisabeth Hanning	900419-2325	I5
 * Date: 160914
 * Description: A program that lists decimal, octal and hexadecimal numbers.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	int value;
	cout << "Ge önskat slutvärde (minst 1): ";
	cin >> value;

	while(value < 1){
		cout << "Felaktigt värde, försök igen!\n";
		cout << "Ge önskat slutvärde (minst 1): ";
		cin >> value;
	}

	cout << setw(10) << "DEC"
	<< setw(10) << "OKT"
	<< setw(10) << "HEX" << endl;

	for(int i=1; i<=value; i++){
		cout << setw(10) <<  dec << i
		<< setw(10) << oct << i
		<< setw(10) << hex << i << "\n";
	}

	return 0;
}
