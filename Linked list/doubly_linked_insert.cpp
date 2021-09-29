#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
int data;
struct node *prev;
struct node *next;
}*head, *last;
class doubly_list
{
    public:
    void create_list(int n);
    void display();
    void insert_beg();
    void insert_last();
    void insert_pos();
};
//Creating list
void doubly_list::create_list(int n)
{
  struct node* newnode;
  int data;
   head=NULL;
   last=NULL;
   head=new(struct node);
   
   if(head!=NULL)
   {
       cout<<"Enter the value in Node 1 : ";
   cin>>data;
   head->data=data;
   head->prev=NULL;
   head->next=NULL;
   last=head;
   for(int i=2; i<=n; i++)
   {
       newnode=new(struct node);
       if(newnode!=NULL);
       cout<<"Enter the value in Node "<<i<<": ";
       cin>>data;
       newnode->data=data;
       newnode->next=NULL;
       newnode->prev=last;
       last->next=newnode;
       last=newnode;
   }
   }
}
//Insert the new data at the begining.
void doubly_list::insert_beg()
{
    int data;
    struct node* temp;
    temp=NULL;
    cout<<"Enter the data which you want to insert at begining:-";
    cin>>data;
    temp=new(struct node);
    temp->data=data;
    temp->next=head;
    temp->prev=NULL;
    head=temp;

}
//Insert the new at the end.
void doubly_list:: insert_last()
{
    int data;
    struct node* temp;
    cout<<"Enter the value which you want to insert at the end : ";
    cin>>data;
    temp=NULL;
    temp=new(struct node);
    temp->data=data;
    temp->prev=last;
    temp->next=NULL;
    last->next=temp;
    last=temp;

}
//Insert the data at the given position.
void doubly_list:: insert_pos()
{
    struct node *temp,*newnode;
    int pos , data;
    temp=new(struct node);
    newnode=new(struct node);
    cout<<"Which position do you want to inserat new data in list : ";
    cin>>pos;
    cout<<"Enter the data :";
    cin>>data;
    temp=head;
     newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
      int i=0;
    while(i!=pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=newnode;
  newnode->prev=temp->prev;
  temp->prev=newnode;
  newnode->next=temp;
}
//Display the data after each operation.
void doubly_list::display()
{
    struct node *temp;
    temp=head;
    int i=1;
    while(temp!=NULL)
    {
        cout<<"Data in Node "<<i<<": "<<temp->data<<endl;
        temp=temp->next;
        i++;
    }
}
int main()
{
    doubly_list d1;
    int n;
    cout<<"Enter the number of data in doubly linked list : ";
    cin>>n;
    d1.create_list(n);
    d1.display();
    cout<<"Insert operation at the begining :-\n "<<endl;
    d1.insert_beg();
    d1.display();
    cout<<"Insert operation at the end :-\n"<<endl;
    d1.insert_last();
    d1.display();
    cout<<"Insert operation at the middle :-\n"<<endl;
    d1.insert_pos();
    d1.display();
}