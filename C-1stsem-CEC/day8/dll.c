#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

struct Node *head, *curr, *newNode; 

int main(){
    head=NULL;
    int ch =1;
    while(ch){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter a number: ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        newNode->prev=NULL;
        if(head==NULL){
            head=newNode;
            curr=newNode;
        }else{
            curr->next=newNode;
            newNode->prev=curr;
            curr=newNode;
        }
        printf("Do you need to repeat (0|1)");
        scanf("%d",&ch);
    }
    if(head!=NULL){
        printf("Elements: \n");
        curr = head;
        while(curr != NULL){
            printf("%d", curr->data);
            if(curr->next != NULL){
                printf(" -> ");
            }
            curr = curr->next;
        }
        printf("\n");
    }else{
        printf("Linked List is Empty");
    }
}