#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
void addedge(vector<pair<int,int> >adj[],int u,int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
int selectminvertex(int dist[], bool visited[])
{
    int min=INT_MAX, index=0;
    for(int i=0; i<5; i++)
    {
        if(dist[i]<=min && visited[i]==false)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}
void dijkstra(vector<pair<int,int> >adj[],int v, int src)
{
   int dist[v];
   bool visited[v]={};
   for(int i=0; i<v; i++)
   {
       dist[i]=INT_MAX;
      
   }
    dist[src]=0;
       for(int i=0; i<v; i++)
       {
         int u=selectminvertex(dist,visited);
          visited[u]=true;
       
       vector<pair<int,int> >:: iterator it;
       for(it=adj[u].begin(); it!=adj[u].end(); it++)
       {
       if(visited[it->first]==false && dist[u]!=INT_MAX && dist[it->first]>dist[u]+it->second)
       {
           dist[it->first]=dist[u]+it->second;
       }
       }
}
for(int i=0; i<v; i++)
{
    cout<< i<<"---->"<<dist[i]<<endl;
}
}
int main()
{
    int v=5;
    vector<pair<int,int> >adj[v];
    addedge(adj,0,1,10);
    addedge(adj,0,4,20);
    addedge(adj,1,2,30);
    addedge(adj,1,3,40);
    addedge(adj,1,4,50);
    addedge(adj,2,3,60);
    addedge(adj,3,4,70);
    dijkstra(adj,v,0);
   // printgraph(adj,v);
}