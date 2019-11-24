//Linked Queue
#include<stdio.h>
#include<stdlib.h>
typedef struct st{
	int info;
	struct st *next;
}node;

typedef struct qt
{
	node *front;
	node *rear;
}queue;

void createqueue(queue *q)
{
	q->front=q->rear=NULL;
}

void enqueue(queue *p,int item)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(p->front==NULL)
	{
		p->front=p->rear=ptr;
	}
	else
	{
		(p->rear)->next=ptr;
		p->rear=ptr;
	}
}
int isempty(queue *p)
{
	if(p->front==NULL)
		return 1;
	else return 0;
}



int dequeue(queue *p)
{
	if(isempty(p))
		printf("Queue is empty\n");
	else
	{
		node *temp1=p->front;
		int temp2=(p->front)->info;
		if(p->front==p->rear)
			p->front=p->rear=NULL;

		else p->front=(p->front)->next;
		free(temp1);
		return temp2;
	}
	
}

void display(queue *p)
{
	if(isempty(p))
		printf("Queue is empty");
	
	else
	{
		printf("Queue elements: ");
		node *loc=p->front;
		while(loc!=NULL)
		{
			printf("%d ",loc->info);
			loc=loc->next;
		}
	}
	
}

void main()
{
	queue q;
	createqueue(&q);
	int ch,item,after,count3;
	while(1)
	{
		printf("\n1.Create the queue\n");
		printf("2.Enqueue\n");
		printf("3.Dequeue\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no of elements\n");
					scanf("%d",&count3);
					for(int i=0;i<count3;i++)
					{
						printf("Enter the %dth element: ",(i+1));
						scanf("%d",&item);
						enqueue(&q,item);
					}
					break;

			case 2: printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					enqueue(&q,item);
					break;

			case 3: printf("Deleted element: %d",dequeue(&q));
					break;

			case 4: display(&q);
					break;

			case 5: exit(1);

			default: printf("Wrong choice\n");


		}
	}
}