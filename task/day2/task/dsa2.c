#include <stdio.h>
# define SIZE 5
int stack[SIZE], top = -1;
void push(int v){if(top<SIZE-1) stack[++top]=v;}
int pop(){return(top ==-1)?-1:stack[top--];}
int main()
{
    push(1);push(2);push(3);
    printf("Undo last filter ID: %d\n",pop());
}