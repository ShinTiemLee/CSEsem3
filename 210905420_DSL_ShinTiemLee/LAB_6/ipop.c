#include <stdio.h>
#include "stacklib.h"

int ipop(int stack[],int *top){
	if(*top<0){
		printf("Stack underflow!");
		return 0;
	}
	return stack[(*top)--];
}