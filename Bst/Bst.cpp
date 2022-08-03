#include <stdlib.h>
#include <iostream>
using namespace std;
class treenode
{
   // treenode* root;
public:
 int data;
 treenode* lchild;
 treenode* rchild;
 treenode()
 {
     data=0;
     lchild=0;
     rchild=0;
 }
  treenode(int key)
  {
  data=key;
  lchild=NULL;
  rchild=NULL;
 }
  treenode* insert(treenode* root, int data)
  {
   if(root==NULL)
   {
       return new treenode(data);
   }
   if(data < root->data)
   {
       root->lchild=insert(root->lchild,data);
   }
   else if(data > root->data)
   {
       root->child=insert(root->child,data);
   }
  return root;
  }
    void inorder(treenoode *root) { 
    if (root != NULL) 
    { 
      inorder(root->left); 
      cout << root->data << endl; 
      inorder(root->right); 
    } 
};
int main()
{
     treenode bst;
    treenode *root=NULL;
    root=bst.insert(root,34);
    root=bst.insert(root,14);
    root=bst.insert(root,31);
    root=bst.insert(root,30);
    root=bst.insert(root,32);
  root=bst.insert(root,12);
root=bst.insert(root,19);
bst.inorder(root);

}