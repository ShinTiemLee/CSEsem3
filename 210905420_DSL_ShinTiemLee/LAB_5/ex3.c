#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_size 20

typedef struct {
	char *a[max_size];
	int *top;
} stack;

char pop(stack s){
char temp=*s.a[*s.top];
*s.top=*s.top-1;
return temp;
}

void push(stack s,char ele){
*s.top=*s.top+1;
*s.a[*(s.top)]=ele;
}

void display(stack s){
	for(int i=0;i<=*s.top;i++)
	printf("%c ",*s.a[i]);
}

int main(){
	stack s;
	int flag=0;
	char ele[max_size];
	char str[max_size];
	for(int i=0;i<max_size;i++)
		s.a[i]=(char*)malloc(sizeof(char));
	s.top=(int*)malloc(sizeof(int));
	*(s.top)=-1;
	printf("Enter the string ");
	fgets(str,20,stdin);
	for(int i=0;i<strlen(str)-1;i++)
		push(s,str[i]);
	for(int i=0;i<strlen(str)-1;i++)
		ele[i]=pop(s);
	for(int i=0;i<strlen(str)-1;i++){
	if(ele[i]!=str[i]){
		flag=1;
		break;
	}}
	if(flag==1)
		printf("The string is not a palindrome");
	else
			printf("The string is a palindrome");
	


	return 0;
	}
