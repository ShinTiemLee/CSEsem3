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
*(s.top)=*(s.top)+1;
printf("%d\n",*s.top);
*(s.a[*(s.top)])=ele;
printf("boo:\n%d\n",*s.a[*s.top]);
}

void display(stack s){
	for(int i=0;i<=*s.top;i--)
	printf("%d ",*s.a[i]);
}
void delete(stack s,int i){
	for(int j=i;j<*s.top;j++){
		*s.a[j]=*s.a[j+1];
	}
	(*s.top)--;
}

int main(){
	stack s;
	int n,temp,k;
	s.top=(int*)malloc(sizeof(int));
	*s.top=-1;
	for( int i=0;i<max_size;i++)
	s.a[i]=(int*)malloc(sizeof(int));
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Enter the elements");
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		push(s,temp);
	}
	printf("Enter the number of elements to delete:");
	scanf("%d",&k);

	
	while(k!=0){
		printf("what");
		for(int i=0;i<*s.top;i++){
			printf("hohoho");
			if(*s.a[i]<*s.a[i+1]){
				printf("w");
				delete(s,i);
				printf("w");
				k--;
				break;
			}
		}
	}
	display(s);
	return 0;
}
