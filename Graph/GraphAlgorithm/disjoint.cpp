//Disjoint set Union.
#include <iostream>
#include <vector>
using namespace std;
#define N 5
int parent[N];
int size[N];

int find(int v){
    if(v==parent[v])
    return v;
    return find(parent[v]);

}
bool Union(int a, int b)
{
 a= find(a);
 b=find(b); 
 if(a!=b) 
 return false;
   parent[b]=a;
}
int main()
{
   

}
