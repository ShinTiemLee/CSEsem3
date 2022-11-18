#include <stdio.h>
#include <string.h>
#define MAX 20
typedef struct stack
{
int data[MAX];
int top;
}stack;
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int evaluate(char x,int op1,int op2);
int evaluate(char x,int op1,int op2)
{
if(x=='+')
return(op1+op2);
if(x=='-')
return(op1-op2);
if(x=='*')
return(op1*op2);
if(x=='/')
return(op1/op2);
if(x=='%')
return(op1%op2);
}
void init(stack *s)
{
s->top=-1;
}
int empty(stack *s)
{
if(s->top==-1)
return(1);
return(0);
}
int full(stack *s)
{
if(s->top==MAX-1)
return(1);
return(0);
}
void push(stack *s,int x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
int pop(stack *s)
{
int x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}

int main()
{
stack s;
char x;
int op1,op2,val;
init(&s);
printf("Enter the expression(eg: +5*23)\nsingle digit operand and operators only:");
char expr[MAX];
scanf("%s",expr);
for(int i=strlen(expr)-1;i>=0;i--){
x=expr[i];
if(isdigit(x))
push(&s,x - '0');
else
{
op1=pop(&s);
op2=pop(&s);
val=evaluate(x,op1,op2);
push(&s,val);
}
}
val=pop(&s);
printf("\nvalue of expression=%d",val);
return 0;
}