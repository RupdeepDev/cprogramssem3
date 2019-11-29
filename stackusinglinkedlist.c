//Linked Stack
#include<stdio.h>
#include<stdlib.h>
typedef struct st{
	int info;
	struct st *next;
}node;
node *top=NULL;
void push(int item)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(top==NULL)
	{
		top=ptr;
		ptr->next=NULL;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
}

void display()
{
	if(top==NULL)
		printf("List is empty\n");
	else
	{
		node *loc=top;
		printf("Linked Stack: ");
		while(loc!=NULL)
		{
			printf("%d ",loc->info);
			loc=loc->next;
		}
	}
}

void pop()
{
	if(top==NULL)
		printf("Underflow\n");
	else
	{
		node *loc=top;
		printf("Popped element: %d",loc->info);
		top=loc->next;
		free(loc);
	}
	
}
void destroy()
{
	if(top==NULL)
		printf("Underflow\n");
	else
	{
		printf("Popped elements: ");
		node *loc=top;
		node *ptr;
		while(loc!=NULL)
		{
			ptr=loc;
			printf("%d ",ptr->info);
			loc=loc->next;
			free(ptr);
		}
		top=NULL;
	}
	
}
void countnodes() //Counts the no of nodes present in the list
{
	node *loc=top;
	int count1=0;
	while(loc!=NULL)
	{
		count1++;
		loc=loc->next;
	}
	printf("The no of nodes are: %d",count1);
}
void search(int item) //Normal search= Determines the position of an item by incrementing a variable.
{
	node *loc=top;
	int count2=0;
	while(loc!=NULL)
	{
		count2++;
		if(loc->info==item)
			printf("Element found at position: %d\n",count2);
		loc=loc->next;
	}
}

void main()
{
	int ch,item,after,count3;
	while(1)
	{
		printf("\n1.Create the Stack\n");
		printf("2.Push\n");
		printf("3.Pop\n");
		printf("4.Destroy everything\n");
		printf("5.Display\n");
		printf("6.Count the no of nodes\n");
		printf("7.Search any node\n");
		printf("8.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no of elements\n");
					scanf("%d",&count3);
					for(int i=0;i<count3;i++)
					{
						printf("Enter the %dth element: ",(i+1));
						scanf("%d",&item);
						push(item);
					}
					break;

			case 2: printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					push(item);
					break;

			case 3: pop();
					break;

			case 4: destroy();
					break;

			case 5: display();
					break;

			case 6: countnodes();
					break;

			case 7: printf("Enter the element to be searched\n");
					 scanf("%d",&item);
					 search(item);
					 break;

			case 8: exit(1);

			default: printf("Wrong choice\n");


		}
	}
}
