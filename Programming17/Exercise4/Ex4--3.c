#include <stdio.h>


#define True 1
#define False 0


/*
3. Write a program that verifies if
particular number is the prime number.
Change the program into a function and use it to write
another program that puts the prime numbers into an array along
with the numbers divisible
by 23 and prints them on screen within the given range of <a, b>. 
*/
int start, end, size;


int isPrime(unsigned int n);
void numsToArray(int start, int end, int *parray);


int main(void){
	printf("\n\n====================\n");
	
	printf("Enter a starting number and ending: ");
	scanf("%i %i", &start, &end);

	size = end - start + 1;

	int array[size];
	numsToArray(start, end, array);

	printf("\n====================\n\n");	
	return 0;
}


int isPrime(unsigned int n){

	register unsigned int i;
	for (i = n - 1; i > 1; --i){
		if (n % i == 0){
			return False;
		}
	}

	return True;
}


void numsToArray(int start, int end, int *parray){

	int tmp;

	register int i;
	for (i = 0; start <= end; ++i, ++start){
		tmp = isPrime(start) || (start % 23 == 0);

		if (tmp){
			parray[i] = start;
			printf("%i : %i\n", i, start);
		}
	}
}


