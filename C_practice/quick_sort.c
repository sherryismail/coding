#include<stdio.h>
#include <stdint.h>
void quicksort(int number[25],int first,int last);
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
    int k=0;
   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;
    printf("i=%d, j=%d,pivot=%d,num[pivot]=%d<--START\n", i, j,pivot,number[pivot]);
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)//numbers on LHS 
            i++; //stop if are not less than num[pivot]. swap needed here
         while(number[j]>number[pivot])//numbers on RHS 
            j--; //stop if numbers are not greater than num[pivot]. swap needed here
        printf("i=%d, j=%d,pivot=%d<--COUNTER ", i, j,pivot);
        if(i<j)
         {
            for(k=0;k<6;k++)
                printf("%d ",number[k]);
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
            printf(" swapped to ");
         }
         for(k=0;k<6;k++)
                printf("%d ",number[k]);
        printf(".");
      }
        //swap the pivot with jth element so pivot is the largest number from first,....pivot
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
        printf(" last swap: %dth <-> %dth => ", pivot,j);
      for(k=0;k<6;k++)
            printf("%d ",number[k]);

      printf("\nfirst half quicksort(%d,%d)\n",first,j-1);
      quicksort(number,first,j-1);
      printf("second half quicksort(%d,%d)\n",j+1,last);
      quicksort(number,j+1,last);
   }
   else
    printf("\n***first [%d] < last[%d] not succeed***\n",first,last);
}

int main(void){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}


