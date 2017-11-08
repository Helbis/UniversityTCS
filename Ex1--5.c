#include<stdio.h>
#include<math.h>

/*
There are given the two legs of the right-angled triangle a and b.
Calculate in degrees the hypotenuse and angles of the triangle.
*/

float a, b, c, angle1, angle2;


int main() {
  printf("\n======================\n");

  printf("Enter length of triangle's legs seperated by space:\n");
  scanf("%f %f", &a, &b);
  angle1 = (float)atan(a/b) * 180.0 / M_PI;
  angle2 = (float)atan(b/a) * 180.0 / M_PI;
  c = (float)sqrt(pow(a, 2) + pow(b, 2));

  printf("Angle 1: %.3f\n", angle1);
  printf("Angle 2: %.3f\n", angle2);
  printf("Leg a: %.3f\n", a);
  printf("Leg b: %.3f\n", b);
  printf("Leg c: %.3f\n", c);

  printf("\n======================\n");
  return 0;
}
