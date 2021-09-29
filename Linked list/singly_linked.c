//Singly Linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
}*head;
//Create the linked list
void create(int size)
{
    struct node *temp, *newnode;
    int i=1,data;
    head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element in %d node : ",i);
    scanf("%d",&data);
    head->data=data;
    temp=head;
    temp->next=NULL;
    for(int i=2; i<=size; i++)
    {
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     {
         break;
     }
     printf("Enter the element in %d node : ",i);
     scanf("%d",&data);
     newnode->data=data;
     temp->next=newnode;
     newnode->next=NULL;
     temp=newnode;
    }
}
//Delete a node.
void deletion(int position)
{
    struct node *delete , *prevnode;
        delete = head;
        prevnode = head;

        for(int i=2; i<=position; i++)
        {
            prevnode = delete;
            delete = delete->next;

            if(delete == NULL)
                break;
        }

        if(delete != NULL)
        {
            if(delete == head)
                head = head->next;

            prevnode->next = delete->next;
            delete->next = NULL;

            free(delete);;
        }
        
}
void display()
{
 struct node *tem;
 tem=head;
 printf("Element is : ");
 while(tem!=NULL)
 {
     printf("%d ",tem->data);
     tem=tem->next;
 }
 printf("\n");
}
int main()
{
    int size,i;
    printf("enter the size of linked list : ");
    scanf("%d",&size);
    create(size);
    display();
    printf("Which number of size do you want to delete: ");
    scanf("%d",&i);
    deletion(i);
    display();
}
