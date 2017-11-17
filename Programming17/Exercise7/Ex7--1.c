#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#ifndef SIZE
#define SIZE 100
#endif


/*
1. Write a program that generates 100 random integers in range ⟨ 1, 1000 ⟩
and stores them in an array of size 1x100,
then sorts the numbers in a non-descending order using bubble sort (by simple substitution)
and displays the result on the screen.
The program should contain a separated bubble sort function. 
*/
int numlist[SIZE];


void bubbleSort(int nums[SIZE]);


int main(void){
	printf("\n\n====================\n");
	
	
	for (int i = 0; i < SIZE; ++i){
		numlist[i] = floor(random() % 1000);

		if (i % 12 != 0){
			printf(" %3i |", numlist[i]);
		}else{
			printf("\n %3i |", numlist[i]);
		}
	}

	bubbleSort(numlist);

	printf("\n\n~~~Sorted: \n\n");

	for (int i = 0; i < SIZE; ++i){
			if (i % 12 != 0){
				printf(" %3i |", numlist[i]);
			}else{
				printf("\n %3i |", numlist[i]);
			}
		}

	printf("\n====================\n\n");	
	return 0;
}


void bubbleSort(int *nums){
	// Ascending order

	int temp, i, missPlaced, sizeForBubble = SIZE - 1;

	do{
		missPlaced = 0;

		for (i = 0; i < sizeForBubble; ++i){
			if (nums[i] < nums[i + 1]){
				temp = nums[i + 1];
				nums[i + 1] = nums[i];
				nums[i] = temp;

				missPlaced++;
			}
		}
	}while(missPlaced != 0);
}
