#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    char ch;
    node* lchild;
    node* rchild;
};
node* newnode(char c)
{
node* root=new node();
root->ch=c;
root->lchild=NULL;
root->rchild=NULL;
return root;
}
node* bst(char post[], char in[], int istart, int iend)
{
  
   if(istart>iend)
   {
       return NULL;
   }
   static int p=iend;
     node* root=newnode(post[p]);
     p-=1;
    if(istart==iend)
    return root;
    int i;
    for(i=istart; i<=iend; i++)
    {
        if(in[i]==root->ch)
        break;
    }
    root->rchild=bst(post,in,i+1,iend);
    root->lchild=bst(post,in,istart,i-1);
    return root;
}
void inorder(node* root)
{
  if(root!=NULL)
  {
      inorder(root->lchild);
      cout<<root->ch<<' ';
      inorder(root->rchild);
  }
}
int main()
{
  char in[]={'H','D','P','L','A','Z','C','E'};
  char post[]={'H','P','L','D','E','C','Z','A'};
  int n=sizeof(in)/sizeof(in[0]);
  node* root=bst(post,in,0,n-1);
  inorder(root);
}