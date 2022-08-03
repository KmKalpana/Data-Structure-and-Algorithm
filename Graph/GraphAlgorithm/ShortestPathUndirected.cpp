#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
void printgraph(vector<int>adj[], int V)
{
    for(int v=0; v<V; v++)
    {
       cout<<"Vertex of "<<v<<" is : " ;
       for(auto x : adj[v])
       {
           cout<<x<<"->";
       }       
       cout<<endl;
    }
}
void ShortestPathUndirected(vector<int>adj[], int N, int src)
{
  int Dist[N];
  for(int i=1; i<=N; i++)
  {
      Dist[i]=INT_MAX;
  }
  queue<int>q;
  q.push(src);
  Dist[src]=0;
  while(!q.empty())
  {
      int node=q.front();
      q.pop();
      for(auto i: adj[node])
      {
          if(Dist[i]>Dist[node]+1)
          {
              Dist[i]=Dist[node]+1;
              q.push(i);
          }
      }
  }
  for(int i=0; i<N; i++)
  {
      cout<<Dist[i]<<" ";
  }
}
int main()
{
     int V=5;
    vector<int>adj[V];
    addedge(adj,0,1);
    addedge(adj,0,4);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,2,3);
    addedge(adj,3,4);
  ShortestPathUndirected(adj,V,0);
}
/*addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,1,5);
    addedge(adj,3,4);
    addedge(adj,4,6);
    addedge(adj,5,6);
*/