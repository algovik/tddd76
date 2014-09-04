#include <iostream>
#include <stdio.h>
using namespace std;

double kelvin_celsius(double kelv);
double kelvin_fahrenheit(double kelv);

int main(){

	double kelv;
	cout.precision(2);
	cout << "Ge en temperatur i Kelvin: ";
	cin >> kelv;

	while(kelv!=0){
		cout << fixed << kelv << " Kelvin motsvarar " << fixed << kelvin_celsius(kelv)
		<< " grader Celsius eller " << fixed << kelvin_fahrenheit(kelv) << " grader Fahrenheit." << endl
		<< "Ge en temperatur i Kelvin: ";
		cin >> kelv;
	}
	cout << "Slut." << endl;
	return 0;
}

/**
 * Converts a temperature given in Kelvin to Celsius.
 * @param kelv	temperature in Kelvin
 * @return	temperature in Celsius
 */
double kelvin_celsius(double kelv){
	return kelv-273.15;
}

/**
 * Converts a temperature given in Kelvin to Fahrenheit.
 * @param kelv	temperature in Kelvin
 * @return	temperature in Fahrenheit
 */
double kelvin_fahrenheit(double kelv){
	return kelv*1.8-459.67;
}