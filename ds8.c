//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
typedef struct l
{
	int info;
	struct l *leftchild;
	struct l *rightchild;
}node; 
node* newnode(int x)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->info=x;
	ptr->leftchild=NULL;
	ptr->rightchild=NULL;
	return ptr;
}
node* insert(node *root,int x)
{
	if(root==NULL)
		return newnode(x);
	else if(x>root->info)
		root->rightchild=insert(root->rightchild,x);
	else root->leftchild=insert(root->leftchild,x);
	return root;
}
node* search(node *root,int x)
{
	if(root==NULL || root->info==x)
		return root;
	else if(x>root->info)
		return search(root->rightchild,x);
	else return search(root->leftchild,x);
}
node* minimum(node *root)
{
	if(root==NULL)
		return NULL;
	else if(root->leftchild!=NULL)
		return minimum(root->leftchild);
	else return root;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->leftchild);
		printf("-> %d ",root->info);
		inorder(root->rightchild);
	}
	else return;
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("-> %d ",root->info);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
	else return;
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("-> %d ",root->info);
	}
	else return;
}
void main()
{
	int ele,ch,d;
	node *root=NULL;
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("1.Insert\n");
		printf("2.Preorder\n");
		printf("3.Inorder\n");
		printf("4.Postorder\n");
		printf("5.Minimum\n");
		printf("6.Search\n");
		printf("7.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element to insert\n");
					scanf("%d",&ele);
					root=insert(root,ele);
					break;

			case 2: preorder(root);
					break;

			case 3: inorder(root);
					break;
			
			case 4: postorder(root);
					break;

			case 5: d=minimum(root)->info;
					printf("minimum is %d",d);
					break;

			case 6: printf("Enter no to be searched\n");
					scanf("%d",&ele);
					if(search(root,ele))
						printf("found\n");
					break;

			case 7: exit(1);

			default: printf("Wrong choice\n");
			
		}
	}
}