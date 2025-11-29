#include<stdio.h>
#define N 100;

int stack[100];
int top = -1;

void push();
void pop();
void display();

int main(){
    int choice;
    while(1){
        printf("Enter your choice: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        case 4: return 0;
            break;
        default:printf("Invalid Choice!!!");
            break;
        }
    }
}

void push(){
    printf("element is pushed\n");
}

void pop(){
    printf("element is poped\n");
}
void display(){
    printf("this the elements\n");
}