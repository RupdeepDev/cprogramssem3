//Binary Search
#include<stdio.h>
#include<stdlib.h> 
void main()
{
   int ch,first,last,middle,n,ele,A[100];
 
   printf("Enter number of elements\n");
   scanf("%d",&n);

   printf("Choose the sorting order:\n");
   printf("1.Ascending\n");
   printf("2.Descending\n");
   scanf("%d",&ch);

   printf("Enter sorted array: ");
   for(int i=0;i<n;i++)
      scanf("%d",&A[i]);
   
   printf("Enter element to be searched\n");
   scanf("%d",&ele);
 
   first=0;
   last=n-1;
   middle=(first+last)/2;

   switch(ch)
   {
      case 1: while(first<=last) 
              {
                  if (A[middle]<ele)
                     first = middle + 1;    
                  else if (A[middle]==ele) 
                  {
                     for(int i=middle;i<n;i++)
                     {
                        if(A[i]==ele)
                           printf("%d found at location %d\n",ele,i+1);
                        else break;
                     }
                     break;
                  }
                  else last=middle - 1;
          
                  middle = (first + last)/2;
               }
               if (first > last)
                  printf("Not found! %d isn't present in the list.\n",ele);
               break;

      case 2: while(first<=last) 
              {
                  if (A[middle]<ele)
                     last=middle-1;    
                  else if (A[middle]==ele) 
                  {
                     for(int i=middle;i<n;i++)
                     {
                        if(A[i]==ele)
                           printf("%d found at location %d\n",ele,i+1);
                        else break;
                     }
                     break;
                  }
                  else first = middle + 1;
          
                  middle = (first + last)/2;
               }
               if (first > last)
                  printf("Not found! %d isn't present in the list.\n",ele);
               break;
   }
 
}
