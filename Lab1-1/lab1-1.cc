#include <stdio.h>
using namespace std;



int main(){

	int value;
	printf("Ge önskat slutvärde (minst 1): ");
	scanf("%d", &value);
	
	while(value < 1){
		printf("Felaktigt värde, försök igen!\n"); 
		printf("Ge önskat slutvärde (minst 1): ");
		scanf("%d", &value);
	}
	
	printf("\tDEC\tOKT\tHEX\n");
	
	for(int i=1; i<=value; i++){
		printf("\t%d\t%o\t%x \n", i, i, i);		
	}
	
	return 0;
}
