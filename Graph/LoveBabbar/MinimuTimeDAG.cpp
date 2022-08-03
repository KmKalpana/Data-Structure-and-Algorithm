// Minimum time taken by each job to be completed given by a Directed Acyclic Graph
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10];
void addedge(int u, int v, vector<int>&indegree)
{
      adj[u].push_back(v);
      indegree[v]++;
}
void helper(vector<int>&indegree, vector<int>&ans, int n)
{
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
          if(indegree[i]==0)
          {
              q.push(i);
              ans[i]=1;
              --indegree[i];
          }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
         for(auto it: adj[node])
         {
             --indegree[it];
             ans[it]=ans[node]+1;
             if(indegree[it]==0)
             {
                 q.push(it);
             }
         }
    }
}
int main()
{
   int N=10;
    vector<int>indegree(N+1,0);
    addedge(1,4,indegree);
    addedge(1,5,indegree);
    addedge(1,3,indegree);
    addedge(2,3,indegree);
    addedge(2,8,indegree);
    addedge(2,9,indegree);
    addedge(2,6,indegree);
    addedge(4,6,indegree);
    addedge(4,8,indegree);
    addedge(5,8,indegree);
    addedge(6,7,indegree);
    addedge(7,8,indegree);
    addedge(8,10,indegree);
    vector<int>Ans(N+1,0);
    helper(indegree,Ans,N);
    for(int i=1; i<=N; i++)
    {
        cout<<Ans[i]<<" ";
    }
  //g++ -std=c++11 adj_list.cpp
}