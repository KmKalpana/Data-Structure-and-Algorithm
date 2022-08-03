#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void bubblesort(int arr[], int n)
{
       for(int i=0; i<n-1; i++)
       {
           for(int j=1; j<n-i; j++)
           {
               if(arr[j-1]>arr[j])
               {
                   swap(arr[j],arr[j-1]);
               }
           }
       }
    
}
int main()
{
    int arr[]={3,2,52,452,32,22,12,44};
    int n=8;
    bubblesort(arr,8);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}