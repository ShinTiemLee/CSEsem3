#include <stdio.h>
#include<stdlib.h>
typedef struct S_NODE {
	int data;
	struct S_NODE* next;
}NODE;

NODE* enqueue(NODE* q,int x){
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=NULL;
	if(q!=NULL){
		NODE* walk=q;
		while(walk->next!=NULL)
			walk=walk->next;
		walk->next=temp;
	}
	else{
		q=temp;
	}
	return q;
}

NODE* dequeue(NODE* q){
	int x;
	NODE* temp;
	if(q==NULL){
		printf("Queue empty");
		return q;
	}
	temp=q;
	x=q->data;
	q=q->next;
	printf("Deleted: %d",x);
	free (temp);
	return q;
}

int main(){
	NODE* q;
	int opt,temp;
	q=NULL;
	while(1){
	printf("\n1)enqueue	2)dequeue	3)exit");
	scanf("%d",&opt);
	switch (opt){
		case 1: printf("Enter input: ");
				scanf("%d",&temp);
				q=enqueue(q,temp);
				break;
		case 2:
				q=dequeue(q);
				break;
		case 3: exit(0);
	}
}

}