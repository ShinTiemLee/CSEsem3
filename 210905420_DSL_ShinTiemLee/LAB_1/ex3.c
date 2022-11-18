#include <stdio.h>
#include<stdlib.h>
void read_display_product();
int main(){
	read_display_product();
	return 0;
}
void read_display_product(){
	int p,q,m,n,i,j,k;
	printf("Enter the dimension of the 1st matrix: ");
	scanf("%d %d",&p,&q);
	int a1[p][q];
	printf("Enter the elements of the 1st matrix:\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&a1[i][j]);
		}
	}
	printf("The input matrix is:\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			printf("%d\t",a1[i][j]);
		}
		printf("\n");
	}
	printf("Enter the dimension of the 2nd matrix: ");
	scanf("%d %d",&m,&n);
	int a2[m][n];
	printf("Enter the elements of the 2nd matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a2[i][j]);
		}
	}
	printf("The input matrix is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",a2[i][j]);
		}
		printf("\n");
	}
	if(q!=m){
		printf("The matrices cannot be multiplied");
		exit(0);
	}
	int arr[p][n];
	for(i=0;i<p;i++){
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}
	for(i=0;i<p;i++){
		for(j=0;j<n;j++){
			for(k=0;k<q;k++)
			arr[i][j]+=a1[i][k]*a2[k][j];
		}
	}
	printf("The product of the matrix is:\n");
	for(i=0;i<p;i++){
		for(j=0;j<n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
