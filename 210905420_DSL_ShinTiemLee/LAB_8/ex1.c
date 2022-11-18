#include <stdio.h>
#include<stdlib.h>
#define max 5

typedef struct {
int a[max];
int *rear,*front;
} apqs;

void insertapq(apqs* apq){
	if((*(apq->rear))==max)
		printf("Queue overflow");
	else{
		int ele;
		printf("Enter element: ");
		scanf("%d",&ele);
		apq->a[*(apq->rear)]=ele;
		*(apq->rear)+=1;
	}
}

int deleteapq(apqs* apq){
	if(*(apq->rear)==*(apq->front)){
		return -1;
	}
	else{
		int i;
		int temp=apq->a[*(apq->front)];
		for( i=*(apq->front);i<=*(apq->rear);i++){
		if(temp>apq->a[i]){
			temp=apq->a[i];
			break;
		}
		}
		if(temp==apq->a[*(apq->front)])
			i=*(apq->front);
		if((*(apq->front) +1)==*(apq->rear))
			(*(apq->rear))--;
		else{
		for(int j=i+1;j<=*(apq->rear);j++)
			apq->a[j-1]=apq->a[j];
		(*(apq->rear))--;
		}
		return temp;
	}
}

void displayapq(apqs* apq){
	for (int i=*(apq->front);i<*(apq->rear);i++)
		printf("\n%d",apq->a[i]);
}

int main(){
	apqs apq;
	apq.rear=(int*)malloc(sizeof(int));
	apq.front=(int*)malloc(sizeof(int));
	*(apq.rear)=0;
	*(apq.front)=0;
	int opt,x;
	while(1){
	printf("\n1)insert	2)delete	3)display	4)exit");
	scanf("%d",&opt);
	switch(opt){
	case 1:	insertapq(&apq);
	break;
	case 2:	
	 x=deleteapq(&apq);
	if(x==-1)
		printf("Queue underflow");
	else
		printf("Deleted element is %d",x);
	break;
	case 3:	displayapq(&apq);
	break;
	default: exit(0);
	};
	}
	return 0;
}