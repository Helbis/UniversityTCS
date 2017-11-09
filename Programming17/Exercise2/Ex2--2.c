#include <stdio.h>
#include <math.h>

/*
Write a program that returns the sum of the series
with an accuracy of e=0.0001.
*/

double n = 1.0, added, accuracy = 1e-4, sum = 0.0;

int main(){
	printf("\n\n====================\n");

	do {
		added = pow((n*n + n), -1);
		sum += added;

		n++;
	} while(added > accuracy);

	printf("n: %f\n", n);
	printf("sum: %f", sum);

	printf("\n====================\n\n");
	return 0;
}
