#include <stdio.h>
int insertion(int a[], int n)
{
    int i,j,key;
  for( i=1; i<n; i++)
  {
       key=a[i];
      for( j=i-1; j>=0 && a[j]>key; j--)
      {
          a[j+1]=a[j];
          
      }
      a[j+1]=key;
  }
}
int main()
{
    int arr[]={4,12,2,345,23,212,345,45453,34};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    printf("After sorting is :\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    }