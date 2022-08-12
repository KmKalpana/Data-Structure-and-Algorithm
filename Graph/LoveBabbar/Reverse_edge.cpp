//Minimum edges to reverse to make path from a source to a destination
#include <bits/stdc++.h>
using namespace std;
void addedge(int u, int v, vector<int>adj[])
{
    adj[u].push_back(v);
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
     
}