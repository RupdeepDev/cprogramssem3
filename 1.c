//Sparse matrix addition and multiplication.Multiplication not working
#include<stdio.h>
void display(int sp[10][3],int m)
{ 
	for(int i=0;i<(m+1);i++)
	{
		for(int j=0;j<3;j++)
			printf("%d ",sp[i][j]);
		printf("\n");
	}
}
void add(int sp1[10][3],int sp2[10][3],int r1,int c1)
{
	int s=1,s1=1,s2=1,x1,x2,m3=0,sp3[10][3];
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			if(sp1[s1][0]==i && sp1[s1][1]==j)
			{
				x1=sp1[s1][2];
				s1++;
			}
			else x1=0;
			if(sp2[s2][0]==i && sp2[s2][1]==j)
			{
				x2=sp2[s2][2];
				s2++;
			}
			else x2=0;
			if((x1+x2)!=0)
			{
				sp3[s][0]=i;
				sp3[s][1]=j;
				sp3[s][2]=x1+x2;
				s++;
				m3++;
			}
		}
	}
	sp3[0][0]=r1;
	sp3[0][1]=c1;
	sp3[0][2]=m3;
	printf("Displaying the resultant matrix\n");
	display(sp3,m3);
}
void multiply(int sp1[10][3],int sp2[10][3],int r1,int c1,int c2)
{
	int s=1,s1=1,s2=1,x1,x2,m3=0,sp3[10][3],sum=0;
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			sum=0;
			for(int k=0;k<c1;k++)
			{
				if(sp1[s1][0]==i && sp1[s1][1]==k)
				{
					x1=sp1[s1][2];
					s1++;
				}
				else x1=0;
				if(sp2[s2][0]==k && sp2[s2][1]==j)
				{
					x2=sp2[s2][2];
					s2++;
				}
				else x2=0;
				sum=sum+x1*x2;
			}
			if(sum!=0)
			{
				sp3[s][0]=i;
				sp3[s][1]=j;
				sp3[s][2]=sum;
				s++;
				m3++;
			}
		}
	}
	sp3[0][0]=r1;
	sp3[0][1]=c2;
	sp3[0][2]=m3;	
	printf("Displaying the resultant matrix\n");
	display(sp3,m3);
}
void main()
{
	int ch,r1,c1,r2,c2,sp1[10][3],sp2[10][3]
	,s=1,m1=0,m2=0,x,sum=0;
	printf("Enter the sizes of the first matrix");
	scanf("%d%d",&r1,&c1);
	printf("Enter the first matrix\n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			scanf("%d",&x);
			if(x!=0)
			{
				sp1[s][0]=i;
				sp1[s][1]=j;
				sp1[s][2]=x;
				s++;
				m1++;
			}
		}
	}
	sp1[0][0]=r1;
	sp1[0][1]=c1;
	sp1[0][2]=m1;
	s=1;
	printf("Enter the sizes of the second matrix");
	scanf("%d%d",&r2,&c2);
	printf("Enter the second matrix\n");
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			scanf("%d",&x);
			if(x!=0)
			{
				sp2[s][0]=i;
				sp2[s][1]=j;
				sp2[s][2]=x;
				s++;
				m2++;
			}
		}
	}
	sp2[0][0]=r2;
	sp2[0][1]=c2;
	sp2[0][2]=m2;
	printf("Enter your choice\n");
	printf("1.Addition\n");
	printf("2.Multiplication\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Displaying the first sparse matrix\n");
				display(sp1,m1);
				printf("Displaying the second sparse matrix\n");
				display(sp2,m2);
				if(r1==r2 && c1==c2)
				{
					add(sp1,sp2,r1,c1);
				}
				else printf("addition not possible");
				break;

		case 2: printf("Displaying the first sparse matrix\n");
				display(sp1,m1);
				printf("Displaying the second sparse matrix\n");
				display(sp2,m2);
				s=1;
				if(c1==r2)
				{
					multiply(sp1,sp2,r1,c1,c2);
				}
				else printf("Multiplication not possible");
				break;

		default: printf("Wrong choice");
	}
}
