#include <stdio.h>
#include <math.h>


#define A 1.0
#define B 1.0
#define C 1.0
#define beta 1.0
#define epsilon 1e-1


/*
1. There is given a function:
As long as the parameters A,B,C are positive, this function is decreasing.
Write a program that tabulates the function above with the step
specified by Delta x. Tabulating should be finished when
the f(x) value decreases below the specified threshold ε.
*/

/*const float epsilon = 1e-1, A = 1, B = 1, C = 1, beta = 1; */
float result;


float f(float x){
	float upper = A * exp(-beta * x);
	float lower = B * pow(x, 2) + C;
	result = upper / lower;

	return result;
}


int main(void){
	printf("\n\n====================\n");
	
	register float x; x = 1;
	while(f(x) >= epsilon){

		if(getchar()){
			printf("%.2f\t%.2f\n", x, result);
		}
		
		x++; 
	}

	printf("\n====================\n\n");	
	return 0;
}
