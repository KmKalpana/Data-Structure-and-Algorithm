#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int s, int d)
{
  adj[s].push_back(d);
  adj[d].push_back(s); 
}
bool checkforcycle(int s, int V, vector<int>adj[],vector<bool>&visited)
{
queue<pair<int,int>>q;
visited[s]=true;
q.push({s,-1});
while(!q.empty())
{
    int node=q.front().first;
    int prev=q.front().second;
    q.pop();
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            visited[it]=true;
            q.push({it,node});
        }
        else if(prev!=it) 
  {
        return true;  
 }
    }
}
return false;
}
bool iscycle(int V, vector<int>adj[]) 
{
  vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
 {
        if (!visited[i] && checkforcycle(i, V, adj, visited))
        {
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