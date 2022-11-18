 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[25];
	int roll_no;
	float cgpa;
} student;

void read(int n, student* ptr);
void display(int n, student* ptr);
void sort(int n, student* ptr,student* p_sort);

int main(){
	int n;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	student* ptr=(student*) calloc(n,sizeof(student));
	student* p_sort=(student*) calloc(n,sizeof(student));
	read(n,ptr);
	display(n,ptr);
	sort(n,ptr,p_sort);
	printf("\n");
	printf("The sorted list is:\n\n");
	display(n,p_sort);
	return 0;

}

void read(int n, student* ptr){
	for(int i=0;i<n;i++){
		printf("Enter name: ");
		scanf("%s",ptr->name);
		printf("Enter roll no: ");
		scanf("%d",&ptr->roll_no);
		printf("Enter cgpa: ");
		scanf("%f",&ptr->cgpa);
		ptr++;
	}
}

void display(int n, student* ptr){
	for(int i=0;i<n;i++){
		printf("\nName: %s",ptr->name);
		printf("\nRoll no: %d",ptr->roll_no);
		printf("\nCgpa: %.2f\n",ptr->cgpa);
		ptr++;
	}
}

void sort(int n, student* ptr,student* p_sort){
	for(int i=0;i<n;i++){
		*p_sort=*ptr;
		p_sort++;
		ptr++;
	}
	for(int i=0;i<n;i++){
		p_sort--;
		ptr--;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-i-1;j++){
			if(ptr->roll_no>(ptr+1)->roll_no){
				*p_sort=*(ptr+1);
				*(p_sort+1)=*ptr;
			}
			ptr++;
			p_sort++;
		}
		for(int j=i;j<n-i-1;j++){
			ptr--;
			p_sort--;
		}
		ptr++;
		p_sort++;
	}
}
