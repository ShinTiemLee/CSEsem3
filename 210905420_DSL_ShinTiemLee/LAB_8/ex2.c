#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5

typedef struct {
char* str[max];
int *rear,*front;
} deques;

void rinsertdeque(deques* deque){
	if((*(deque->rear))==max)
		printf("Queue overflow");
	else{
		char* ele=(char*)malloc(20*sizeof(char));
		printf("Enter element: ");
		scanf("%s",ele);
		(deque->str[*(deque->rear)])=ele;
		*(deque->rear)+=1;
	}
}

void linsertdeque(deques* deque){
	if((*(deque->rear))==max)
		printf("Queue overflow");
	else{
		char* ele=(char*)malloc(20*sizeof(char));
		printf("Enter element: ");
		scanf("%s",ele);
		for(int j=*(deque->rear);j>=*(deque->front);j--)
			(deque->str[j+1])=(deque->str[j]);
		*(deque->rear)+=1;
		(deque->str[*(deque->front)])=ele;
		
	}
}

char* ldeletedeque(deques* deque){
	if(*(deque->rear)==*(deque->front)){
		return "NULL";
	}
	else{
		char* temp=(char*)malloc(20*sizeof(char));
		temp=(deque->str[*(deque->front)]);
		for(int i=*(deque->front);i<=*(deque->rear)-1;i++)
			(deque->str[i])=(deque->str[i+1]);
		(*(deque->rear))--;
		return temp;
	}
}

void displaydeque(deques* deque){
	for (int i=*(deque->front);i<*(deque->rear);i++)
		printf("\n%s",deque->str[i]);
}

int main(){
	deques deque;
	deque.rear=(int*)malloc(sizeof(int));
	deque.front=(int*)malloc(sizeof(int));
	for(int i=0;i<max;i++)
	deque.str[i]=(char*)malloc(20*sizeof(char));
	*(deque.rear)=0;
	*(deque.front)=0;
	int opt;
	char* x=(char*)malloc(20*sizeof(char));
	while(1){
	printf("\n1)left insert	2)right linsert	3)left delete	4)display	5)exit");
	scanf("%d",&opt);
	switch(opt){
	case 1:	linsertdeque(&deque);
	break;
	case 2:rinsertdeque(&deque);
	break;
	case 3:	
	 x=ldeletedeque(&deque);
	if(!strcmp(x,"NULL"))
		printf("Queue underflow");
	else
		printf("Deleted element is %s",x);
	break;
	case 4:	displaydeque(&deque);
	break;
	default: exit(0);
	};
	}
	return 0;
}