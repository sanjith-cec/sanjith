//Queue using Linked List
//Example App: Spotify — Song playback queue
 //→ Next songs queued and played one by one.

#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*next;};
struct Node*front=NULL,*rear=NULL;

void enqueue(int v)
{
     struct Node*n=malloc(sizeof(struct Node)); n->data=v;n->next=NULL;
    if(!rear) front=rear=n; else{ rear->next=n; rear=n; }
}
int dequeue()
{
     if(!front) return -1; int x=front->data; front=front->next; if(!front) rear=NULL; return x; 
}
int main()
{
     enqueue(1); enqueue(2); printf("Playing song ID: %d\n", dequeue()); 
}