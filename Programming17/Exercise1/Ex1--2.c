#include <stdio.h>
#include <math.h>


/*
Write a program that calculates an area
of any geometric figure.
*/

float a, b;


int main(void) {
  printf("\n======================\n");

  printf("Please lengths of sides of triangle: \n");
  scanf("%f %f", &a, &b);

  printf("Area of given triangle: %.3f", 0.5*a*b);

  printf("\n======================\n");
  return 0;
}
