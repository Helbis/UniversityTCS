#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
2. Write a program that calculates the value of the expression W(n),
while n represents the natural numbers.
Change the program into a function, use it to write another program
that writes into an array the following natural numbers within
the range of ⟨a, b⟩ and their corresponding values of W(n).
Print the results on the screen,
using the pre-written procedure to display the results. 
*/
float *array;
unsigned long int a, b;
char continue_ans;
unsigned int size;


float W(unsigned long int n);
void WtoArray(unsigned long int a, unsigned long int b, float *parray);
void printArray(float *array, unsigned int size);


int main(void){
	printf("\n\n====================\n");
	

	do{
		printf("Enter starting number (natural number): ");
		scanf("%ld", &a);

		printf("Enter ending number (natural number): ");
		scanf("%ld", &b);

		/*Invalid input correction*/
		if (a >= b){
			printf("Sorry your input numbers were wrong,\nplease try again.\n\n");
			continue;
		}else{
			size = b - a + 1;
			array = (float *) malloc(size);

			WtoArray(a, b, array);
			printArray(array, size);

			printf("Do you want to continue? [y/n] : ");
			scanf("%s", &continue_ans); 
			if (continue_ans == 'y' || continue_ans == 'Y'){
				continue;
			}else{
				return 0;
			}
		}
	}while(1);


	printf("\n====================\n\n");	
	return 0;
}


float W(unsigned long int n){
	float result = 0;

	if (n % 2 == 0){
		result += 0.5 * n + pow(n, 2);
	}else{
		result += n * (n - 5);
	}

	return result;
}


void WtoArray(unsigned long int a, unsigned long int b, float *parray){

	register unsigned int i;
	for (i=0; a <= b; ++i, ++a){
		parray[i] = W(a);
	}
}


void printArray(float *array, unsigned int size){

	printf("\n~~DEBUG~~\nsize : %u \n", size);

	register unsigned int i;
	for (i = 0; i < size; ++i){
		printf("%i : %.2f\n", i, array[i]);
	}
}