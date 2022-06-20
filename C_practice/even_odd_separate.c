#include <stdio.h>
#include <stdlib.h>
//sort array by Parity. even to the left hand side. Any order of numebrs is acceptable
int main()
{

    //  int nums[]={1,2,3,4};
    //  int nums[]={1};
     int nums[] = {3,5,7};   
    int i=0,j=0,k=0;
    int numsSize = 3;
    int * out = (int *)malloc(sizeof(int)* numsSize);
    //*returnSize = numsSize;
    int temp[numsSize];//worst case all are odd
    for(i=0;i < numsSize; i++)
    {
        if(nums[i] % 2==0)
        {
            *(out+ j) = nums[i];
            j++;
        }
        else{
            temp[k++] = nums[i];
        }
    }
    for(i=0;i<k;i++)
    {
        *(out+j+i) = temp[i];
    }
    for(i=0; i<numsSize;i++)
    {
        printf("%d ", out[i]);
    }
}