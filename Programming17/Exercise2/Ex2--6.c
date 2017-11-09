#include <stdio.h>


float num, sum = 0;


int main(){
	printf("\n\n====================\n");


	int i = 0;
	while(1){
		printf("#%i. Please enter a number: ", i + 1);
		scanf("%f", &num);


		if (num == 0){
			printf("Average of numbers entered: %.2f\n", sum / i);
			break;
		}else{
			sum += num;
			i++;
		}
	}


	printf("\n====================\n\n");
	return 0;
}
