/*Move Zeros to the Left 
Given an integer array, move all elements that are 0 to the left 
while maintaining the order of other elements in the array.
 The array has to be modified in-place.
 1 10 20 0 59 0 63 0 88 0
 Output = 0 0 0 0 1 10 20 59 63 88
*/
#include <stdlib.h>
#include <stdio.h>
//two pointer problem
void move_zeros_to_left(int A[], int n) {
    int wr=n-1;
    int rd=n-1;
    while(rd >= 0)
    {//error: if array has no zeros, below if never happens
        if(A[rd]!= 0){
        //move the non-zero value to the location where write pointer was
            A[wr] = A[rd];
            wr--;
        }
         rd--;//move to the next non-zero value
    }
    while(wr>=0)
    {
        A[wr] = 0;
        wr--;
    }
}

void main()
{
    int size, i;
     printf("Enter the size of array:");
    scanf("%d", &size);
    i= 0;
    int * arr = malloc(sizeof(int) * size);
    while(i<size)
    {
        scanf("%d ", &arr[i]);
        i++;
    }
    printf("\nMoved all zeros to left:");
    move_zeros_to_left(arr, size);
    for(i=0; i < size;i++)
    {
        printf("%d ", arr[i]);
    }
}