#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 Calculate the variance σ² and and standard deviation
 for m independent measurements x1,x2, ... , xm (m < 200).
*/


double variance, deviation, sum_of_x = 0.0, sum = 0.0, x_bar = 0.0;
unsigned int m = 0, i;


int main(){
	printf("\n\n====================\n");

	printf("Enter the number of measurements: ");
	scanf("%u", &m);
	double x[200] = {};

	for (i = 0; i < m; i++) {
		x[i] = random();
	}

	for (i = 0; i < m; i++) {
		sum_of_x += x[i];
	}

	x_bar = sum_of_x / m;

	for (i = 0; i < m; i++) {
		sum += pow(x[i] - x_bar, 2);
	}

	variance = pow((m -1), -1) * sum;
	deviation = sqrt(variance);

	printf("variance = %f", variance);
	printf("\ndeviation = %f", deviation);

	printf("\n====================\n\n");
	return 0;
}
