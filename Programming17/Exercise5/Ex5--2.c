#include <stdio.h>
#include <string.h>


/*
2. Goldbach's conjecture says that every even number can be
represented as the sum of two primes.
Write a program that verifies
this hypothesis for the first 20 even numbers.
*/

unsigned int num, p;


short int is_prime(int num){
	if (num <= 1) return 0;
	if (num % 2 == 0 && num > 2) return 0;
	    
	register int i;
	for(i = 3; i < num / 2; i+= 2){
		if (num % i == 0){
			return 0;
		}
	}
	return 1;
}


int main(void){
	printf("\n\n====================\n");
	
	printf("Enter a number: ");
	scanf("%i", &num);

	register int i;
	for (i=num-2; i > 1; --i){ /* You have to start with two numbers lower or you'll get 1 at some cases*/
		if (is_prime(i)){
			p = num - i;
			printf("\t%d + %d = %d\n", p, i, num);
			break;
		}
	}

	printf("\n====================\n\n");	
	return 0;
}
