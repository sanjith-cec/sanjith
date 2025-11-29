#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head,*newNode,*curr;
int main(){
    head = NULL;
    int ch = 1;
    while(ch){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter a number: ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL){
            head = newNode;
            curr=newNode;
        }else{
            curr->next = newNode;
            newNode->prev = curr;
            curr=newNode;
        }
        printf("DO you need to continue or not (0|1): \n");
        scanf("%d",&ch);

    }
    printf("Elements: \n");
    curr = head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
    return 0;
}