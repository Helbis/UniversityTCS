#include <stdio.h>


#define MAX_VAL 1000


/*
1. A twin prime is a prime number that differs
from another prime number by two.
Some examples of twin prime pairs are
(3, 5), (5, 7), (11, 13), (17, 19), (29, 31) and (41, 43).
Write a program that stores 20 twin primes larger than 'a'
in an array and displays them on the screen.
'a' is any positive integer, entered with the the keyboard,
smaller than 1000. The program should be immune to improper
syntax (for example other characters entered)
or to numbers with the values out of range. 
*/


int a = MAX_VAL + 1;
int primes[MAX_VAL];
int twins[MAX_VAL / 2][2];


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
	
	char *msg;
	char *m;

	do{
		printf("Please enter 'a': ");
		m = fgets(msg, 80, stdin);
		sscanf(msg, "%i", &a);
	}while(a > MAX_VAL);


	//Prime numbers calculation
	int i = 0, j = a, k = 0;
	while(1){
		if (is_prime(j) && j > a){
			primes[i] = j;

			if ((i >= 1) && (primes[i-1] + 2 == primes[i])){
				twins[k][0] = primes[i - 1];
				twins[k][1] = primes[i];
				
				printf("twin primes: (%i, %i)\n", twins[k][0], twins[k][1]);
				// printf("\ttwins: (%i, %i)\n", twins[k][0], twins[k][1]);
				if (k >= 20){
					break;
				}
				
				k++;
			}
			// printf("prime: %i\n", primes[i]);
			i++;
		}
		j++;
	}

	printf("\n\t~INFO~\n");
	printf("Number of prime numbers: %i\n", i);
	printf("Number of prime twins:   %i\n", k);


	printf("\n====================\n\n");	
	return 0;
}
