//Stack implementataion. LIFO-Last In First Out
#include<stdio.h>
#include<stdlib.h>

#define MAX 20
typedef struct st
{
	int ele[MAX];
	int top;
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
	p->top++;
	p->ele[p->top]=val;
}
int isEmpty(stack *p)
{
	if(p->top==-1)
	return 1;
	else return 0;
}
int pop(stack *p)
{
	int z;
	z=p->ele[p->top];
	p->top--;
	return z;
}
void display(stack *p)
{
	printf("The elements of the stack are: ");
	for(int i=p->top;i>=0;i--)
	{
		printf("%d ",p->ele[i]);
	}
}
void search(stack *p)
{
	int s1,flag=0;
	printf("Enter the value to be searched\n");
	scanf("%d",&s1);
	for(int i=p->top;i>=0;i--)
	{
		if(s1==p->ele[i])
		{
			printf("Position:%d\n",i+1);
			flag=1;
		}
	}
	if(flag==0)
	printf("Element not found");
}	
		
	
void main()
{
	int ch,ele;
	stack s;
	createstack(&s);
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Search\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: if(isFull(&s))
					  printf("Stack is full, cannot push element\n");
					  else
					  {
					  		printf("Enter value to be pushed\n");
					  		scanf("%d",&ele);
					  		push(&s,ele);
					  }
					  break;
					  
			case 2: if(isEmpty(&s))
					  printf("Stack is empty, cannot pop element\n");
					  else
					  {
					  		int p1=pop(&s);
					  		printf("Popped element: %d",p1);
					  }
					  break;
					  
			case 3: if(isEmpty(&s))
					  printf("Stack is empty, cannot search element\n");
					  else search(&s);
					  break;
					  
			case 4: if(isEmpty(&s))
					  printf("Stack is empty, cannot display element\n");
					  else
					  display(&s);
					  break;

			case 5: exit(1);
					  
			default: printf("Wrong choice, enter again");
		}
	}
}		
