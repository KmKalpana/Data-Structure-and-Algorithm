#include <bits/stdc++.h>
using namespace std;
struct treenode
{
    int data;
    struct treenode* left;
    struct treenode* right;
};
typedef struct treenode pre;
pre* newnode(int data)
{
pre* root=new pre();
root->data=data;
root->left=NULL;
root->right=NULL;
return root;
}
pre* createlist(int arr[], int strt, int end)
{
  if(strt>end)
  {
      return NULL;
  }
  pre* root=newnode(arr[strt]);
  int i;
  for(i=strt+1; i<=end; i++)
  {
      if(arr[i]>root->data)
      {
          break;
      }
  }
  root->left=createlist(arr,strt+1,i-1);
  root->right=createlist(arr,i,end);
  return root;
}
void inorder(pre* root)
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
    int arr[]={10,4,2,8,5,9,15,12,20};
    pre* root=createlist(arr,0,8);
    inorder(root);
}