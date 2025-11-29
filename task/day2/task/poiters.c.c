// // Theory summary:
// Integers stored using 2’s complement


// Floating point stored using IEEE 754 format


// MSB determines sign

----------------------------------------------------------------------------------------------------
sum_of_digits.c
------------------------------------------------------------------------------------------------------

#include <stdio.h>

int main() {
    int num, sum = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }

    printf("Sum of digits = %d\n", sum);
    return 0;
}

// sum += num % 10;
// num /= 10;
// These two statements work together to extract digits from the number from right to left and add them to sum.

// 🧠 Statement 1:
// c
// Copy code
// sum += num % 10;
// ➡ % is modulus operator → gives remainder after division
// ➡ num % 10 gives the last digit of num

// Example:

// makefile
// Copy code
// num = 456
// num % 10 = 6
// Then:

// bash
// Copy code
// sum = sum + 6
// ✔ This adds the last digit to sum

// 🧠 Statement 2:
// c
// Copy code
// num /= 10;
// ➡ /= means: num = num / 10
// ➡ Removing the last digit from the number

// Example:

// ini
// Copy code
// num = 456 / 10 = 45
// (Decimal part is dropped → integer division)


