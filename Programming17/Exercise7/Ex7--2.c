#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
2. Write a program that gets a sequence of n integers from the keyboard,
inserts them into an array and displays them on the screen,
then sorts the numbers in a non-descending order using insertion sort (by simple insertion)
and displays the result on the screen.
The program should contain a separate insertion sorting function. 
*/
int n, numlist[10];


void insertionSort(int *nums, int size);


int main(void){
	printf("\n\n====================\n");
	

	printf("How many numbers will you enter? : ");
	scanf("%i", &n);

	for (int i = 0; i < n; ++i){
		scanf("%i", &numlist[i]);
	}

	insertionSort(numlist, n);

	printf("\n\n~~~Sorted: \n\n");

	for (int i = 0; i < n; ++i){
			if (i % 12 != 0){
				printf(" %3i |", numlist[i]);
			}else{
				printf("\n %3i |", numlist[i]);
			}
		}

	printf("\n====================\n\n");	
	return 0;
}


void insertionSort(int *nums, int size){

	int temp;

	if (nums[0] > nums[1]){
		temp = nums[0];
		nums[0] = nums[1];
		nums[1] = temp;
	}
	

	for (int i = 2; i <= size - 1; ++i){
		for (int j = i - 1; j > 0; --j){
			if (nums[j] > nums[j + 1]){
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}
