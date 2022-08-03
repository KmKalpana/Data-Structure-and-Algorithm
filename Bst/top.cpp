#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct topview
{
    int data;
    struct topview* lchild;
    struct topview* rchild;
};
typedef struct topview top;
void topviews(top* root,map<int,pair<int,int> >&m,int dist, int level)
{
  if(root==NULL)
  return ;
  if(m.count(dist)==0)
  {
      m[dist]=make_pair(root->data,level);
  }
  else if(m[dist].second>level)
  {
      m[dist]=make_pair(root->data,level);
  }
    topviews(root->lchild,m,dist-1,level+1);
    topviews(root->rchild,m,dist+1,level+1);
}
void create(top* root)
{
    map<int,pair<int,int> >m;
     topviews(root,m,0,0);
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->second.first<<" ";
    }
}
top* newnode(int data)
{
    top* root;
    root= new top();
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}
top* insert(top* root, int data)
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
   top* root;
   root=NULL;
     int arr[]={50,30,20,40,70,60,80};
     int n=sizeof(arr)/sizeof(arr[0]);
    for (int key=0; key<n; key++) 
    {
        root = insert(root, arr[key]);
    }
     create(root);
    
}