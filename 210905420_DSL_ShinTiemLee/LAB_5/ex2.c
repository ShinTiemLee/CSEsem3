#include <stdio.h>
#include<stdlib.h>
#define max_size 10

typedef struct {
	int *a[max_size];
	int *top;
} stack;


int pop(stack s){
int temp=*s.a[*s.top];
*s.top=*s.top-1;
return temp;
}

void push(stack s,int ele){
*s.top=*s.top+1;
*s.a[*(s.top)]=ele;
}

void display(stack s){
	printf("The binary form is ");
	for(int i=*s.top;i>=0;i--)
	printf("%d ",*s.a[i]);
}

void convert(int dec,stack s){
int temp;
do{
	temp=dec%2;
	dec=dec/2;
	push(s,temp);
	}while(dec>0);
}


int main(){
	printf("Enter the decimal number: ");
	int dec;
	scanf("%d",&dec);
	stack DecToBin;
	DecToBin.top=(int*)malloc(sizeof(int));
		for(int i=0;i<max_size;i++)
	DecToBin.a[i]=(int*)malloc(sizeof(int));
	*(DecToBin.top)=-1;
	convert(dec,DecToBin);
	display(DecToBin);
	return 0;
	
}