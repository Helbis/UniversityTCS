#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_VAL
#define MAX_VAL 1000
#endif


/*
3. Write a program that in user specified range ⟨x1, x2⟩
performs one with the three operations:
- designates prime numbers
- designates twin primes
- verifies Goldbach's conjecture
depending on the choice made by the user.
The program should use a conditional statement switch.
Draw the block structure with the the internal blocks.
*/

int x1, x2;
int primes[MAX_VAL], twins[MAX_VAL / 2][2];
int choice = 1;


short int is_prime(int num);

void Goldbach(int num1, int num2);

void TwinPrimes(int start, int stop);


int main(void){
	printf("\n\n====================\n");
	

	printf("Enter the range: (start, stop) : ");
	scanf("%i %i", &x1, &x2);

	printf("Choose what you wish to do: \n");
	printf("1 -> Evaluate primes in that range.\n");
	printf("2 -> Evaluate twin primes.\n");
	printf("3 -> Verify Goldbach's conjecture.\n\n");

	scanf("%i", &choice);
	printf("choice: %i\n", choice);
	printf("x1: %i\nx2: %i\n", x1, x2);

	switch(choice){
		case 1: {
			for (x1, x2; x1 <= x2; ++x1){
				if (is_prime(x1)){
					printf("%i\n", x1);
				}
			}
			break;
		}

		case 2: {
			TwinPrimes(x1, x2);
			break;
		}

		case 3: {
			Goldbach(x1, x2);
			break;
		}
		default: {
			printf("Invalid input!\n");
			system("ls -la");
		}
	}

	printf("\n====================\n\n");	
	return 0;
}


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


void Goldbach(int num1, int num2){
	int p;

	register int i;
	for (i=num2 - 2; i > num1; --i){ /* You have to start with two numbers lower or you'll get 1 at some cases*/
		if (is_prime(i)){
			p = num2 - i;
			printf("\t%d + %d = %d\n", p, i, num2);
			break;
		}
	}
}


void TwinPrimes(int start, int stop){ 

	int i = 0, k = 0;
	while(1){
		// printf("Inside the loop\n");
		// printf("start: %i\n", start);
		// printf("stop:  %i\n", stop);

		if (start < stop){

			if (is_prime(start)){
				primes[i] = start;
				// printf("Inside the if\n");

				if ((i >= 1) && (primes[i-1] + 2 == primes[i])){
					twins[k][0] = primes[i - 1];
					twins[k][1] = primes[i];
					
					printf("twin primes: (%i, %i)\n", twins[k][0], twins[k][1]);
					// printf("\ttwins: (%i, %i)\n", twins[k][0], twins[k][1]);
					
					k++;
				}
				// printf("prime: %i\n", primes[i]);
				i++;
			}
			start++;
		}else{
			break;
		}
	}
}
