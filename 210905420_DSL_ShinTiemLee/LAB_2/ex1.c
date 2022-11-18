#include<stdio.h>
void REVERSE(int a[],int n);
int main(){
	int n,i;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	REVERSE(arr,n);
	printf("The reversed array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);	
	return 0;
}
void REVERSE(int a[],int n){
	int temp,i,j=n-1;
	for(i=0;i<n/2;i++){
	temp=*(a+i);
	*(a+i)=*(a+j);
	*(a+j)=temp;
	j--;
	}
}