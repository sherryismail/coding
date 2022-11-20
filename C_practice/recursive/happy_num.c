#include <stdint.h>
#include <stdio.h>
typedef enum bool {
    false,true,
}bool;
bool isHappy(int n){
    //constraints n= [0,2^31 - 1]
    int i=0,j=0;
    int digits[31], sum=0;
    for(j=0;j<31;j++)
        digits[j]= 0;

    int dividor = 10;
    while(n > 1)
    {
        digits[i] = (n%dividor)/(dividor/10);
        printf("[%d] = %d ",i,digits[i]);
        n = n- (n%dividor);
        dividor *= 10;
        i++;
    }
    
    for(j=0; j <i;j++)
    {
        sum += digits[j]*digits[j];
    }
    printf("\nsum=%d\n", sum);
    if(sum == 0)
        return false;
    else if (sum == 1)
        return true;
    else
        isHappy(sum);
     sleep(1000);
}
void main(void)
{
    int n;
    printf("Enter a number to check if its happy:");
    scanf("%d", &n);
   
    isHappy(n);
}