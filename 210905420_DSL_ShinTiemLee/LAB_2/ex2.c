#include<stdio.h>
#include<stdlib.h>
int* Smallest(int*,int n);
int main(){
	int n,temp;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int *a=(int*)calloc(n,sizeof(int));
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		*(a+i)=temp;
	}
	int *small=Smallest(a,n);
	printf("The smallest element is %d",*small);
	free(a);
	return 0;
}
int* Smallest(int* a,int n){
	int* small=a;
	for(int i=1;i<n;i++){
		if(*small>*(a+i))
			*small=*(a+i);
	}
	return small;
}