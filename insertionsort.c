//Insertion sort
#include<stdio.h>
void insertionsort(int A[50],int n)
{
	int key,flag=0,j;
	for(int i=1;i<n;i++)
	{
		key=A[i];
		for(j=(i-1);j>=0;j--)
		{
			if(A[j]>key)
			{
				A[j+1]=A[j];
				flag=1;
			}
			else break;
		}
		if(flag)
			A[j+1]=key;
	}
}
void display(int A[50],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
void main()
{
	int A[50],n;
	printf("Enter the no of elements you want to enter\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Original array:   \n");
	display(A,n);
	insertionsort(A,n);
	printf("\nThe sorted array is:  \n");
	display(A,n);
}
	
