#include<stdio.h>
void quicksort(int A[50],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j)
      {
         while(A[i]<=A[pivot] && i<last)
            i++;
         while(A[j]>A[pivot])
            j--;
         if(i<j)
         {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
         }
      }

      temp=A[pivot];
      A[pivot]=A[j];
      A[j]=temp;
      quicksort(A,first,j-1);
      quicksort(A,j+1,last);

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
   quicksort(A,0,n-1);
   printf("\nThe sorted array is:  \n");
   display(A,n);
}