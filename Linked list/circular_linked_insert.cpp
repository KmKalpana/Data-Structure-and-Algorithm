//Circular singly linked list.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head;
class circular_list
{
public:
 void create_list(int n);
 void insert_beg();
 void insert_mid();
 void insert_last();
 void display();
};
void circular_list:: create_list(int n)
{
    int data;
struct node *newnode, *temp;
head=new(struct node);
cout<<"Enter the value at the node 1: ";
cin>>data;
head->data=data;
head->next=NULL;
temp=head;
for(int i=2; i<=n; i++)
{
    newnode=new(struct node);
    cout<<"Enter the value at the node "<<i<<": ";
    cin>>data;
    newnode->data=data;
    newnode->next=NULL;
    temp->next=newnode;
    temp=newnode;
}
newnode->next=head;
}

void circular_list:: display()
{
struct node *temp;
temp=head;
int i=1;
do
{
cout<<"Data at node "<<i<<" is :"<<temp->data<<endl;
temp=temp->next;
i++;
} while (temp!=head);
}
void circular_list:: insert_beg()
{
    struct node *temp, *begin;
int data;
begin=new(struct node);
 cout<<"Enter the data Which number do you want to insert at the begining: ";
 cin>>data;
 begin->data=data;
 begin->next=head;
 temp=head;
 while(temp->next!=head)
 {
     temp=temp->next;
 }
 temp->next=begin;
 head=begin;
}
void circular_list::insert_mid()
{
int pos,data;
struct node *newnode,*temp;
newnode=new(struct node);
cout<<"Enter the position for insert the new data: ";
cin>>pos;
cout<<"Enter the data : ";
cin>>data;
temp=head;
int i=1;
while(i!=pos-1)
{
    temp=temp->next;
    i++;
}
newnode->data=data;
newnode->next=temp->next;
temp->next=newnode;
}
void circular_list::insert_last()
{
  struct node *temp,*last;
  int data;
  last=new(struct node);
  cout<<"Enter the data Which number do you want to insert at the end: ";
  cin>>data;
  last->data=data;
  last->next=head;
   temp=head;
   while(temp->next!=head)
   {
       temp=temp->next;
   }
   temp->next=last;
}
int main()
{
    circular_list c;
    int n;
    cout<<"Enter the number of node in circular linked list : ";
    cin>>n;
    c.create_list(n);
    c.display();
    c.insert_beg();
    c.display();
    c.insert_mid();
    c.display();
    c.insert_last();
    c.display();
}
