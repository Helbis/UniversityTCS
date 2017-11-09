#include <stdio.h>
// #include "stick.c"
// #include "Block.c"


/*
4. Towers of Hanoi
It is a mathematical game or puzzle.
It consists of three rods, and a number of disks
of different sizes which can slide onto any rod.
The puzzle starts with the disks in a neat stack in
ascending order of size on one rod, the smallest at the top,
thus making a conical shape.
The objective of the puzzle is to move the entire stack to another rod,
obeying the following rules:
Only one disk may be moved at a time.
Each move consists of taking the upper disk
from one of the rods and sliding it onto another rod,
on top of the other disks that may already be present on that rod.
No disk may be placed on top of a smaller disk.
*/

void gunwo(void);
void gunwo2(void);


int main(){
	printf("\n\n====================\n");
	
	gunwo2();

	gunwo();

	printf("\n====================\n\n");	
	return 0;
}
