#include<stdio.h>
#include <math.h>

/*
Write a program that calculates an area
of any geometric figure.
*/

typedef struct Triangle{
  float A[2] = {};
  float B[2] = {};
  float C[2] = {};

  float vertice = {{}, {}, {}};

  float area;

  float distAB;
  float distAC;
  float distBC;
} triangle;


double angle;


void triArea(Triangle *triangle);
char check_lowest(Triangle *triangle);
void translate(float x, float y, Triangle *triangle);
void rotate(float *angle, float []);
char check_highest(Triangle *triangle);


int main() {
  printf("\n======================\n");

  printf("Please enter points of triangle\nby following the lines\n");
  printf("in cartesian form (x, y)");

  int i =0;
  for (i; i < 3; i++) {
    printf("\n%i : ", i);
    scanf("%f, %f", &triangle.vertice[i][0], &triangle.vertice[i][1]);
  }

  triArea(&triangle);

  printf("Area of given triangle: %.3f",triangle.area);

  printf("\n======================\n");
  return 0;
}


void triArea(Triangle *triangle){
  check_lowest(Triangle *triangle);
  translate(float x, float y, Triangle *triangle);
  rotate(float *angle, float []);
  check_highest(Triangle *triangle);


  triangle.area = result;
}


char check_lowest(Triangle *triangle){
  /*
  Function that from given triangle returns lowest point in form of:
  'A' || 'B' || 'C' or if they are multiple points at the same level:
  'co-AC' || 'co-AB' || 'co-BC'
  */

  short unsigned int AlessB = (triangle.A[1] < triangle.B[1]) ? 1:0;
  short unsigned int AlessC = (triangle.A[1] < triangle.C[1]) ? 1:0;
  short unsigned int BlessC = (triangle.B[1] < triangle.C[1]) ? 1:0;

  short unsigned int AeqB = (triangle.A[1] == triangle.B[1]) ? 1:0;
  short unsigned int AeqC = (triangle.A[1] == triangle.C[1]) ? 1:0;
  short unsigned int BeqC = (triangle.B[1] == triangle.C[1]) ? 1:0;

  if(AlessB && AlessC){
    /* A is the lowest point! */
    return 'A';
  }else if(BlessC){
    /* B is the lowest point! */
    return 'B';
  }else{
    /* C is the lowest point! */
    return 'C';
  }
}


void translate(float x, float y, Triangle *triangle){

}


void rotate(float *angle, float []){

}


int check_highest(Triangle *triangle){

  /*
  Function that from given triangle returns highest point in form of:
  'A' || 'B' || 'C' or if they are multiple points at the same level:
  'co-AC' || 'co-AB' || 'co-BC'
  */

    short unsigned int AmoreB = (triangle.A[1] > triangle.B[1]) ? 1:0;
    short unsigned int AmoreC = (triangle.A[1] > triangle.C[1]) ? 1:0;
    short unsigned int BmoreC = (triangle.B[1] > triangle.C[1]) ? 1:0;

    short unsigned int AeqB = (triangle.A[1] == triangle.B[1]) ? 1:0;
    short unsigned int AeqC = (triangle.A[1] == triangle.C[1]) ? 1:0;
    short unsigned int BeqC = (triangle.B[1] == triangle.C[1]) ? 1:0;

    if(AmoreB && AmoreC){
      /* A is the highest point! */
      return 'A';
    }else if(BmoreC){
      /* B is the highest point! */
      return 'B';
    }else{
      /* C is the highest point! */
      return 'C';
    }
}
