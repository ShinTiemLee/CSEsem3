#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

typedef struct {
char str[max];
int *rear,*front;
} deques;

void rinsertdeque(deques* deque,char ele){
	if((*(deque->rear))==max)
		printf("Queue overflow");
	else{
		(deque->str[*(deque->rear)])=ele;
		*(deque->rear)+=1;
	}
}

void linsertdeque(deques* deque){
	if((*(deque->rear))==max)
		printf("Queue overflow");
	else{
		char ele;
		printf("Enter element: ");
		scanf("%c",&ele);
		for(int j=*(deque->rear);j>=*(deque->front);j--)
			(deque->str[j+1])=(deque->str[j]);
		*(deque->rear)+=1;
		(deque->str[*(deque->front)])=ele;
		
	}
}

char ldeletedeque(deques* deque){
	if(*(deque->rear)==*(deque->front)){
		return '!';
	}
	else{
		char temp;
		temp=(deque->str[*(deque->front)]);
		for(int i=*(deque->front);i<=*(deque->rear)-1;i++)
			(deque->str[i])=(deque->str[i+1]);
		(*(deque->rear))--;
		return temp;
	}
}

char rdeletedeque(deques* deque){
	if(*(deque->rear)==*(deque->front)){
		return '!';
	}
	else{
		char temp;
		temp=(deque->str[*(deque->rear)-1]);
		(*(deque->rear))--;
		return temp;
	}
}

void displaydeque(deques* deque){
	for (int i=*(deque->front);i<*(deque->rear);i++)
		printf("\n%c",deque->str[i]);
}

int main(){
	deques deque;
	deque.rear=(int*)malloc(sizeof(int));
	deque.front=(int*)malloc(sizeof(int));
	*(deque.rear)=0;
	*(deque.front)=0;
	int opt;
	char* x=(char*)malloc(20*sizeof(char));
	printf("\nEnter string: ");
	scanf("%s",x);
	for(int i=0;i<strlen(x);i++)
		rinsertdeque(&deque,x[i]);
	int flag=0;
	char a,b;
	for(int i=0;i<=strlen(x)/2;i++){
		a=ldeletedeque(&deque);
		b=rdeletedeque(&deque);
		if(a!=b)
			flag=1;
	}
	if(flag==0)
		printf("The string is palindrome");
	else
		printf("The string is not palindrome");
	
	
	return 0;
}