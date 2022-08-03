#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void insertionSort(int arr[], int n)
{
       int i, j, key;
       for(int i=1; i<n; i++)
       {
           key=arr[i];
           j=i-1;
           while(j>=0 && arr[j]>key)
           {
               arr[j+1]=arr[j];
               j--;
           }
           arr[j+1]=key;
    }
    
}
int main()
{
    int arr[]={3,2,52,452,32,22,12,44};
    int n=8;
    insertionSort(arr,7);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}