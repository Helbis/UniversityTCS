#include <stdio.h>
#include <stdlib.h>


#ifndef SIZE
#define SIZE 100
#endif

/*
5. Write a quicksort function and join it with the program
written in tasks 1-4. Within the program,
extract the file that contains all sort functions.
*/

float numlist[SIZE];


void QuickSort(float *arr, int low, int high);

int partition(float *A, int low, int high);


int main(void){
	printf("\n\n====================\n");
	
	for (int i = 0; i < SIZE; ++i){
		numlist[i] = rand() % 1000;

		if (i % 12 != 0){
			printf(" %.2f |", numlist[i]);
		}else{
			printf("\n %.2f |", numlist[i]);
		}
	}

	QuickSort(numlist, 0, SIZE - 1);

	printf("\n\n~~~Sorted: \n\n");

	for (int i = 0; i < SIZE; ++i){
			if (i % 12 != 0){
				printf(" %.2f |", numlist[i]);
			}else{
				printf("\n %.2f |", numlist[i]);
			}
		}

	printf("\n====================\n\n");	
	return 0;
}


void QuickSort(float *arr, int low, int high){
	//high is in the first iteration the last index

	if (low < high){
		int p = partition(arr, low, high);
        QuickSort(arr, low, p - 1 );
        QuickSort(arr, p + 1, high);
	}
}

int partition(float *A, int low, int high){
	int pivot = A[high];
	int i = low - 1;
	float temp;

	for (int j = low; j < high - 1; j++){
		if (A[j] < pivot){
		i++;

		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		}
	}

	if (A[high] < A[i + 1]){
		temp = A[i + 1];
		A[i + 1] = A[high];
		A[high] = temp;
	}
    
	return ++i;
}
