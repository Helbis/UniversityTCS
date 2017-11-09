#include <stdio.h>
#define n 3
#define m 3


/*
2. Write a program that puts the elements of 
an A matrix of dimension n to m (n, m < 20) into an array and:
- Calculates and displays matrix of the sum of the row elements
- Calculates and displays matrix of the sum of the column elements
*/

int i, j;
int matrix[n][m];
int rowvector[m], columnvector[n];


void sumColumns(void){
	for (i=0; i < n; ++i){
		for (j=0; j < m; ++j){
			columnvector[i] += matrix[i][j];
		}
	}
}


void sumRows(void){
	for (i=0; i < m; ++i){
		for (j=0; j < n; ++j){
			rowvector[i] += matrix[j][i];
		}
	}
}


int main(void){
	printf("\n\n====================\n");
	

	for (i=0; i < n; ++i){
		for (j=0; j < m; ++j){
			matrix[i][j] = 0;
			rowvector[j] = 0;
		}

		for (j=0; j < m; ++j){
			printf("%i ", matrix[i][j]);	
		}
		printf(" | %i\n", columnvector[i]);
		
		columnvector[i] = 0;
	}


	/* PRINTING 
	for (i=0; i < n; ++i){
		printf("\n");

				printf("%i", rowvector[j]);
		printf("\n%i", columnvector[i]);
	}
	*/
	
	printf("\n====================\n\n");	
	return 0;
}
