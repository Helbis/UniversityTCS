#include<stdio.h>

/*
Write a program that calculates a value of the following function:
http://lidia-js.iis.p.lodz.pl/ITCS/theory/CExercises.php
*/

int main() {
	printf("\n======================\n");

	float x, ans;
	printf("Please enter the x:");
	scanf("%f", &x);

	if((x < -5) || (x > 5)){
		ans = x;
		ans += 5;
		ans *= ans;
		ans -= 10;
	}else{
		ans = x;
		ans *= ans;
		ans *= 2;
		ans += x * 3;
		ans--;
	 }

	 printf("\nYour answer: %.3f", ans);

	 printf("\n======================\n");
	 return 0;
}
