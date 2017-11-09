#include <stdio.h>


/*
 Write a program that calculates the sum of arbitrary n real numbers.
*/


int main(){
	printf("\n\n====================\n");

	printf("Please enter numbers below, when done enter 0 for quiting.\n");

	char theChar;
	float num = 0, sum = 0;

	do {
		scanf("%f", &num);

		sum += num;
	}while (num != 0);

	printf("%.3f\n", sum);

	printf("\n====================\n\n");
	return 0;
}
