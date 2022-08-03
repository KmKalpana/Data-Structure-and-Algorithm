//Find if there is a path of more than k length from a source
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addEdge(int u, int v, int wt, vector<pair<int,int>>&adj)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
bool solve(int src, int k, vector<bool>&vis,vector<pair<int,int>>&adj)
{
 vis[src]=true;
 if(k<=0)
 return true;
 for(auto it: adj[src])
 {
         int u=it.first;
         int wt=it.second;
         if(vis[u]==true)
         continue;
         if(wt>=k)
         return true;
         if(solve(u,k-wt,vis,adj))
          return true;
 }
 vis[src]=false;
 return false;
}
int main()
{
    vector<pair<int,int>>adj;
    int k=34;
    addEdge(0, 1, 4,adj);
    addEdge(0, 7, 8,adj);
    addEdge(1, 2, 8,adj);
    addEdge(1, 7, 11,adj);
    addEdge(2, 3, 7,adj);
    addEdge(2, 8, 2,adj);
    addEdge(2, 5, 4,adj);
    addEdge(3, 4, 9,adj);
    addEdge(3, 5, 14,adj);
    addEdge(4, 5, 10,adj);
    addEdge(5, 6, 2,adj);
    addEdge(6, 7, 1,adj);
    addEdge(6, 8, 6,adj);
    addEdge(7, 8, 7,adj);
    vector<bool>vis(9,false);
    cout<<solve(0,k,vis,adj)<<endl;
}