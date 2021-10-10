#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int top ;
    int *stack;
};
void create(struct Stack *s)
{
    s->top=-1;
    s->stack=(int*)malloc(sizeof(int));
    
}
void push(struct Stack *s,int data)
{
    if(s->top==-1)
    {
        s->top=0;
        s->stack[s->top]=data;
    }
    else
    {
        s->top++;
        s->stack[s->top]=data;
    }
}
void pop(struct Stack *s)
{
int x= s->stack[s->top];
s->top--;
cout<<"pop element is : "<<x<<endl;
}

int main()
{
    struct Stack s;
    create(&s);
    push(&s,5);
    push(&s,8);
    push(&s,45);
    push(&s,56);
    for(int i=s.top; i>=0; i--)
    {
        cout<<s.stack[i]<<' ';
    }
    cout<<endl;
    pop(&s);
    for(int i=s.top; i>=0; i--)
    {
        cout<<s.stack[i]<<' ';
    }
    }
