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
node* bst(char pre[], char in[], int istart, int iend)
{
    static int preindex=0;
   if(istart>iend)
   {
       return NULL;
   }
     node* root=newnode(pre[preindex++]);
     if(istart==iend)
     {
         return root;
     }
     int i;
     for(i=istart; i<=iend; i++)
     {
          if(root->ch==in[i])
          {
              break;
          }
     }
     root->lchild=bst(pre,in,istart,i-1);
     root->rchild=bst(pre,in,i+1,iend);
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
  char pre[]={'A','D','H','L','P','Z','C','E'};
  int n=sizeof(in)/sizeof(in[0]);
  node* root=bst(pre,in,0,n-1);
  inorder(root);
}