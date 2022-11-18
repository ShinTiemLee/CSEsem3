#include <stdio.h>
int Lsearch(int arr[],int n,int key);
int main(){
	int n,key,pos,i;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the key to search: ");
	scanf("%d",&key);
	pos=Lsearch(arr,n,key);
	if(pos==-1)
		printf("The key does not exist!");
	else
		printf("The key is found in position %d",pos+1);
	return 0;
}
int Lsearch(int arr[],int n,int key){
	int j,pos=-1;
	for(j=0;j<n;j++){
		if(key==arr[j]){
			pos=j;
			break;
		}
	}
	return pos;
}
