#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
   TreeNode* newnode(int val)
    {
        TreeNode* node=new TreeNode();
        node->val=val;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    int height(TreeNode *root)
    {
        if(root==NULL)
        {
            return -1;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh>rh)
        return (lh+1);
        return (rh+1);
    }
    int getbalance(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1;
        }
        return height(root->left)-height(root->right);
    }
TreeNode* leftrotate(TreeNode* root)
{
   TreeNode* y=root->right;
   TreeNode* z=y->left;
   y->left=root;
   root->right=z;
   return y;
    
}
TreeNode* rightrotate(TreeNode* root)
{
    TreeNode* y=root->left;
    TreeNode* z=y->right;
    y->right=root;
    root->left=z;
    return y; 
}
TreeNode* create(TreeNode* root, int key)
{
    if(root==NULL)
    {
        return newnode(key);
    }
    if(key<root->val)
    {
        root->left=create(root->left,key);
    }
    else if(key>root->val)
    {
        root->right=create(root->right,key);
    }
    int bfact=getbalance(root);
    if(bfact==2 && key<root->left->val)
    {
        return rightrotate(root);
    }
    else if(bfact==-2 && key>root->right->val)
    {
        return leftrotate(root);
    }
    else if(bfact==2 && key>root->left->val)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    else if(bfact==-2 && key<root->right->val)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void inorder(TreeNode* root)
{
    if(root)
    {
        cout<<root->val<<" "<<height(root)<<" "<<getbalance(root)<<endl;
        inorder(root->left);
        
        inorder(root->right);
    }
}
int main()
{
   TreeNode* root=NULL;
   root=create(root,10);
   root=create(root,20);
   root=create(root,30);
   root=create(root,40);
   root=create(root,35);
   root=create(root,50);
   root=create(root,70);
    inorder(root);
}