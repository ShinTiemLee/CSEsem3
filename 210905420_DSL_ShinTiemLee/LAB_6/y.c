#include <stdio.h>
#include <string.h>
#include "stacklib.h"
#define max 50
typedef enum {lparen,rparen,plus,minus,multiply,divide,mod,operand ,eos} prescedence;

prescedence get_token(char *sym,int *n,char expr[]){
	*sym=expr[(*n)--];
	switch (*sym){
	case '(': return lparen;
				break;
	case ')': return rparen;
				break;
	case '+': return plus;
				break;
	case '-': return minus;
				break;
	case '*': return multiply;
				break;
	case '/': return divide;
				break;
	case '%': return mod;
				break;
	case '\0': return eos;
				break;
	default: return operand;
	};
}

static int isp[]={0,19,12,12,13,13,13,0,0};
static int icp[]={20,19,12,12,13,13,13,0,0};

int main(){
	printf("Enter the expression: ");
	char expr[max];
	char stack[max];
	stack[0]=eos;
	scanf("%s",expr);
	for(int i=0;i<strlen(expr)/2;i++){
		char temp=expr[i];
		expr[i]=expr[strlen(expr)-i-1];
		expr[strlen(expr)-i-1]=temp;
	}
	printf(expr);
	prescedence token;
	char sym;
	int op1,op2;
	int n=strlen(expr)-1;
	int top=0;
	token=get_token(&sym,&n,expr);
	for(token=get_token(&sym,&n,expr);token!=eos;token=get_token(&sym,&n,expr)){
		if(token==operand)
			printf("%c",sym);
		else if(token==lparen){
			while(stack[top]!=rparen)
				printf("%c",cpop(stack,&top));
			char temp=cpop(stack,&top);
		}
		else{
			while(isp[stack[top]]>icp[token])
				printf("%c",cpop(stack,&top));
			cpush(stack,&top,max,token);
		}
	}

	printf("The answer is %d",ans);
	return 0;	
}