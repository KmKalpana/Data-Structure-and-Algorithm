#include <iostream>
using namespace std;
int binarySearch(int arr[], int key, int start, int end)
{
   
   int mid=(start+end)/2;
     if(arr[mid]==key)
     {
         return mid;
     }
     if(arr[start]<=key && arr[mid]>key)
     {
       return binarySearch(arr,key,start,mid-1);
     }
     else if(arr[end]>=key && arr[mid]<key)
     {
         return binarySearch(arr,key,mid+1,end);
     }

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    cout<<binarySearch(arr,5,0,7)<<endl;
}