#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int dd,mm,yy;
} birth;

typedef struct{
	int home_no,zipcode;
	char state[20];
} add;

typedef struct{
	char name[25];
	birth dob;
	add address;
} employee;

void read(int n, employee* ptr);
void display(int n, employee* ptr);


int main(){
	printf("Enter the number of employees: ");
	int n;
	scanf("%d",&n);
	employee e[n];
	employee *ptr=e;
	read(n,ptr);
	display(n,ptr);
	return 0;

}

void read(int n, employee* ptr){
	for(int i=0;i<n;i++){
		printf("Enter name: ");
		scanf("%s",ptr->name);
		printf("Enter dob in [dd mm yyyy] format: ");
		scanf("%d",&ptr->dob.dd);
		scanf("%d",&ptr->dob.mm);
		scanf("%d",&ptr->dob.yy);
		printf("Enter address in [house no. zipcode state] format: ");
		scanf("%d",&ptr->address.home_no);
		scanf("%d",&ptr->address.zipcode);
		scanf("%s",ptr->address.state);
		ptr++;
	}
}

void display(int n, employee* ptr){
	for(int i=0;i<n;i++){
		printf("\nName: %s",ptr->name);
		printf("\n DOB: %d/%d/%d",ptr->dob.dd,ptr->dob.mm,ptr->dob.yy);
		printf("\nHouse no.: %d\n Zipcode: %d\n State: %s",ptr->address.home_no,ptr->address.zipcode,ptr->address.state);
		ptr++;
	}
}
