#include <iostream>
#include <stdio.h>
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
	
	cout << "\tDEC\tOKT\tHEX\n";
	
	for(int i=1; i<=value; i++){
	cout << "\t" <<  dec << i
	<< "\t" << oct << i
	<< "\t" << hex << i << endl;
	}
	
	return 0;
}
