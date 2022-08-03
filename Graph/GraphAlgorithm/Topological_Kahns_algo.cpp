#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int s, int d)
{
    adj[s].push_back(d);
}
void topological(vector<int>adj[],int V)
{
 vector<int>indegree(V,0);
 	for (int u = 0; u < V; u++) {
		vector<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
			indegree[*itr]++;
}

  queue<int>q;
  vector<int>top_ord;
  for(int i=0; i<V; i++)
  {
      if(indegree[i]==0)
      {
          q.push(i);
      }
  }
int count=0; 
while(!q.empty())
{
    int u=q.front();
    q.pop();
    top_ord.push_back(u);
    vector<int>::iterator itr;
    for(itr=adj[u].begin(); itr!=adj[u].end(); ++itr)
    if(--indegree[*itr]==0)
    q.push(*itr);
    count++;
}
if(count!=V)
{
    cout<<"Thera exists a cycle in the Graph\n";
    return ;
}
for(int i=0; i<top_ord.size(); ++i)
{
    cout<<top_ord[i]<<" ";
}
}
int main()
{
       int V=6;
vector<int>adj[V];
addedge(adj,5,2);
addedge(adj,5,0);
addedge(adj,4,0);
addedge(adj,4,1);
addedge(adj,2,3);
addedge(adj,3,1);
topological(adj,V);
}