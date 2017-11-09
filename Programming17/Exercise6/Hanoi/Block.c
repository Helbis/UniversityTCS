#include <stdio.h>


extern void gunwo(void){

	register int i;
	for (i = 0; i < 10; ++i){
		printf("%i | ", i);
	}
}