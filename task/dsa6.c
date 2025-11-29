//Stack using Linked List
//Example App: Snapchat — Undo drawing layers
 //→ Each stroke is pushed; undo pops top layer.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;struct Node*next;
};
   struct Node*top=NULL;
   void push(int v)
{
     struct Node*n=malloc(sizeof(struct Node)); n->data=v; n->next=top; top=n; 
}
int pop()
{
     if(!top) return -1; int x=top->data; top=top->next; return x;
}
int main()
{
    push(101); push(102);
    printf("Undo last stroke ID: %d\n", pop());
}