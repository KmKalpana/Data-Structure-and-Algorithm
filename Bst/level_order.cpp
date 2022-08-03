#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
     struct node* lchild;
     struct node* rchild;
     node(int key)
     {
         this->data=key;
         this->lchild=this->rchild=NULL;
     }
};
void levelorder(node* root)
{
    if(root==NULL)
    return ;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* current=q.front();
        cout<<current->data<<' ';
        if(current->lchild!=NULL)
             q.push(current->lchild);
        if(current->rchild!=NULL)
        q.push(current->rchild);
        q.pop();
    }
}
int  main()
{
    struct node* root=new node(11);
    root->lchild=new node(5);
    root->lchild->lchild=new node(4);
    root->lchild->rchild=new node(9);
    root->lchild->rchild->lchild=new node(6);
    root->rchild= new node(12);
    root->rchild->rchild=new node (14);
    root->rchild->rchild->lchild=new node(12);
    root->rchild->rchild->lchild->rchild=new node (13);
    levelorder(root);
}