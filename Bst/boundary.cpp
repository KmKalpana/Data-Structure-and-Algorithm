#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct treenode
{
int data;
struct treenode* lchild;
struct treenode* rchild;
};
typedef struct treenode bst;

bst* newnode(int data)
{
    bst* root=new bst();
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}
bst* insert(bst* root, int data)
{
  if(root==NULL)
  {
      return newnode(data);
  }
  if(data<root->data)
  {
      root->lchild=insert(root->lchild,data);
  }
  else if(data > root->data)
  {
      root->rchild=insert(root->rchild,data);
  }
  return root;
}
/*void inorder(bst* root)
{
if(root!=NULL)
{
   
    cout<<root->data<<" ";
     inorder(root->lchild);
    inorder(root->rchild);
}
}*/
void leftbound(bst* root)
{
if(root==NULL)
{
    return;
}
if(root->lchild)
{
    cout<<root->data<<" ";
    leftbound(root->lchild);
}
else if(root->rchild)
{
    cout<<root->data<<" ";
    leftbound(root->rchild);
}
}
void rightbound(bst* root)
{
if(root==NULL)
{
    return;
}
  if(root->rchild)
  {
      cout<<root->data<<" ";
      rightbound(root->rchild);
  }
  else if(root->lchild)
  {
      cout<<root->data<<' ';
      rightbound(root->lchild);
  }
}
void printleaves(bst* root)
{
    if(root==NULL)
    {
        return ;
    }
    printleaves(root->lchild);
    if(!(root->lchild) && !(root->rchild))
    cout<<root->data<<" ";
    printleaves(root->rchild);
}
void printboundary(bst* root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    leftbound(root->lchild);
    printleaves(root->lchild);
    printleaves(root->rchild);
    rightbound(root->rchild);
}
int  main()
{
    bst *root=NULL;
     int arr[]={50,30,20,40,70,60,80};
     int n=sizeof(arr)/sizeof(arr[0]);
    for (int key=0; key<n; key++) 
    {
        root = insert(root, arr[key]);
    }
      printboundary(root);
}
