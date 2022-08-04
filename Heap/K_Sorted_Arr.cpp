/*K sorted Array.
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int arr[]={6,5,3,2,8,10,9};
  int k=3;
  int n=sizeof(arr)/sizeof(arr[0]);
  priority_queue<int, vector<int>, greater<int> > pq(arr,arr+k+1);
 int j=0;
 for(int i=k+1; i<n; i++)
 {
        arr[j++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
     
 }
 while(!pq.empty())
 {
     arr[j++]=pq.top();
     pq.pop();
 }
 for(int i=0; i<n; i++)
 {
    cout<<arr[i]<<" ";
 }
 return 0;
}