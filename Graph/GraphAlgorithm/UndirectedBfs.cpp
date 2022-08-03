#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int s, int d)
{
    v[s].push_back(d);
    v[d].push_back(s);
}
void printGraph(vector<int>adj[], int V)
{
    for(int i=1; i<V; i++)
    {
        cout<<"Vertex of "<<i<<" is: ";
        for(auto x: adj[i])
        {
            cout<<x<<"->";
        }
        cout<<endl;
    }
}
int main()
{
    int V=11;
  vector<int>v[V];
  addedge(v,1,2);
  addedge(v,2,4);
  addedge(v,3,5);
  addedge(v,5,6);
  addedge(v,6,7);
  addedge(v,7,8);
  addedge(v,8,9);
  addedge(v,8,11);
  addedge(v,10,5);
  addedge(v,10,9);
  printGraph(v,V);
}