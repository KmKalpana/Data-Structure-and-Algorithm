#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;
class Graph
{
public:
  int v,s,d;
   bool *visited;
  void addedge(vector<int>adj[],int s, int d);
  void DFS(vector<int>adj[],int v);
  void printgraph(vector<int>adj[],int v);
};
void Graph :: addedge(vector<int>adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
void Graph::DFS(vector<int>adj[],int s)
{
  visited[s]=true;
   cout<<s<<" ";
   vector<int>::iterator i;
  for( i=adj[s].begin(); i!=adj[s].end(); ++i)
   {
     if(!visited[*i])
     {
         DFS(adj,*i);
     }   
   }
}
void Graph::printgraph(vector<int>adj[],int v)
{
  for(int i=0; i<v; i++)
  {
      cout<<"Vertex of "<< i  <<" is : ";
      for(auto u: adj[i])
      {
       cout<<u<<"-> ";
      }
      cout<<endl;
  }
}
int main()
{
    int v=5;
    Graph g;
    vector<int>adj[v];
    g.addedge(adj,0,1);
    g.addedge(adj,0,4);
    g.addedge(adj,1,2);
    g.addedge(adj,1,3);
    g.addedge(adj,1,4);
    g.addedge(adj,2,3);
    g.addedge(adj,3,4);
    cout<<"DFS is : ";
    g.DFS(adj,0);
    cout<<endl;
    g.printgraph(adj, v);
}