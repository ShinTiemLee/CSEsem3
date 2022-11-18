#include <stdio.h>
typedef struct{
		double a,b;
	} complex;
complex * add(double a, double b, double c,double d,complex* ptr);
complex * sub(double a, double b, double c,double d,complex* ptr);
complex * mul(double a, double b, double c,double d,complex* ptr);
int main(){
	complex n1,n2,n_add,n_sub,n_mul;
	complex *ptr_add=&n_add;
	complex *ptr_sub=&n_sub;
	complex *ptr_mul=&n_mul;
	printf("Enter the real part of the first complex number: ");
	scanf("%lg",&n1.a);
	printf("Enter the imaginary part of the first complex number: ");
	scanf("%lg",&n1.b);
	printf("Enter the real part of the second complex number: ");
	scanf("%lg",&n2.a);
	printf("Enter the imaginary part of the second complex number: ");
	scanf("%lg",&n2.b);
	ptr_add=add(n1.a,n1.b,n2.a,n2.b,ptr_add);
	printf("\nThe sum is (%.2lg) + (%.2lg)i",ptr_add->a,ptr_add->b);
	ptr_sub=sub(n1.a,n1.b,n2.a,n2.b,ptr_sub);
	printf("\nThe difference is (%.2lg) + (%.2lg)i",ptr_sub->a,ptr_sub->b);
	ptr_mul=mul(n1.a,n1.b,n2.a,n2.b,ptr_mul);
	printf("\nThe product is (%.2lg) + (%.2lg)i",ptr_mul->a,ptr_mul->b);
	return 0;
}
complex * add(double a, double b, double c,double d,complex* ptr){
	ptr->a=a+c;
	ptr->b=b+d;
	return ptr;
}
complex * sub(double a, double b, double c,double d,complex* ptr){
	ptr->a=a-c;
	ptr->b=b-d;
	return ptr;
}
complex * mul(double a, double b, double c,double d,complex* ptr){
	ptr->a=(a*c-(b*d));
	ptr->b=(a*d+c*b);
	return ptr;
}