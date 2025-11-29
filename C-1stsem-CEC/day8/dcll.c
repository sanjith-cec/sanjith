#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

struct Node *head, *tail, *newNode; 

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
            tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        newNode->next=head;
        printf("Do you need to repeat (0|1)");
        scanf("%d",&ch);
    }
    if(head!=NULL){
        printf("Elements: \n");
        tail = head;
        while(tail->next != head){
            printf("%d", tail->data);
            if(tail->next != NULL){
                printf(" -> ");
            }
            tail = tail->next;
        }
        printf("%d",tail->data);
        printf("\n");
    }else{
        printf("Linked List is Empty");
    }
}