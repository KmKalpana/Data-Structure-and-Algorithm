#include <stdlib.h>
#include <iostream>
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
void inorder(bst* root)
{
if(root!=NULL)
{
   
    cout<<root->data<<" ";
     inorder(root->lchild);
    inorder(root->rchild);
}
}
int  main()
{
    bst *root=NULL;
    root= insert(root,12);
    root= insert(root,11);
     root= insert(root,7);
    root= insert(root,5);
     root= insert(root,16);
    root= insert(root,2);
  
    root= insert(root,20);
    inorder(root);
}