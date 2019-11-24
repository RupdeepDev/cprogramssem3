//Circular queue
//3 changes
//isfull condition,display,and incrementing any front or rear
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef struct qt
{
	int rear;
	int front;
	int ele[MAX];
}queue;

void createqueue(queue *q)
{
	q->front=q->rear=-1;
}
int isFull(queue *p)
{
	if((p->front==p->rear+1)||(p->front==0 && p->rear==MAX-1))
	return 1;
	else return 0;
}
int isEmpty(queue *p)
{
	if(p->front==-1)
	return 1;
	else return 0;
}
void enqueue(queue *p,int ele)
{
	if(isFull(p))
	printf("Overflow");
	else
	{
		if(isEmpty(p))
		p->front=p->rear=0;
		else p->rear=(p->rear+1)%MAX;
		p->ele[p->rear]=ele;
	}	
}

int dequeue(queue *p)
{
		int z=p->ele[p->front];
		if(p->front==p->rear)
		p->front=p->rear=-1;
		else p->front=(p->front+1)%MAX;
		return z;
}
void display(queue *p)
{
	if(isEmpty(p))
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Queue elements: ");
		if(p->rear>=p->front)
		{
			for(int i=p->front;i<=p->rear;i++)
			{
				printf("%d ",p->ele[i]);
			}
		}
		else
		{
			for(int i=p->front;i<MAX;i++)
				printf("%d ",p->ele[i]);
			
			for(int i=0;i<=p->rear;i++)
				printf("%d ",p->ele[i]);
			
		}
		
	}
	
}
void main()
{
	int ch,ele;
	queue q;
	createqueue(&q);
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter value to be inserted\n");
					  scanf("%d",&ele);
					  enqueue(&q,ele);
					  break;
					  
			case 2: if(isEmpty(&q))
					  printf("Underflow");
					  else printf("Deleted element: %d",dequeue(&q));
					  break;
					  
			case 3: display(&q);
					break;		  
			
			case 4: exit(1);
					  
			default: printf("Wrong choice, enter again");
		}
	}
}		
