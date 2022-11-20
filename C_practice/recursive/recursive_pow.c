#include <stdio.h>
#include <string.h>
int count = 0;
int power  (int a, int b);
int power (int a, int b)
{
    if (b==0)//start with simplest case of 'h'
        return 1;
    else
        return a * power(a,b-1);
}

int main()
{
    int a,b,c,result;
    printf("Enter a b for pow(a,b):");
    
    scanf("%d %d",&a,&b);
    result = power(a,b);
    printf(" = %d", result);
}