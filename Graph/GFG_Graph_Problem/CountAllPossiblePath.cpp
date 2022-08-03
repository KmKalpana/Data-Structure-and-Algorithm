//Count all possible path between 2 vertices.
//Run on GDB.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(int u, int v, vector<int>adj[])
{
            adj[u].push_back(v);
}
void helper(vector<int>adj[],int src, int dst, int &count, vector<int>&vis,vector<vector<int>>&res,vector<int>v)
{
      vis[src]=1;
   if(src==dst)
   {
       count++;
   }
   else
   {
      for(auto it: adj[src])
      {
          if(!vis[it])
          {
             // cout<<it<<" ";
              helper(adj,it,dst,count,vis,res,v);
          }
      }
   }
      vis[src]=0;
}
int main()
{
     int n=5;
     vector<int>adj[8];
     addedge(1,2,adj);
     addedge(2,5,adj);
     addedge(1,5,adj);
     addedge(1,3,adj);
     addedge(3,5,adj);
     addedge(4,3,adj);
     addedge(2,4,adj);
          int src=1, dst=5;
      int count=0;
      vector<int>vis(n,0);
      vector<vector<int>> res;
      vector<int>v;
      helper(adj,src, dst,count,vis,res,v);
      cout<<count<<endl;
      /*for(int i=0; i<res.size(); i++)
      {
          for(int j=0; j<res[i].size(); j++)
          {
           cout<<res[i][j]<<" ";
          }
          cout<<endl;
      }*/

}
/*
Time Complexity: O(N!). 
If the graph is complete then there can be around N! recursive calls, so the time Complexity is O(N!)
Space Complexity: O(1). 
Since no extra space is required.
*/