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

	printf("Indata innehöll: \n\t%d alfabetiska tecken\n\t%d siffertecken \n\t%d interpunktionstecken\n\t%d vita tecken\n\t%d tecken totalt\n", alpha, digit, punct, space, total);

	return 0;
}