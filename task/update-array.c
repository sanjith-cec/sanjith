#include <stdio.h>
int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int pos =1;
    int newvalue = 98;
    
    arr [pos] = newvalue;
    
    printf ("arr after update;\n");
    for(int i = 0; i < 5; i++)
    {
     printf("%d", arr[i]);
    }
    return 0;
}  