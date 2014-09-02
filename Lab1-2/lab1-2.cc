#include <iostream>
#include <stdio.h>
using namespace std;

double kelvin_celsius(double kelv);
double kelvin_fahrenheit(double kelv);

int main(){

	double kelv, cel, fahr;
	printf("Ge en temperatur i Kelvin: ");
	scanf("%lf", &kelv);

	while(kelv!=0){
		printf("%.2f Kelvin motsvarar %.2f grader Celsius eller %.2f grader Fahrenheit.\n", kelv, kelvin_celsius(kelv), kelvin_fahrenheit(kelv));
		//printf("273.15 Kelvin motsvarar 0.00 grader Celsius eller 32.00 grader Fahrenheit.
		printf("Ge en temperatur i Kelvin: ");
		scanf("%lf", &kelv);
	}
	printf("Slut.\n");
	return 0;
}

double kelvin_celsius(double kelv){
	return kelv-273.15;
}

double kelvin_fahrenheit(double kelv){
	return kelv*1.8-459.67;
}