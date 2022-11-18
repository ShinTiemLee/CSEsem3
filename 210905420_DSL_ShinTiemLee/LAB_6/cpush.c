#include <stdio.h>
#include "stacklib.h"

void cpush(char *stack,int *top,int max,char ele){
	if(*top>=max)
		printf("Stack overflow!");
	else
		stack[++(*top)]=ele;
}