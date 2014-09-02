#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

	double temperature;
	printf("Ge en temperatur i Kelvin: ");
	scanf("%lf", &temperature);

	while(temperature!=0){
		printf("%.2f Kelvin motsvarar", temperature);
		//printf("273.15 Kelvin motsvarar 0.00 grader Celsius eller 32.00 grader Fahrenheit.
		printf("Ge en temperatur i Kelvin: ");
		scanf("%lf", &temperature);
	}
	
		printf("Slut.");
		return 0;	
		
	}