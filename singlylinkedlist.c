//Singly linked list implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct st{
	int info;
	struct st *next;
}node;
node *start=NULL;
void insertatbeg(int item)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;
	}
	else
	{
		ptr->next=start;
		start=ptr;
	}
}
void insertatend(int item)
{
	node *loc=start;
	node *ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;
	}
	else
	{
		while(loc->next!=NULL)
		{
			loc=loc->next;
		}

		loc->next=ptr;
		ptr->next=NULL;
	}
}
void display()
{
	if(start==NULL)
		printf("List is empty\n");
	else
	{
		node *loc=start;
		printf("List: ");
		while(loc!=NULL)
		{
			printf("%d ",loc->info);
			loc=loc->next;
		}
	}
}
node* position(int item) /*Determines the pointer where the item is found. Used in insert 
after and deleteafter functions*/
{
	node *loc=start;
	while(loc!=NULL)
	{
		if(loc->info==item)
			return loc;
		loc=loc->next;
	}
}
void insertafter(int after,int item)
{
	node *loc=position(after);
	if(loc==NULL)
		printf("Not found");
	else
	{
		node *ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(loc->next==NULL)
		{
			loc->next=ptr;
			ptr->next=NULL;
		}
		else
		{
			ptr->next=loc->next;
			loc->next=ptr;
		}
	}
}
void deletefrombeg()
{
	if(start==NULL)
		printf("List is empty\n");
	else
	{
		node *loc=start;
		start=loc->next;
		free(loc);
	}
	
}
void deletefromend()
{
	if(start==NULL)
		printf("List is empty\n");
	else
	{
		node *loc=start;
		node *prev;
		while(loc->next!=NULL)
		{   
			prev=loc;
			loc=loc->next;
		}
		prev->next=NULL;
		free(loc);
	}
}
void deleteafter(int after)
{
	node *loc=position(after);
	if(loc==NULL || loc->next==NULL)
		printf("Not found");
	else if((loc->next)->next==NULL)
	{
		node *ptr=loc->next;
		loc->next=NULL;
		free(ptr);
	}
	else
	{
		node *ptr=loc->next;
		loc->next=ptr->next;
		free(ptr);
	}
}
void countnodes() //Counts the no of nodes present in the list
{
	node *loc=start;
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
	node *loc=start;
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
		printf("\n1.Create the list\n");
		printf("2.Insert at beginning\n");
		printf("3.Insert at end\n");
		printf("4.Insert after a given element\n");
		printf("5.Delete from beginning\n");
		printf("6.Delete from end\n");
		printf("7.Delete after a given element\n");
		printf("8.Display\n");
		printf("9.Count the no of nodes\n");
		printf("10.Search any node\n");
		printf("11.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no of nodes\n");
					scanf("%d",&count3);
					for(int i=0;i<count3;i++)
					{
						printf("Enter the %dth element: ",(i+1));
						scanf("%d",&item);
						insertatend(item);
					}
					break;

			case 2: printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					insertatbeg(item);
					break;

			case 3: printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					insertatend(item);
					break;

			case 4: printf("Enter element after which you want to insert\n");
					scanf("%d",&after);
					printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					insertafter(after,item);
					break;

			case 5: deletefrombeg();
					break;

			case 6: deletefromend();
					break;

			case 7: printf("Enter element after which you want to delete\n");
					scanf("%d",&after);
					deleteafter(after);
					break;

			case 8: display();
					break;

			case 9: countnodes();
					break;

			case 10: printf("Enter the element to be searched\n");
					 scanf("%d",&item);
					 search(item);
					 break;

			case 11: exit(1);

			default: printf("Wrong choice\n");


		}
	}
}
