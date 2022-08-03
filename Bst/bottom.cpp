#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct bottomview
{
    int data;
    struct bottomview* lchild;
    struct bottomview* rchild;
};
typedef struct bottomview bottom;
void bottomviews(bottom* root,map<int,pair<int,int>>&m,int dist, int level)
{
  if(root==NULL)
  return ;
  if(m.count(dist)==0)
  {
      m[dist]=make_pair(root->data,level);
  }
  else if(m[dist].second<level)
  {
      m[dist]=make_pair(root->data,level);
  }
    bottomviews(root->lchild,m,dist-1,level+1);
    bottomviews(root->rchild,m,dist+1,level+1);
}
void create(bottom* root)
{
    map<int,pair<int,int> >m;
     bottomviews(root,m,0,0);
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->second.first<<" ";
    }
}
bottom* newnode(int data)
{
    bottom* root;
    root= new bottom();
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}
bottom* insert(bottom* root, int data)
{
   if(root==NULL)
   {
       return  newnode(data);
   }
   if(data<root->data)
   {
       root->lchild=insert(root->lchild,data);
   }
   else if(data>root->data)
   {
       root->rchild=insert(root->rchild,data);
   }
   return root;
}

int main()
{
   bottom* root;
   root=NULL;
     int arr[]={50,30,20,40,70,60,80};
     int n=sizeof(arr)/sizeof(arr[0]);
    for (int key=0; key<n; key++) 
    {
        root = insert(root, arr[key]);
    }
     create(root);
    
}