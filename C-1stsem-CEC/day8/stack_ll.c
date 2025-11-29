#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Stack;

Stack *top = NULL;

// PUSH operation
void push(int x) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = x;
    newNode->link = top;
    top = newNode;

    printf("%d pushed into stack\n", x);
}

// POP operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }

    Stack *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->link;
    free(temp);
}

// DISPLAY operation
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    Stack *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- STACK MENU (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
