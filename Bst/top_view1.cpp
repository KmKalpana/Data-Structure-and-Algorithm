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
void topviews(top* root,vector<int>&v)
{
  if(root==NULL)
  return ;
  map<int,int>m;
  queue<pair<top*, int> >q;
  q.push(make_pair(root,0));
  while(!q.empty())
  {
      
      auto it=q.front();
      q.pop();
      top* node=it.first;
      int line=it.second;
      if(m.find(line)==m.end())
      {
         m[line]=node->data;
      }
         if(node->lchild!=NULL)
         {
        q.push(make_pair(node->lchild,line-1));
         }
        if(node->rchild!=NULL)
        {
           q.push(make_pair(node->rchild,line+1));
        }
   
  }
      for(auto it : m)
       {
      v.push_back(it.second);
  }
  }
void create(top* root)
{
    vector<int>v;
     topviews(root,v);
     vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
    {
        cout<<(*it)<<" ";
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