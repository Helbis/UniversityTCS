#include <stdio.h>
#include <string.h>

#define val 9
#define size 100


/*
1. Write a program that puts into an array the names and 
surnames of n students as well as their addresses and prints
the contents of this array on the screen in three columns. (n<10). 
*/


char fname[size];
char lname[size];
char address[size];
char data[val][size];


int main(void){
	printf("\n\n====================\n");
	

	printf("Input:\n");

	register int i, j, k;
	for (i=0, j=0; i < val; i+=3, j++){
		printf("Student(%i) : ", j+1);
		scanf("%s %s %s", fname, lname, address);

		strcpy(data[i], fname);
		strcpy(data[i+1], lname);
		strcpy(data[i+2], address);
	}

	printf("\nOutput:\n");

	for (k=0; k < val; k+=3){
		printf("%i: ", k);
		printf("%s %s %s\n", data[k], data[k+1], data[k+2]);
	}

	printf("\n====================\n\n");	
	return 0;
}
