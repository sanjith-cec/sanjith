//example 1:printnumber 1 to 10
#include<stdio.h>
int main()
{  
    for(int i=1; i<=10; i++)
    {
        printf("%d\n",i);
    }

//example 2: print evan numbers
     for (int i = 2; i <= 20; i += 2);
    {
    printf("%d\n", i);
    }

//example 3:calculate sum of first 5 number
    int sum =0;
   
    for (int i=1; i<=5; i++)
   {
    sum +=i;
   }
   printf("sum=%d",sum);
}