#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int dd;
	int *mm;
	int yy;
} birth;

typedef struct{
	int reg_no;
	char* name;
	char add[30];
} info;

typedef struct{
	char *col_name;
	char uni_name[25];
} col;

typedef struct{
	birth *dob;
	info stu_info;
	col col_info;

}student;

void read(student* ptr ){
	printf("Enter dob in [dd mm yyyy] format: ");
	scanf("%d",&ptr->dob->dd);
	scanf("%d",	ptr->dob->mm);
	scanf("%d",&ptr->dob->yy);
	printf("Enter stu_info in [reg no. name address] format: ");
	scanf("%d\n",&ptr->stu_info.reg_no);
	fgets(ptr->stu_info.name,30,stdin);
	fgets(ptr->stu_info.add,30,stdin);
	printf("Enter college_info in [college name university name] format: ");
	fgets(ptr->col_info.col_name,30,stdin);
	fgets(ptr->col_info.uni_name,30,stdin);
}

void display( student* ptr){
	printf("DOB: %d/%d/%d \n",ptr->dob->dd,*(ptr->dob->mm),ptr->dob->yy);
	printf("Student info: %d",ptr->stu_info.reg_no);
	puts(ptr->stu_info.name);
	puts(ptr->stu_info.add);
	printf("\nCollege info: ");
	puts(ptr->col_info.col_name);
	puts(ptr->col_info.uni_name);

}

int main(){

	printf("Enter the number of students: ");
	int n;
	scanf("%d",&n);
	student *ptr=(student*)malloc(n*sizeof(student));
	for(int i=0;i<n;i++){
	(ptr+i)->dob=(birth*)malloc(sizeof(birth));
	(ptr+i)->dob->mm=(int*)malloc(sizeof(int));
	(ptr+i)->stu_info.name=(char*)malloc(sizeof(char));
	(ptr+i)->col_info.col_name=(char*)malloc(sizeof(char));
	}
	for(int i=0;i<n;i++)
	read(ptr+i);
	for(int i=0;i<n;i++)
	display(ptr+i);

	return 0;
}
