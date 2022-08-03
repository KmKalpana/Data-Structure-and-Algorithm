#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int s, int d)
{
    adj[s].push_back(d);
}
bool checkforcycle(int node, vector<int>adj[],vector<bool>&vis,vector<bool>&dfsvis)
{
    vis[node]=true;
    dfsvis[node]=true;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(checkforcycle(it,adj,vis,dfsvis))
            return true; 
        }
        else if(dfsvis[it])
        return true; 
    }
    dfsvis[node]=0;
    return false;
}
bool iscycle(int V, vector<int>adj[])
{
     vector<bool>vis(V+1,false);
     vector<bool>dfsvis(V+1,false);
     for(int i=0; i<V; i++)
     { 
         if(!vis[i])
         {
             if(checkforcycle(i,adj,vis,dfsvis))
             return true;

         }
     }
      return false;
}
int main()
{
    int V=4;
  vector<int>adj[V];
   addedge(adj,0,1);
   addedge(adj,1,2);
    addedge(adj,0,2);
   if (iscycle(V,adj))
        cout << "Yes";
    else
        cout << "No";
}