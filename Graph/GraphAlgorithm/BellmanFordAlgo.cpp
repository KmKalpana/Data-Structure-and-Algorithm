#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int s, int d, int weight)
    {
        u=s;
        v=d;
        wt=weight;
    }
};
int main()
{
  int V=6;
  vector<node>adj;
  adj.push_back(node(0,1,5));
  adj.push_back(node(1,2,-2));
  adj.push_back(node(1,5,-3));
  adj.push_back(node(2,4,3));
  adj.push_back(node(3,2,6));
  adj.push_back(node(3,4,-2));
  adj.push_back(node(5,3,1));
  int inf=10000000;
  vector<int>dist(V,inf);
  int src=0;
  dist[src]=0;
  for(int i=1; i<=V-1; i++)
  {
      for(auto it : adj)
      {
          if(dist[it.u]+it.wt<dist[it.v])
          {
              dist[it.v]=dist[it.u]+it.wt;
          }
      }
  }
       int fl = 0; 
    for(auto it: adj) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
 if(!fl)
 {
  for(int i=0; i<V; i++)
  {
      cout<<dist[i]<<" ";
  }
  }
}