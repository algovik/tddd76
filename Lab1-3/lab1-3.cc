#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main(){
	
	int alpha=0, digit=0, punct=0, space=0, total=0;
	char c;

	while(cin >> noskipws >> c){
		alpha += isalpha(c);
		digit += isdigit(c);
		punct += ispunct(c);
		space += isspace(c);
		total+=1;
	}

	cout << "Indata innehöll: " << endl
	<< "\t" << alpha << "\t alfabetiska tecken" << endl
	<< "\t" << digit << "\t siffertecken" << endl
	<< "\t" << punct << "\t interpunktionstecken" << endl
	<< "\t" << space << "\t vita tecken" << endl
	<< "\t" << total << "\t tecken totalt" <<endl;

	return 0;
}