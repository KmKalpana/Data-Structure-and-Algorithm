#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(int u, int v, int wt, vector<pair<int,int>>adj[])
{
         adj[u].push_back({v,wt});
}
void findTopoSort(int src, vector<int>&vis,stack<int>&st, vector<pair<int,int>>adj[])
{
        vis[src]=1;
        for(auto it: adj[src])
        {
            if(!vis[it.first])
            {
                findTopoSort(it.first,vis,st,adj);
            }
        }
        st.push(src);
}
void LongestPath(int src, int n, vector<pair<int,int>>adj[])
{
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            findTopoSort(i,vis,st,adj);
        }
    }
    vector<int>dist(n,INT_MIN);
    dist[src]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MIN)
        {
            for(auto it: adj[node])
            {
                     if(dist[node]+it.second>dist[it.first])
                     {
                         dist[it.first]=dist[node]+it.second;
                     }
            }
        }
    }
     for(int i=0; i<n; i++)
        {
            cout<<dist[i]<<" ";
        }
}
int main()
{
    int n=6;
 vector<pair<int,int>> adj[6];
     addedge(0,1,2,adj);
     addedge(0,4,1,adj);
     addedge(1,2,3,adj);
     addedge(4,2,2,adj);
     addedge(2,3,6,adj);
     addedge(4,5,4,adj);
     addedge(5,3,1,adj);
    LongestPath(0,n,adj);
}