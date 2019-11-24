//Doubly linked list implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct st{
	int info;
	struct st *prev;
	struct st *next;
}node;
node *head=NULL;
node *tail=NULL;
void createlist(int item)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(tail==NULL)
	{
		ptr->prev=NULL;
		head=tail=ptr;
	}
	else
	{
		tail->next=ptr;
		ptr->prev=tail;
		tail=ptr;
	}
}
void traverseinorder()
{
	node *loc=head;
	printf("List: ");
	while(loc!=NULL)
	{
		printf("%d ",loc->info);
		loc=loc->next;
	}
}
void traverseinreverse()
{
	node *loc=tail;
	printf("List in reverse order: ");
	while(loc!=NULL)
	{
		printf("%d ",loc->info);
		loc=loc->prev;
	}
}
node* search(int item)
{
	node *loc=head;
	while(loc!=NULL)
	{
		if(loc->info==item)
			return loc;
		loc=loc->next;
	}
}
void insertafter(int after,int item)
{
	node *loc=search(after);
	if(loc==NULL)
		printf("Not found");
	else
	{
		node *ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(loc->next==NULL)
		{
			loc->next=ptr;
			ptr->prev=loc;
			ptr->next=NULL;
			tail=ptr;
		}
		else
		{
			ptr->next=loc->next;
			ptr->prev=loc;
			(loc->next)->prev=ptr;
			loc->next=ptr;
		}
	}
}
void insertbefore(int before,int item)
{
	node *loc=search(before);
	if(loc==NULL)
	printf("Not found");
	else 
	{
		node *ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(loc->prev==NULL)
		{
			loc->prev=ptr;
			ptr->next=loc;
			ptr->prev=NULL;
			head=ptr;
		}
		
		else
		{
			ptr->prev=loc->prev;
			ptr->next=loc;
			(loc->prev)->next=ptr;
			loc->prev=ptr;
		}
	}
}
void deleteafter(int after)
{
	node *loc=search(after);
	if(loc==NULL || loc->next==NULL)
		printf("Not found");
	else if((loc->next)->next==NULL)
	{
		node *ptr=loc->next;
		loc->next=NULL;
		tail=loc;
		free(ptr);
	}
	else
	{
		node *ptr=loc->next;
		loc->next=ptr->next;
		(ptr->next)->prev=loc;
		free(ptr);
	}
}
void deletebefore(int before)
{
	node *loc=search(before);
	if(loc==NULL || loc->prev==NULL)
		printf("Not found");
	else if((loc->prev)->prev==NULL)
	{
		node *ptr=loc->prev;
		loc->prev=NULL;
		head=loc;
		free(ptr);
	}
	else
	{
		node *ptr=loc->prev;
		(ptr->prev)->next=loc;
		loc->prev=ptr->prev;
		free(ptr);
	}
}
void destroy()
{
	node *loc=head;
	node *ptr;
	while(loc!=NULL)
	{
		ptr=loc;
		loc=loc->next;
		free(ptr);
	}
	head=tail=NULL;
}
void main()
{
	int ch,item,after,before,count1;
	while(1)
	{
		printf("\n1.Create the list\n");
		printf("2.Insert after a given element\n");
		printf("3.Insert before a given element\n");
		printf("4.Delete after a given element\n");
		printf("5.Delete before a given element\n");
		printf("6.Destroy everything\n");
		printf("7.Display\n");
		printf("8.Display in reverse order\n");
		printf("9.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no of nodes\n");
					scanf("%d",&count1);
					for(int i=0;i<count1;i++)
					{
						printf("Enter the %dth element: ",(i+1));
						scanf("%d",&item);
						createlist(item);
					}
					break;

			case 2: printf("Enter element after which you want to insert\n");
					scanf("%d",&after);
					printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					insertafter(after,item);
					break;

			case 3: printf("Enter element before which you want to insert\n");
					scanf("%d",&before);
					printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					insertbefore(before,item);
					break;

			case 4: printf("Enter element after which you want to delete\n");
					scanf("%d",&after);
					deleteafter(after);
					break;

			case 5: printf("Enter element before which you want to delete\n");
					scanf("%d",&before);
					deletebefore(before);
					break;

			case 6: destroy();
					break;

			case 7: traverseinorder();
					break;

			case 8: traverseinreverse();
					break;

			case 9: exit(1);

			default: printf("Wrong choice\n");


		}
	}
}