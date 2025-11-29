 //Queue using Dynamic Array
// Example App: Swiggy / Zomato — Food order queue
 //→ New orders enqueue; oldest gets served first.


#include <stdio.h>
#include <stdlib.h>
int *q, f=0,r=-1,size=0,cap=2;
void en(int v) 
{
     if(size==cap){cap*=2;q=realloc(q,cap*sizeof(int));} q[++r]=v; size++; 
}
int de()
{
     if(size==0) return -1; size--; return q[f++]; 
}
int main()
{
    q=malloc(cap*sizeof(int));
    en(501); en(502);
    printf("Serving Order ID: %d\n", de());
}