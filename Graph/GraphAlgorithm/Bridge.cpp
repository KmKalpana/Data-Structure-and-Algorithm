#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
void dfs(int node, int parent, vector<int>&vis, vector<int>&tin,vector<int>&low,int &timer,vector<int>adj[])
{
    vis[node]=1;
    tin[node]=low[node]= ++timer;
    for(auto it: adj[node])
    {
        if(it==parent)
            continue;
        if(!vis[it])
        {
            dfs(it,node,vis,tin,low,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node])
            {
                cout<<node<<" "<<it<<endl;
            }
        }
        else{
            low[node]=min(low[node],tin[it]);
        }
    }
}
int main()
{
     int V=5;
    vector<int>adj[V];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,0,3);
    addedge(adj,3,4);
    vector<int>low(V,-1);
    vector<int>tin(V,-1);
    vector<int>vis(V,0);
    int timer=0;
  for(int i=0; i<V; i++)
  {
      if(!vis[i])
      {
          dfs(i,-1,vis,tin,low,timer,adj);
      }
  }
  return 0;
}