#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int s, int d)
{
    adj[s].push_back(d);
}
void dfs(vector<int>adj[], int v,stack<int>& Stack,vector<bool>&visited)
{
    visited[v] = true;
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
     {
            if (!visited[*i])
            dfs(adj, *i,Stack,visited);
     }
    Stack.push(v);
}
void topological(vector<int>adj[],int V)
{
    stack<int>st;
    vector<bool>visited(V,false);
  for(int i=0; i<V; i++)
  {
        if(visited[i]==false)
        dfs(adj,i,st,visited);
  }
  while(st.empty()==false)
{
    cout<<st.top()<<" ";
    st.pop();
}
}
int main()
{
    

}