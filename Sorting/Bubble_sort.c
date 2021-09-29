
#include <Stdio.h>
#include <stdlib.h>
//Sorting
int bubblesort(int a[], int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
  int a[]={13,20,32,62,68,52,38,46};
  int n= sizeof(a)/sizeof(a[0]);
  bubblesort(a,n);
  printf("Sorting array is : \n");
  for(int i=0; i<n; i++)
  {
      printf("%d ",a[i]);
  }
  }
