#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void selectionsort(int arr[], int n)
{
       int i, j, small;  
      
    for (i = 0; i < n-1; i++)
    {  
        small = i; 
          
        for (j = i+1; j < n; j++)
        {
           if (arr[j] < arr[small]) 
           { 
             small = j;  
           }
        }
        swap(arr[small],arr[i]);
    }
    
}
int main()
{
    int arr[]={3,2,52,452,32,22,12,44};
    int n=8;
    selectionsort(arr,7);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}