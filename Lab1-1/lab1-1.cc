#include <iostream>
using namespace std;


int main()
{
	int value;
	cout << "Ge önskat slutvärde (minst 1):";
	cin >> value;
	
	while(value < 1){
		cout << endl << "Felaktigt värde, försök igen!" << endl;
		cout << "Ge önskat slutvärde (minst 1):";
		cin >> value;
	}
	
	cout << endl << "DEC       OKT       HEX" << endl << endl;
	
	for(int i=0; i<value; i++){
	cout << i << "       " << i << "       " << i << endl;
	
	}
	
	
	return 0;
}
