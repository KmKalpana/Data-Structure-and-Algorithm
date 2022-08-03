#include <iostream>
using namespace std;
class TreeNode
{
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
    return root;
}
void inorder(TreeNode* root,int key)
{
    if(root)
    {
         if(key>root->val)
        {
            cout<<root->val<<endl;
            return;
        }
        inorder(root->left,key);
        inorder(root->right,key);
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
    inorder(root,25);
}