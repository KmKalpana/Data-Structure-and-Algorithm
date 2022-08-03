#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int s, int d)
{
adj[s].push_back(d);
adj[d].push_back(s);
}
bool checkforcycle(int s, int parent, vector<int>adj[],vector<bool>&visited)
{
       visited[s] = true; 
        for(int it: adj[s]) 
        {
            if(!visited[it]) 
            {
                if(checkforcycle(it,s,adj,visited)) 
                    return true; 
            }
            else if(it!=parent) 
                return true; 
        }
        
        return false; 
    
}
bool iscycle(int V, vector<int>adj[])
{
    vector<bool>visited(V+1,false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i] && checkforcycle(i,-1,adj,visited))
        return true;
    }
    return false;
}
int main()
{
    
 int V=4;
  vector<int>adj[V];
   addedge(adj,0,1);
   addedge(adj,1,2);
    addedge(adj,0,2);
   if (iscycle(V,adj))
        cout << "Yes";
    else
        cout << "No";

}