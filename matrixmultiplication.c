//Matrix multiplication
#include<stdio.h>
void display(int A[10][10],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}
void multiply(int A[10][10],int B[10][10],int r1,int c1,int r2,int c2)
{
	int C[10][10];
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			C[i][j]=0;
			for(int k=0;k<c1;k++)
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
		}
	}
	printf("Resultant array:-\n");
	display(C,r1,c2);
}

void main()
{
	int A[10][10],B[10][10];
	int r1,c1,r2,c2;
	printf("Enter sizes for the arrays\n");
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	if(c1==r2)
	{
		printf("Enter first 2D array\n");
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
				scanf("%d",&A[i][j]);
		}
		printf("Enter second 2D array\n");
		for(int i=0;i<r2;i++)
		{
			for(int j=0;j<c2;j++)
				scanf("%d",&B[i][j]);
		}
		printf("First array:-\n");
		display(A,r1,c1);
		printf("Second array:-\n");
		display(B,r2,c2);
		multiply(A,B,r1,c1,r2,c2);
	}
	else printf("Multiplication not possible\n");
}
