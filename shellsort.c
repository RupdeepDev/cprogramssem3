//Shell sort
#include<stdio.h>
void shellsort(int A[50],int n)
{
	int temp,j;
	for(int gap=n/2;gap>0;gap=gap/2)
	{
		for(int i=gap;i<n;i++)
		{
			temp=A[i];
			for(j=i;j>=gap && A[j-gap]>temp;j=j-gap)
			{
				A[j]=A[j-gap];
			}
			A[j]=temp;
		}
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
	shellsort(A,n);
	printf("\nThe sorted array is:  \n");
	display(A,n);
}
	
