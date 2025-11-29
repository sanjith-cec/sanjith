#include <stdio.h>
int main ()
{
   int arr[] = {2, 4, 6, 8};
   int *p =arr ;
   for (int i=0; i<4; i++)
 {
   printf("%d", *(p+i));
 }
}