#define N 5
#include <stdio.h>

int stack[N];
int top = -1;

int main() {
    int choice, x;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // PUSH
            if (top == N - 1) {
                printf("Stack Overflow!\n");
            } else {
                printf("Enter a number to push: ");
                scanf("%d", &x);
                top++;
                stack[top] = x;
                printf("%d pushed!\n", x);
            }
            break;

        case 2: // POP
            if (top == -1) {
                printf("Stack Underflow!\n");
            } else {
                printf("Popped: %d\n", stack[top]);
                top--;
            }
            break;

        case 3: // DISPLAY
            if (top == -1) {
                printf("Stack is empty.\n");
            } else {
                printf("Stack Elements: ");
                for (int i = top; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
            break;

        case 4:
            return 0; // Exit program

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
