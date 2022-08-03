#include <stdlib.h>
#include <iostream>
using namespace std;
struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode bst;
bst* newnode(int data)
{
    bst* root;
    root= new bst();
    root->data=data;
    root->left=NULL;
    root->right=NULL;
}
bst* insert(bst* root, int data)
{
   if(root==NULL)
   {
       return  newnode(data);
   }
   if(data<root->data)
   {
       root->left=insert(root->left,data);
   }
   else if(data>root->data)
   {
       root->right=insert(root->right,data);
   }
   return root;
}
bst* findmin(bst* right)
{
    bst* current=right;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
bst* deletenode(bst* root, int key)
{
  if(root==NULL)
  {
      return root;
  }
  else if(key<root->data)
  {
    root->left =deletenode(root->left,key);
  }
  else if(key>root->data)
  {
      root->right =deletenode(root->right,key);
  }
  else
  {  
      //Case 1: No child
      if(root->left==NULL && root->right==NULL)
      {
          delete(root);
          root=NULL;
          //return root;
      }
      //Case 2: One child
      else if(root->left==NULL)
      {
          bst* temp=root;
          root=root->right;
          delete(temp);
          //return root;
      }
      else if(root->right==NULL)
      {
          bst* temp=root;
          root=root->left;
          delete(temp);
        //  return root;
      }
      //Case 3: Two Child
      else
      {
          bst* temp= findmin(root->right);
          root->data=temp->data;
          root->right=deletenode(root->right,temp->data);
         // return root;
      }
}
return root;
}
void inorder(bst* root)
{
if(root!=NULL)
{
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
}
int main()
{
   bst *root=NULL;
    // int arr[]={50,30,20,40,70,60,80};
     int arr[]={5,3,6,2,4,7};
     int n=sizeof(arr)/sizeof(arr[0]);
    for (int key=0; key<n; key++) 
    {
        root = insert(root, arr[key]);
    }
    deletenode(root,5);
    inorder(root);
}
// g++ -std=c++11 delete.cpp
/*for (int key: arr) 
    {
        root = insert(root, key);
 }
 */