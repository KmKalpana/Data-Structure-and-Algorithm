#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 5
int parent[N], Rank[N];
void make(int v)
{
 parent[v]=v;
 Rank[v]=0;
}
int find(int a)
{
    if(a==parent[a])
    {
        return a;
    }
    return find(parent[a]);
}
void Union(int a, int b)
{
  a=find(a);
  b=find(b); 
  if(a!=b)
  { 
      if(Rank[a]<Rank[b])
      {
          swap(a,b);
          parent[b]=a;
      }
      if(Rank[a]==Rank[b])
      {
          Rank[a]++;
      }
  }
}
int main()
{
    int n, m;
    cin>>n>>m;             //n=number of nodes and m=number of edges.
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1; i<=n; i++) 
    {
        make(i);
    }
    int total_cost=0;
    for(auto &edge: edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v))
        continue;
        Union(u,v);
        total_cost+=wt;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<parent[i]<<" ";
    }

    cout<<"Total cost is : "<<total_cost<<endl;
}