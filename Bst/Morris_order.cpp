#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* newnode(int key)
{
    TreeNode* node=new TreeNode();
     node->val=key;
     node->left=NULL;
     node->right=NULL;
     return node;
}
TreeNode* insert(TreeNode* root, int val)
{
    if(root==NULL)
    {
        return newnode(val);
    }
    if(val<root->val)
    {
        root->left=insert(root->left,val);
    }
    else if(val>root->val)
    {
        root->right=insert(root->right,val);
    }
    return root;
}
TreeNode* predecessor(TreeNode* root)
{
    TreeNode* node=root->left;
    while(node->right && node->right!=root)
    {
        node=node->right;
    }
    return node;
}
void morris(TreeNode* root)
{
    TreeNode* current=root;
    TreeNode* pre;
    while(current!=NULL)
    {
      if(current->left==NULL)
      {
          cout<<current->val<<" ";
          current=current->right;
      }
      else{
           pre=predecessor(current);
          if(pre->right==NULL)
          {
            pre->right=current;
            current=current->left;
          }
          else{
              pre->right=NULL;
               cout<<current->val<<" ";
              current=current->right;
          }
      }
    }
}
int main()
{
    TreeNode* root=NULL;
    root=insert(root,6);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,8);
    root=insert(root,10);
    root=insert(root,9);
    root=insert(root,12);
   morris(root);
}