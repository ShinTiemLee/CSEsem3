#include <stdio.h>
#include <stdlib.h>
#define max_size 5

typedef struct{
	char *a[max_size];
	int *top; 
}stack;

int isFull(stack s){
	if(*(s.top)>=max_size)
	return 0;
	else
	return 1;
}

int isEmpty(stack s){
	if(*(s.top)<0)
	return 0;
	else
	return 1;
}

char pop(stack s){
int chk=isEmpty(s);
if(chk==0){
printf("Stack underflow!");
return;
}
char temp=*s.a[*s.top];
*s.top=*s.top-1;
return temp;
}

void push(stack s){
	char ele;
printf("Enter the element to push: ");
scanf("%c",&ele);
scanf("%c",&ele);
int chk=isFull(s);
if(chk==0){
printf("Stack overflow!");
return;
}
*s.top=*s.top+1;
*s.a[*(s.top)]=ele;
}

void display(stack s){
		for(int i=0;i<=*s.top;i--)
	printf("%c ",*s.a[i]);
}

int main(){
	stack s;
	char ele;
	for(int i=0;i<max_size;i++)
		s.a[i]=(char*)malloc(sizeof(char));
	s.top=(int*)malloc(sizeof(int));
	*(s.top)=-1;
	int opt=0;
	while(opt!=4){
	printf("\n1)push 2)pop 3)display 4)exit");
	scanf("%d",&opt);
	fflush(stdin);
	switch(opt) {
		case 1: 
				push(s);
				break;
		case 2: ele=pop(s);
				if(isEmpty(s))
				printf("The popped element is %c",ele);
				break;
		case 3: display(s);
				break;
		case 4: exit(0);
		default: printf("\nInvaid input\n");
	}
	}
	return 0;

}