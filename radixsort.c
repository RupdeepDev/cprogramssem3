#include <stdio.h>
int getMax(int A[], int n)
{
  int max = A[0];
  for (int i = 1; i < n; i++)
    if (A[i] > max)
      max = A[i];
  return max;
}
void countingSort(int A[], int n, int place)
{
  int output[n + 1];
  int max = (A[0] / place) % 10;
  for (int i = 1; i < n; i++)
  {
    if (((A[i] / place) % 10) > max)
      max = A[i];
  }
  int count[max + 1];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < n; i++)
    count[(A[i] / place) % 10]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    output[count[(A[i] / place) % 10] - 1] = A[i];
    count[(A[i] / place) % 10]--;
  }
  for (int i = 0; i < n; i++)
    A[i] = output[i];
}
void radixsort(int A[], int n)
{
  int max = getMax(A, n);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(A, n, place);
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
  radixsort(A,n);
  printf("\nThe sorted array is:  \n");
  display(A,n);
}
