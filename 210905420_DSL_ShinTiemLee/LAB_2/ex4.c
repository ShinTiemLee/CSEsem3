#include<stdio.h>
#include<stdlib.h>
void read(int ,int, int**);
void display(int,int,int**);
void product(int **,int **,int, int,int **,int ,int);
int main(){
	int p,q,m,n;
	printf("Enter the dimensions of the matrix: ");
	scanf("%d %d",&p,&q);
	printf("Enter the dimensions of the matrix: ");
	scanf("%d %d",&m,&n);
	if(p!=n){
		printf("Error: Dimensions incompatibale for multiplication");
		exit(0);
	}
	int** ptr1,**ptr2,**prod_ptr;
	ptr1=(int**)calloc(p,sizeof(int*));
	for(int i=0;i<p;i++)
		ptr1[i]=(int*)calloc(q,sizeof(int));
	read(p,q,ptr1);
	display(p,q,ptr1);
	ptr2=(int**)calloc(m,sizeof(int*));
	for(int i=0;i<m;i++)
		ptr2[i]=(int*)calloc(n,sizeof(int));
	read(m,n,ptr2);
	display(m,n,ptr2);
	prod_ptr=(int**)calloc(p,sizeof(int*));
	for(int i=0;i<p;i++)
		prod_ptr[i]=(int*)calloc(n,sizeof(int));
	product(prod_ptr,ptr1,p,q,ptr2,m,n);
	display(p,n,prod_ptr);
	return 0;
}

void read(int a, int b, int** ptr){
	printf("Enter the elements:\n");
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			scanf("%d",&ptr[i][j]);
		}
	}
}

void display(int a, int b,int **ptr){
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
		printf("%d\t",ptr[i][j]);
		}
		printf("\n");
	}
}

void product(int** prod_ptr,int** ptr1,int p,int q,int** ptr2,int m,int n){
	printf("The product is:\n");
	for(int i=0;i<p;i++){
		for(int j=0;j<n;j++)
			prod_ptr[i][j]=0;
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<q;k++){
				prod_ptr[i][j]+=ptr1[i][k]*ptr2[k][j];
			}
		}
	}
}
