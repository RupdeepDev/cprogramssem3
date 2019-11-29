//Polynomial addition
#include<stdio.h>
struct st
{
	int coeff;
	int exp;
}p1[10],p2[10],p3[10];

void main()
{
	int n1,n2,n3,i,j,k;
	printf("Enter the no of terms for polynomial 1 and 2\n");
	scanf("%d%d",&n1,&n2);
	printf("Enter the first polynomial\n");
	for(i=0;i<n1;i++)
	{
		printf("Enter the coefficient and exponent for %dth term",(i+1));
		scanf("%d%d",&p1[i].coeff,&p1[i].exp);
	}
	printf("Enter the second polynomial\n");
	for(i=0;i<n2;i++)
	{
		printf("Enter the coefficient and exponent for %dth term",(i+1));
		scanf("%d%d",&p2[i].coeff,&p2[i].exp);
	}
	i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(p1[i].exp==p2[j].exp)
		{
			p3[k].coeff=p1[i].coeff+p2[j].coeff;
			p3[k].exp=p1[i].exp;
			i++,j++,k++;
		}
		else if(p1[i].exp>p2[j].exp)
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].exp=p1[i].exp;
			i++,k++;
		}
		else
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].exp=p2[j].exp;
			k++,j++;
		}
	}
	while(i<n1)
	{
		p3[k].coeff=p1[i].coeff;
		p3[k].exp=p1[i].exp;
		i++,k++;
	}
	while(j<n2)
	{
		p3[k].coeff=p2[j].coeff;
		p3[k].exp=p2[j].exp;
		j++,k++;
	}
	n3=k;
	printf("Displaying resultant polynomial\n");
	for(k=0;k<n3;k++)
	{
		if(k==0)
		printf("%dx^%d",p3[k].coeff,p3[k].exp);
		else if(p3[k].coeff>0)
		printf("+%dx^%d",p3[k].coeff,p3[k].exp);
		else printf("%dx^%d",p3[k].coeff,p3[k].exp);
	}
}
	
