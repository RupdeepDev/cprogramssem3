// Linear queue. FIFO-First In First Out
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct qt{
	int rear;
	int front;
	int ele[MAX];
}queue;
void createqueue(queue *q)
{
	q->front=q->rear=-1;
}
int isfull(queue *q)
{
	if(q->rear==MAX-1)
	return 1;
	else return 0;
}
int isempty(queue *q)
{
	if(q->front==-1)
		return 1;
	else return 0;
}
void enqueue(queue *p,int ele)
{
	if(isfull(p))
	printf("Overflow");
	else
	{
		if(isempty(p))
		{
			p->front=p->rear=0;
		}
		else
		{
			p->rear++;
		}
		p->ele[p->rear]=ele;
	}
}
int dequeue(queue *p)
{
	if(isempty(p))
		printf("Underflow");
	else
	{
		int temp;
		temp=p->ele[p->front];
		if(p->front==p->rear)
			p->front=p->rear=-1;
		else p->front++;
		return temp;
	}
}
void display(queue *p)
{
	if(isempty(p))
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Queue elements: ");
		for(int i=p->front;i<=p->rear;i++)
		{
			printf("%d ",p->ele[i]);
		}
	}
	
}
void main()
{
	queue q;
	createqueue(&q);
	int ch,ele;
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
			case 1: printf("Enter the element you want to insert\n");
					scanf("%d",&ele);
					enqueue(&q,ele);
					break;

			case 2: printf("Deleted element: %d",dequeue(&q));
					break;

			case 3: display(&q);
					break;

			case 4: exit(1);

			default: printf("wrong choice\n");

		}		
	}

}
