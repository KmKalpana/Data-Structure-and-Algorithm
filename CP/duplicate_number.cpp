#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int>findDuplicates(vector<int>&arr, int n)
{
    sort(arr.begin(),arr.end());
    vector<int>v;
    int i=1;
    while(i<arr.size())
    {
       if(arr[i-1]==arr[i])
       {
         v.push_back(arr[i-1]);
       }
        i++;
    }
    if(v.size()==0)
    {
        v.push_back(-1);
    }
    return v;
}
int main()
{
 vector<int>v(5);
 for(int i=0; i<5; i++){
     int x;
     cin>>x;
     v.push_back(x);
 }
vector<int>ans;
ans=findDuplicates(v,5);
for(int i=0; i<ans.size(); i++)
{
    cout<<ans[i]<<" ";
}
}