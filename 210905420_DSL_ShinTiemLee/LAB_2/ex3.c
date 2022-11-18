#include<stdio.h>
void a(int* ptr1,int* ptr2){
	printf("Passing pointers to a function, ptr1=%d ,ptr2=%d\n",*ptr1,*ptr2);
}
int* b(int* ptr1){
	*ptr1+=1;
	return ptr1;
}
int main(){
	int* ptr1,*ptr2,*ptr3;
	int num=500;
	ptr1=&num;
	ptr2=ptr1;
	a(ptr1,ptr2);
	ptr3=b(ptr1);
	printf("Passed pointer is ptr3=%d\n",*ptr3);
	printf("Pointer ptr2 is pointer to ptr1, ptr1=(%d,%p), ptr2=(%d,%p)",*ptr1,ptr1,*ptr2,ptr2);
	return 0;
}
