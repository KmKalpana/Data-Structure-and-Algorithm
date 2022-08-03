#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;
void addedge(vector<int>adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
void printgraph(vector<int>adj[], int V)
{
    for(int v=0; v<V; v++)
    {
       cout<<"Vertex of "<<v<<"is : " ;
       for(auto x : adj[v])
       {
           cout<<x<<"->";
       }       
       cout<<endl;
    }
}

int main()
{
    int V=5;
    vector<int>adj[V];
    addedge(adj,0,1);
    addedge(adj,0,4);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,2,3);
    addedge(adj,3,4);
    printgraph(adj, V);
}
//g++ -std=c++11 adj_list.cpp