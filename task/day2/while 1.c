//example 3:sum of digits
# include <stdio.h>
int main()
{
int num=1234, sum= 0;
while (num>0)
{
    sum += num % 10;
    num /= 10;
}
printf("sum of digits =%d\n",sum);
}