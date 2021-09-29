#include <stdio.h>
void count_sort(int a[], int n)
{
 int max=a[0];
    for(int i=0; i<n; i++)
    {
     if(max<a[i])
     {
         max=a[i];
     }
    }
    int b[max];
for(int i=0; i<=max; i++)
{
  b[i]=0;
}    
for(int i=0; i<n; i++)
{
    b[a[i]]++;
}
int i=0, j=0;
 while(j<=max)
 {
 if(b[j]>0)
 {
 a[i++]=j;
 b[j]--;
 }
 else
 j++;
 }
}
int main()
{
    int a[]={4,34,45,453,23,45,56,23,48};
    int n=sizeof(a)/sizeof(a[0]);
    count_sort(a,n);
    printf("Count_Sorting is : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}