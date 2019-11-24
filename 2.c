//Infix to postfix.Incomplete
#include<stdio.h>
#define MAX 20
typedef struct st
{
	int top;
	char ele[MAX];
}stack;
void createstack(stack *p)
{
	p->top=-1;
}
int isFull(stack *p)
{
	if(p->top==MAX-1)
	return 1;
	else return 0;
}
void push(stack *p,int val)
{
	if(isFull(&s))
		printf("Stack is full, cannot push element\n");
	else
	{
		p->top++;
		p->ele[p->top]=val;
	}
}
int isEmpty(stack *p)
{
	if(p->top==-1)
	return 1;
	else return 0;
}
int pop(stack *p)
{
	if(isEmpty(&s))
		printf("Stack is empty, cannot pop element\n");
	else
	{
		int z;
		z=p->ele[p->top];
		p->top--;
		return z;
	}	
}
void display(stack *p)
{
	if(isEmpty(&s))
		printf("Stack is empty, cannot display element\n");
	else
	{
		int i=0;
		printf("The elements of the stack are: ");
		while((p->top)-i>=0)
		{
			printf("%d ",p->ele[(p->top)-i]);
			i++;
		}
	}	
}
void infixtopostfix(char *i,char *p)
{
	stack s;
	createstack(&s);
	while(*i!='\0')
	{
		if(*i=='(')
		{
			push(&s,*i);
			i++;
		}
		else if(*i==')')
		{
			while(s.ele[s.top]!='(' && isempty())
		}
	}
}