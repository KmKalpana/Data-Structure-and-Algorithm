#include <stdio.h>
#include <stdlib.h>
struct adjnode
{
    int dest;
    struct adjnode* next;
};
struct adjlist
{
  struct adjnode* head;
};
struct graph
{
    int v;
    struct adjlist* array;
};
struct graph* create(int v)
{
    struct graph* Graph = (struct graph*)malloc(sizeof(struct graph));
     Graph->v=v;
     Graph->array=(struct adjlist*)malloc(sizeof(struct adjlist)*v);
     for(int i=0; i<v; i++)
     {
         Graph->array[i].head=NULL;
     }
     return Graph;
}
struct adjnode* newadjnode(int dest)
{
     struct adjnode* newnode=(struct adjnode*)malloc(sizeof(struct adjnode));
     newnode->dest=dest;
     newnode->next=NULL;
     return newnode;
}
void addedge(struct graph* graph, int src, int dest)
{
        struct adjnode* check=NULL;
        struct adjnode* newnode=newadjnode(dest);
        if(graph->array[src].head==NULL)
        {
             newnode->next=graph->array[src].head;
             graph->array[src].head=newnode;
        }
        else
        {
            check=graph->array[src].head;
            while(check->next!=NULL)
            {
                check=check->next;
            }
            check->next=newnode;
        }
        newnode=newadjnode(src);
        if(graph->array[dest].head==NULL)
        {
            newnode->next=graph->array[dest].head;
            graph->array[dest].head=newnode;
        }
        else{
            check=graph->array[dest].head;
            while(check->next!=NULL)
            {
                check= check->next;
            }
            check->next=newnode;
        }

}
void print(struct graph* graph)
{
    for(int i=0; i<graph->v; i++)
    {
        printf("vertex of %d index is : ",i);
        struct adjnode* p = graph->array[i].head;
         while(p)
         {
             printf("->%d",p->dest);
             p=p->next;
         }
         printf("\n");
    }
}
int main()
{
  int v=5;
  struct graph* Graph=create(v);
  addedge(Graph,0,1);
  addedge(Graph,0,4);
  addedge(Graph,1,2);
  addedge(Graph,1,3);
  addedge(Graph,1,4);
  addedge(Graph,2,3);
  addedge(Graph,3,4);
  print(Graph);
}