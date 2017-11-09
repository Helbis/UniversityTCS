#include <stdio.h>
#include <math.h>


int a(){

	//Natural numbers : N={1, 2, 3, 4, ..., n}
	int n = 1;

	while (pow(1.02, n) <= 1000 * pow(n, 2)) {
		n++;
	}

	return n;
}


int b(){

	//Natural numbers : N={1, 2, 3, 4, ..., n}
	int n = 1;
	float sum = 0;

	while (sum <= 2) {
		sum += pow(n, -1);
		n++;
	}

	return n;
}


int main(){
	printf("\n\n====================\n");

	printf("For n = %i\nthe equality is satisfied.(a)\n", a());
	printf("For n = %i\nthe equality is satisfied.(b)\n", b());


	printf("\n====================\n\n");
	return 0;
}
