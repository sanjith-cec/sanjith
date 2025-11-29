#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int choice = 0;
    double a, b, result;

    while (1) {
        /* Menu */
        printf("\nMenu:\n");
        printf("1 - Add\n");
        printf("2 - Subtract\n");
        printf("3 - Multiply\n");
        printf("4 - Divide\n");
        printf("5 - Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            /* invalid non-integer input - clear stdin and continue */
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) ; /* flush */
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue;
        }

        if (choice == 5) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: /* Add */
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &a, &b) != 2) { printf("Invalid numbers.\n"); while(getchar()!='\n'); break; }
                result = a + b;
                printf("Result: %.6g + %.6g = %.6g\n", a, b, result);
                break;

            case 2: /* Subtract */
                printf("Enter two numbers (a b) to compute a - b: ");
                if (scanf("%lf %lf", &a, &b) != 2) { printf("Invalid numbers.\n"); while(getchar()!='\n'); break; }
                result = a - b;
                printf("Result: %.6g - %.6g = %.6g\n", a, b, result);
                break;

            case 3: /* Multiply */
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &a, &b) != 2) { printf("Invalid numbers.\n"); while(getchar()!='\n'); break; }
                result = a * b;
                printf("Result: %.6g * %.6g = %.6g\n", a, b, result);
                break;

            case 4: /* Divide */
                printf("Enter two numbers (numerator denominator): ");
                if (scanf("%lf %lf", &a, &b) != 2) { printf("Invalid numbers.\n"); while(getchar()!='\n'); break; }
                if (b == 0.0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = a / b;
                    printf("Result: %.6g / %.6g = %.6g\n", a, b, result);
                }
                break;

            default:
                printf("Invalid choice. Please choose between 1 and 5.\n");
                break;
        }
        /* clear leftover newline if needed */
        while (getchar() != '\n' && !feof(stdin)) ;
    }

    return 0;
}
