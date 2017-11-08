#include <stdio.h>

/*
Write a program that verifies
an identity of the following equation:
(a+b)(a-b) = a²-b². 
*/

int a, b;

int main() {
  printf("\n\n========================\n");

  printf("Please enter two numbers to check the identity\n");
  scanf("%d %d", &a, &b);

  if (((a+b) * (a-b)) == ((a*a) - (b*b))) {
    printf("The identity is TRUE\n");
  }else{
    printf("The identity is FALSE\n");
  }


  printf("\n========================\n\n");
  return 0;
}
