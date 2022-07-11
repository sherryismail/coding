#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int * pascal(int rowIndex, int * returnSize) {
     //base case
    
    if(rowIndex==0){
        int * cur = (int *)malloc(sizeof(int));
        *cur= 1;
        printf("%d\n", cur[0]);
        return cur;
    }
    else
    {
        int i=0;
       
        int * prev = pascal(rowIndex-1,returnSize);
        *(returnSize) = rowIndex+1;//nth row has n+1 elements
        int * curr = (int *)malloc(sizeof(int) * (rowIndex+1));
        curr[i] = 1;//first element of each row is 1
        printf("%d ", curr[i]);
        for(i=1; i < rowIndex; i++)
        {
            curr[i] = prev[i-1]+prev[i];
            printf("%d ", *(curr+i));
        }
        curr[i]= 1;//i is incremented to final pos of row
        printf("%d\n", curr[i]);
        
        free(prev);
        return curr;
    }
}
int main() {
  
  /* Put any tests here. */
  int row = 0, returnSize;
  printf("Enter number: ");
  scanf("%d", &row);

  int * res = pascal(row, &returnSize);
printf("\n%dth row in pascals triangle is:\n", row);
  for(int i=0; i <= row; i++)
  {
    printf("%d ", *(res++));
  }
  
  return 0;
}