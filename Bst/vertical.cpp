#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct verticalview
{
    int data;
    struct verticalview* lchild;
    struct verticalview* rchild;
};
typedef struct verticalview top;
void topviews(top* root,multimap<int,int>&m,int dist)
{
  if(root==NULL)
  return ;
  m.insert(make_pair(root->data,dist));
  topviews(root->lchild,m,dist-1);
  topviews(root->rchild,m,dist+1);
}
void create(top* root)
{
    multimap<int,int>m;
    topviews(root,m,0);
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<' ';
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