//Modified Bubble sort
#include<stdio.h>
void bubblesort(int A[50],int n)
{
	int temp,flag;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<(n-i-1);j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
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
	bubblesort(A,n);
	printf("\nThe sorted array is:  \n");
	display(A,n);
}
	
