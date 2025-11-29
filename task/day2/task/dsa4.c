//3. Stack using Dynamic Array
// Example App: Chrome / YouTube — Back navigation history
// → Each visited page/video pushed; going back pops.

#include <stdio.h>
#include <stdlib.h>
int *stack, top=-1, cap=2;
void push(int v){ if(top==cap-1){cap*=2;stack=realloc(stack,cap*sizeof(int));} stack[++top]=v; }
int pop(){ return (top==-1)?-1:stack[top--]; }
int main(){
    stack=malloc(cap*sizeof(int));
    push(11); push(22); push(33);
    printf("Back to video ID: %d\n", pop());
}