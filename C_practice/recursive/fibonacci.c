#include <stdio.h>
/*method 1: recursive
Time Complexity - O(2^N)
Space Complexity - O(N) */
int fib1(int n)
{
    if (n == 0 || n == 1)
    return n;
    else
        return fib1(n-1) + fib1(n-2);
}
/*method 2 : Dynamic programming
Time Complexity - O(N)
Space Complexity - O(N)
*/
int fib2(int n)
{
    if(n<2)
        return n;
    int num[n+2];
    num[0] = 0;
    num[1] = 1;
    for(int i=2; i<=n;i++)
        num[i] = num[i-1] + num[i-2];
    return num[n];
}
/*method 3: Imperative approach
storing only two previous fibonacci values in two variables.
Time Complexity - O(N)
Space Complexity - O(1)*/
int fib3(int n)
{
    if(n<2)
        return n;
    int a=0, b=1, c=0;
    for(int i=1; i <n; i++)//tricky range of iteration
    {
        c = a+b;
        a=b;
         b =c;
    }
    return c;
}
void main()
{
    printf("%d %d %d", fib1(4), fib2(4), fib3(4));
}