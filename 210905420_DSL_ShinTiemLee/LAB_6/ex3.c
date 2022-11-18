#include <stdio.h>
#include <stdlib.h>
#define max 50

void push1(int *a,int *top1,int *top2,int ele){
	if(*top1+1==*top2)
		printf("Stack overflow!");
	else{
		a[++(*top1)]=ele;
	}
}

void push2(int *a,int *top1,int *top2,int ele){
	if(*top1==*top2-1)
		printf("Stack overflow!");
	else{
		a[--(*top2)]=ele;
	}
}

int pop1(int *a,int *top1){
	if(*top1<0){
		printf("Stack Underflow!");
		return -1;
	}
	else{
		return a[(*top1)--];
	}
}

int pop2(int *a,int *top2){
	if(*top2>max-1){
		printf("Stack Underflow!");
		return -1;
	}
	else{
		return a[(*top2)++];
	}
}

void display1(int *a,int *top1){
	for(int i=*top1;i>=0;i--){
		printf("%d ",a[i]);
	}
}

void display2(int *a,int *top2){
	for(int i=*top2;i<=max-1;i++){
		printf("%d ",a[i]);
	}
}

int main(){
	int a[max];
	int* top1;
	int *top2;
	top1=(int*)malloc(sizeof(int));
	top2=(int*)malloc(sizeof(int));
	*top1=-1;
	*top2=max;
	int opt,ele;
	while(1){
	printf("\n1)push stack1	2)pop stack1	3)push stack2	4)pop stack2	5)display stack1	6)display stack2	7)exit");
	scanf("%d",&opt);
	switch (opt){
	case 1:	printf("\nEnter the element to push:");
			scanf("%d",&ele);
			push1(a,top1,top2,ele);
			break;
	case 2:	printf("\nThe popped element is %d",pop1(a,top1));
			break;
	case 3:	printf("Enter the element to push:");
			scanf("%d",&ele);
			push2(a,top1,top2,ele);
			break;
	case 4:	printf("\nThe popped element is %d",pop2(a,top2));
			break;
	case 5:	display1(a,top1);
			break;		
	case 6:	display2(a,top2);
			break;	
	default: exit(0);
	};
	}
	return 0;
}