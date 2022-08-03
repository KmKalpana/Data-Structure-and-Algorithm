#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fun(vector<int>&v)
{
    vector<int>res(v.size());
    stack<int>st;
    for(int i=v.size()-1; i>=0; i--)
    {
        int curr=v[i];
        while(!st.empty() && st.top()<=curr)
        {
            st.pop();
        }
        res[i]=st.empty()?-1:st.top();
        st.push(curr);
    }
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}
int main()
{
    //vector<int>v{2,4,1,3,1,6};
    vector<int>v{4,5,2,25};
   // vector<int>v{11,13,3,10,7,21,26};
    fun(v);
}