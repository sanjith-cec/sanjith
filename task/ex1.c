//keep taking inoput antil usere enters a prime number
# include<stdio.h>
int main()
{
  int n, i,isprime;
  do {
    printf("number enter maado:");
    scanf("%d",&n);
    isprime=1;
    for (i=2; i*i<=n; i++);
     {
        if(n %i ==0)
        {
            isprime =0;
            break;

        }
     }
    }
  while (isprime ==0);
  printf(" prime number milgai :%d\n",n);
  return 0;
}
