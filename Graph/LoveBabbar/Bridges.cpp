//Find bridges in a graph.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void addedge(int u, int v, vector<int>adj[])
{
            adj[u].push_back(v);
            adj[v].push_back(u);
}
 void dfs(int node, int parent, vector<int>&vis, vector<int>&tin, vector<int>&low, int &timer, vector<int>adj[], vector<vector<int>>&ans)
    {
       vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it: adj[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                dfs(it, node, vis, tin,low, timer, adj,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    ans.push_back({it,node});
                    cout<<it<<" "<<node<<endl;
                }
            }
            else
            {
                low[node]=min(low[node], tin[it]);
            }
        }
    }
int main()
{
       int n=4;
       vector<int>adj[n];
       vector<vector<int> >ans(3);
       addedge(0,1,adj);
       addedge(1,2,adj);
       addedge(2,0,adj);
       addedge(1,3,adj);
       vector<int>tin(n,-1);
       vector<int>low(n,-1);
       vector<int>vis(n,0);
       int timer=0;
       for(int i=0; i<n; i++)
       {
           if(!vis[i])
           {
               dfs(i,-1,vis,tin,low,timer,adj,ans);
           }
       }
       for(int i=0; i<ans.size(); i++)
       {
           cout<<ans[i][0]<<" "<<ans[i][1];
       }
}