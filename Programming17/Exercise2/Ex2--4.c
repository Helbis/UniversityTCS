#include <stdio.h>
#include <math.h>


double left, right;
int a, b;


int main(){
	printf("\n\n====================\n");

	printf("Enter range for check (start stop): ");
	scanf("%i %i", &a, &b);

	for (a; a < b; a++) {

		left = pow(a, 3) + 20 * a;
		right = 3 * pow(a, 2) + 370;

		printf("%.2f < %.2f\n", left, right);

		if(left >= right){
			printf("It's not working!\nFor n = %i\n\n", a);
		}
	}

	printf("\n====================\n\n");
	return 0;
}
