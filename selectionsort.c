//Selection sort
#include<stdio.h>
void selectionsort(int A[50],int n)
{
	int temp,pos;
	for(int i=0;i<(n-1);i++)
	{
		pos=i;
		for(int j=(i+1);j<n;j++)
		{
			if(A[j]<A[pos])
				pos=j;
		}
		if(pos!=i)
		{
			temp=A[i];
			A[i]=A[pos];
			A[pos]=temp;
		}
	}
}
void display(int A[50],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	print("\n");
}
void main()
{
	int A[50],n;
	printf("Enter the no of elements you want to enter\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("Original array:   \n");
	display(A,n);
	selectionsort(A,n);
	printf("\nThe sorted array is:  \n");
	display(A,n);
}
	
