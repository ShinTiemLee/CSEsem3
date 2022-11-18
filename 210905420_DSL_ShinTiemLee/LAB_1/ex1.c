#include <stdio.h>
double Add(double arr[],int n);
int main(){
	int n,i;
	printf("Enter the number of elements of 1-D array: ");
	scanf("%d",&n);
	double arr[n];
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%lg",&arr[i]);
	double sum=Add(arr,n);
	printf("The sum of the given array is: %g",sum);
	return 0;
}
double Add(double arr[],int n){
	int j;
	double sum=0;
	for(j=0;j<n;j++)
		sum+=arr[j];
	return sum;
}