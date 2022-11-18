#include <stdio.h>
#include "stacklib.h"

void ipush(int *stack,int *top,int max,int ele){
	if(*top>=max)
		printf("Stack overflow!");
	else
		stack[++(*top)]=ele;
}