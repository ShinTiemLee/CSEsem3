#include <stdio.h>

 int fibbo(int n){
 if(n==0)
 	return 0;
 if(n<=2){
 	return 1;
 }
 else
 	return fibbo(n-1)+fibbo(n-2);
 }

 int main(){
 	printf("Enter the number of terms:");
 	int n;
 	scanf("%d",&n);
 	for(int i=0;i<n;i++){
 		int f=fibbo(i);
 		printf("%d ",f);
 	}
 	return 0;

 }