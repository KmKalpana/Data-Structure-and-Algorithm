#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N,m;
    cin>>N>>m;
    vector<pair<int,int> >adj[N];
    int u,v,wt;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    int parent[N],key[N];
    bool mstSet[N];
    for(int i=0; i<N; i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
        parent[i]=-1;
    }
   key[0]=0;
  parent[0]=-1;
  for(int i=0; i<N-1; i++)
  {
      int mini=INT_MAX,u;
      for(int j=0; j<N; j++)
      {
          if(mstSet[j]==false && key[j]<mini)
          {
              mini=key[j];
              u=j;
          }
          mstSet[u]=true;
          for(auto it : adj[u])
          {
              int v=it.first;
              int weight=it.second;
              if(mstSet[v]==false && weight<key[v])
              parent[v]=u;
              key[v]=weight;
          }
      }
  }
  for(int i=1; i<N; i++)
  {
      //cout<<i<<"- "<<parent[i]<<"\n";
      cout<<key[i]<<" ";
  }
}
/*
5 6
0 1 2
0 3 6
1 3 8
1 4 5
1 2 3 
2 4 7
*/