#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int max=arr[0];
    for(int i=1; i<n; i++)
    {
        if(max<arr[i])
        {
       max=arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int n)
{
    int output[n+1];
    int max=getMax(arr,n);
    int count[max+1];
    for(int i=0; i<=max; i++)
    {
        count[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }
    for(int i=1; i<=max; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i<n; i++)
    {
        arr[i]=output[i];
    }

}
int main()
{
    int arr[]={1,5,2,3,2,5,6,9,8};
    int n=8;
    countingSort(arr,8);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}