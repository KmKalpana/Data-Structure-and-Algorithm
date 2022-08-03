#include <iostream>
using namespace std;
int count=0;
void merge(int arr[], int l, int mid, int h)
{
  int n1=mid-l+1;
  int n2=h-mid;
  int arr1[n1];
  int arr2[n2];
  for(int i=0; i<n1; i++)
  {
      arr1[i]=arr[l+i];
  }
  for(int j=0; j<n2; j++)
  {
      arr2[j]=arr[mid+1+j];
  }
  int i=0, j=0, k=l;
  int count=0;
  while(i<n1 && j<n2)
  {
      if(arr1[i]<=arr2[j])
      {
          arr[k]=arr1[i];
          k++, i++;
          count++;
      }
      else
      {
          arr[k]=arr2[j];
          k++, j++;
      }
  }
  while(i<n1)
  {
          arr[k]=arr1[i];
          k++, i++;
      
  }
  while(j<n2)
      {
          arr[k]=arr2[j];
          k++, j++;
      }
}
void mergesort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid=(h-l)/2+l;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
        
    }
}
int main()
{
    int arr[]={3,2,52,452,32,22,12,44};
    int n=8;
    mergesort(arr,0,7);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of comparasion is : "<<count<<endl;
}