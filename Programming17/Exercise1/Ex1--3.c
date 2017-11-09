#include <stdio.h>

/*
Write a program that calculates
an arithmetic average of any two numbers.
*/

int a, b;

int main() {
  printf("\n\n========================\n");

  printf("Please enter two numbers to calculate average\n");
  scanf("%d %d", &a, &b);
  printf("The average is: %d\n", (a+b)/2 );

  printf("\n========================\n\n");
  return 0;
}
