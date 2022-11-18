#include<stdio.h>
int large(int arr[],int n);
int main(){
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("The 2nd largest element is: %d",large(arr,n));
	return 0;
}
int large(int arr[],int n){
	int large=arr[0],large2=arr[1];
	if(large<large2 ){
			int temp=large2;
			large2=large;
			large=temp;
		}
	for(int i=2;i<n;i++){
		if(large2<arr[i])
			large2=arr[i];
		if(large<large2 ){
			int temp=large2;
			large2=large;
			large=temp;
		}
		}
	return large2;
}
