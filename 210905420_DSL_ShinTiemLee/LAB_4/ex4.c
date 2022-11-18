#include <stdio.h>

void TOH(char s,char d, char a, int* count,int n){
	if(n==1){
	printf("\nMove disk %d from %c to %c",n,s,d);
	*count=*count+1;
	}
	else{
	TOH(s,a,d,count,n-1);
	printf("\nMove disk %d from %c to %c",n,s,d);
	TOH(a,d,s,count,n-1);
	*count=*count+1;
	}
}
int main(){
	int c=0;
	int* count=&c;
	char s='A',d='B',a='C';
	int n;
	printf("Enter the number of disks\n");
	scanf("%d",&n);
	TOH(s,d,a,count,n);
	printf("\nThe number of moves is %d",*count);
	return 0;
}