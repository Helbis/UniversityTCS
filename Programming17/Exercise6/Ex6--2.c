#include <stdio.h>


int n;
unsigned short form;


unsigned long int iterative(int n){
	unsigned long int result = 1;

	register unsigned short int i;
	for (i = 0; i < n; ++i){
		result *= 2;
	}

	return result;
}


unsigned long int recursive(int n){
	unsigned long int result;

	if (n < 1){
		return 1;
	}else{
		return 2 * recursive(n - 1);
	}
}


int main(){
	printf("\n\n====================\n");
	
	printf("What power would you like to raise 2 to?\n");
	scanf("%i", &n);

	printf("\n1. Iterative\n");
	printf("2. Recursive\n");
	scanf("%hi", &form);

	switch(form){
		case 1:{
			printf("Iterative: %lu\n", iterative(n));
			break;
		}
		case 2:{
			printf("Recursive: %lu\n", recursive(n));
			break;
		}
		default :{
			printf("Nothing was matched.\n");
			break;
		}
	}

	printf("\n====================\n\n");	
	return 0;
}
