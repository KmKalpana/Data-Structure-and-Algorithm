#include <iostream>
using namespace std;
#include <bits/stdc++.h>
struct node
{
    int val;
    struct node* next;
}*Node;
struct node* head=NULL;
void insert(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->next=head;
    head=newnode;
}
void display()
{
    
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<' ';
        ptr=ptr->next;
    }
}
int main()
{
    //struct node* ptr;
      insert(1);
      insert(2);
      insert(3);
      insert(4);
      insert(5);
      insert(6);
      display();
      return 0;
}