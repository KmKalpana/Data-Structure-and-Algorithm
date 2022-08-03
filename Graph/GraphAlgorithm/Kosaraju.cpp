#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[], int s, int d)
{
    adj[s].push_back(d);
}
void dfs(int node, stack<int>&st, vector<int>&vis,vector<int>adj[])
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,st,vis,adj);
        }
    }
    st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int>transpose[])
{
  cout<<node<<" ";
  vis[node]=1;
  for(auto it: transpose[node])
  {
      if(!vis[it])
      {
         revDfs(it,vis,transpose);
      }
  }
}
int main()
{
int V=6;
    vector<int>adj[V+1];
    addedge(adj,1,3);
    addedge(adj,3,2);
    addedge(adj,2,1);
    addedge(adj,3,5);
    addedge(adj,5,4);
    addedge(adj,4,6);
    addedge(adj,6,5);
	
    stack<int>st;
    vector<int>vis(V+1,0);
    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
        {
            dfs(i,st,vis,adj);
        }
    }
    vector<int>transpose[V+1];
    for(int i=1; i<=V; i++)
    {
        vis[i]=0;
        for(auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            cout<<"SCC : ";
            revDfs(node,vis,transpose);
            cout<<endl;
        }
    }
}