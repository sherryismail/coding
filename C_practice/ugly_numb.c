#include<stdio.h>
#include <stdint.h>
int IsUgly(int no, int max);
int getNthUgly(int n);
int maxDivide(int a, int b);
int getNthUgly(int n)
{
  int i = 1, count = 1;
  while (n>count)
  {
    i++;
    if (IsUgly(i,n))
        count++;
  }
  return i;
}
int maxDivide(int a, int b)
{
    while (a % b == 0)
    {
        a = a / b;
        if (a == 10)
            printf("a = a / b;a=%d,b=%d\n",a,b);
    }
    return a;
}
int IsUgly(int no, int max)
{
    int x = no;
    no = maxDivide(no, 2);
    if (x == max)
        printf("maxDivide(no, 2) = %d\n",no);
    no = maxDivide(no, 3);
        if (x == max)
        printf("maxDivide(no, 3) = %d\n",no);
    no = maxDivide(no, 5);
        if (x == max)
        printf("maxDivide(no, 5) = %d\n",no);
 
    return (no == 1) ? 1 : 0;
}
 
int main ()
{
  int n,no;
  while (1) {
  scanf("%d", &n);
  no = getNthUgly(n);;
  printf("%dth ugly no. is %d\n ",n, no);
  }
  return 0;
}