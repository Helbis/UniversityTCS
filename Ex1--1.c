#include<stdio.h>

/*
Write a program that displays any text on the screen.
The user should enter the displayed text from the keyboard.
*/

char *text;

int main() {
  printf("\n\n======================\n");

  printf("Please enter the text you wish to display:\n");
  scanf("%s", &text);

  printf("%s\n", text);

  printf("\n======================\n");
  return 0;
}
