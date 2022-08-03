#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int>>adj[], int s, int d, int wt)
{
    adj[s].push_back({d,wt});
    adj[d].push_back({s,wt});
}
void dijkstraUndirected(vector<pair<int,int>>adj[], int src, int V)
{
 priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> >pq;  //MinHeap.
  vector<int>dist(V+1,INT_MAX);
   dist[src]=0;
   pq.push({0,src});
   while(!pq.empty())
   {
       int distance=pq.top().first;
       int node=pq.top().second;
       pq.pop();
       vector<pair<int,int>>::iterator it;
       for(auto it: adj[node])
       {
           int next=it.first;
           int nextdist=it.second;
          if(dist[next] > distance+nextdist)
          {
              dist[next]=dist[node]+nextdist;
              pq.push({dist[next],next});
          }
       }
   }
   for(int i=0; i<V; i++)
   {
   cout<<dist[i]<<" ";
   }
}
int main()
{
     int V=5;
    vector<pair<int,int>>adj[V];
    addedge(adj,0,1,2);
    addedge(adj,0,4,5);
    addedge(adj,1,2,3);
    addedge(adj,1,3,4);
    addedge(adj,1,4,7);
    addedge(adj,2,3,4);
    addedge(adj,4,3,2);
    dijkstraUndirected(adj,0,V);
}