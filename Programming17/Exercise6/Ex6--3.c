#include <stdio.h>


int start, end, result;


int fib(int n){
	if (n <= 1){
		return 1;
	}else{
		return fib(n - 1) + fib(n - 2);
	}
}


int main(){
	printf("\n\n====================\n");
	
	printf("Enter starting number: ");
	scanf("%i", &start);

	printf("Enter ending number: ");
	scanf("%i", &end);

	for (start; start <= end; start++){
		result = fib(start);
		printf("%i : %i\n", start, result);
	}

	printf("\n====================\n\n");	
	return 0;
}
