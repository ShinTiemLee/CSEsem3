#include <stdio.h>
#include "stacklib.h"

char cpop(char stack[],int *top){
	if(*top<0){
		printf("Stack underflow!");
		return NULL;
	}
	return stack[(*top)--];
}