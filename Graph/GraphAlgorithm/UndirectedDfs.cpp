#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int s, int d)
{
    v[s].push_back(d);
    v[d].push_back(s);
}
bool dfs(int start,int parent, vector<bool>&vis, vector<int>adj[], int V)
{
     vis[start]=true;
     for(auto i: adj[start])
     {
         if(vis[i]!=true)
         {
             if(dfs(i,start,vis,adj,V))
             {
                return true;
             }
             else if(parent!=i)
             {
                 return true;
             }
         }
     } 
     return false;  
}
int main()
{
    int V=6;
  vector<int>v[V];
  vector<bool>vis(V+1,false);
  addedge(v,0,4);
  addedge(v,1,2);
  addedge(v,1,4);
  addedge(v,2,3);
  addedge(v,3,4);
  int count=0;
  for(int i=0; i<V; i++)
      {
               if(!vis[i])
               {
                   if(dfs(i,-1,vis,v,V))
                   {
                       cout<<"true"<<endl;
                       count=1;
                       break;
                   }
               }
      }
      if(count==0)
      {
      cout<<"false"<<endl;
      }
}