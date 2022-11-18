#include <stdio.h>
#include <stdlib.h>

typedef struct S_NODE{
	int data;
	struct S_NODE* next;
}NODE;
typedef NODE* node;

node getnode(){
	node get=(node)malloc(sizeof(NODE));
	return get;
}

node add(node list,int x){
	
	node temp=getnode();
	temp->data=x;
	temp->next=NULL;
	if(list==NULL){
		list=temp;
	}
	else{
	node walk=list;
		while(walk->next!=NULL)
			walk=walk->next;
		walk->next=temp;
	}
	
	return list;
}

node UNION (node list1,node list2){
	node uni;
	for(node i=list1;i->next!=NULL;i=i->next){
		uni=add(uni,i->data);
	}
	for(node i=list2;i->next!=NULL;i=i->next){
		for(node j=list1;j->next!=NULL;j=j->next){
			if(j->data!=i->data)
			uni=add(uni,i->data);
	}
	}
	
	return uni;
}

/*for(i=list;i->next!=NULL;i=i->next)
					printf("\t%d",i->data);
				printf("\t%d",i->data);
				break;*/

int main(){
	node list1,list2,uni, inter,i;
	int x;
	int opt;
	list1=list2=uni=NULL;
	while(1){
	printf("\n1)add1	2)add2	3)union	4)intersection	5)exit");
	scanf("%d",&opt);
	switch (opt){
		case 1: printf("Enter element to add: ");
	scanf("%d",&x);
	list1=add(list1,x);

				break;
		case 2:	printf("Enter element to add: ");
	scanf("%d",&x);
	list2=add(list2,x);
				break;
		case 3: uni=UNION(list1,list2);
				for(i=uni;i->next!=NULL;i=i->next)
					printf("\t%d",i->data);
				printf("\t%d",i->data);
				break;
		case 5: exit(0);
	}
}


}