#include <stdio.h>
int main()
{ 
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;//same as p = &arr[0]
    printf("access using array index:\n");
    for(int i=0;i<5; i++)
    printf("arr[%d] = %d\n", i, arr[i]);

    printf("\naccess using pointer arthemic;\n");
    for (int i = 0; i < 5; i++)
    printf("*p(p+%d)  %d\n", i, *(p + i)); 
    return 0;
}