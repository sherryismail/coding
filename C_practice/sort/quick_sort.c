#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define DEBUG_PRINT  0
void quicksort_first(int* number,int first,int last);
void quicksort_last(int* number,int first,int last);
void swap(int *x, int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
void print_elements(int number[25])
{
   int k=0;
   for (k=0; k<6;k++)
    printf("%d ",number[k]);
   printf(".");
}
int partition_first(int *number, int first, int last)
{
   int i, j, pivot, temp;
   int k=0;
   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)//numbers on LHS 
            i++; //stop if are not less than num[pivot]. swap needed here
         while(number[j]>number[pivot])//numbers on RHS 
            j--; //stop if numbers are not greater than num[pivot]. swap needed here

        if(i<j)
         {
            // print_elements(number);
            swap(&number[i], &number[j]);
            printf(DEBUG_PRINT," swapped to ");
            // print_elements(number);
         }
      }
      //swap the pivot with jth element so pivot is the largest number from first,....pivot
      //swap with the final element on the right that stops being bigger than pivot=low
      //newest arr[j] is smaller than pivot so pivot should be inserted in the middle
      swap(&number[pivot],&number[j]);
      return j;
   }
   else
   {
    return -1;
   }
}
//https://hackr.io/blog/quick-sort-in-c
void quicksort_first(int* number,int first,int last)
{
      int j = partition_first(number,first, last);
      if(j!= -1)
      {
         quicksort_first(number,first,j-1);
         quicksort_first(number,j+1,last);
      }
}

//iterative/recursive way to do it
int partition_last(int * number, int first, int last)
{
   int pivot=last, i=first, j=last;
   if (first < last)//????should this check be in quicksort_last?
   {
      pivot=last;
      i=first;
      j=last;
     while (i<j)
     {
        while(number[i] < number[pivot])//IMPORTANT "while" not "if"
        i++;
        while (number[j] >=pivot && j >=first)//<--IMPORTANT. Not "j>low"
        j--;
        if(i<j)
        {
            swap(&number[i], &number[j]);
        }
     } //repeat while loop until 'i' and 'j' cross each other
      //swap the pivot<->the first occurance of a larger element found
        //swap with the final element on the left that stops being smaller than pivot=high
      swap(&number[i], &number[pivot]);
      return i;
   }
   else {
      return -1;
   }
   
}
void quicksort_last(int* number,int first,int last)
{
      int j = partition_last(number,first, last);
      if(j!= -1)
      {
         quicksort_last(number,first,j-1);
         quicksort_last(number,j+1,last);
      }
}

int main(void){
   int i, count;

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);
   int * number = (int *)malloc(sizeof(int)* count);
   int * number2 = (int *)malloc(sizeof(int)* count);
   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++){
      scanf("%d",&number[i]);
      number2[i] = number[i];
   }
   //when the pivot=0
   quicksort_first(number,0,count-1);
   printf("\n\nLow Quick Sort: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
   //pivot is last number
   quicksort_last(number2,0,count-1);
   printf("\n\nHigh Quick Sport: ");
   for(i=0;i<count;i++)
      printf(" %d",number2[i]);

   return 0;
}
/* TIme complexity:
T(n) = T(k) + T(n-k-1) + (n) → (i)

T(k) and T(n-k-1) represent the two recursive calls in the quicksort algorithm. 
The last term (n) represents the partition(),
 while k is representative of the total count of the numbers present in the set 
 that is smaller than the pivot.


Worst case: O(n^2)
When the partition process always picks either the smallest or the greatest element as the pivot, 
it is considered to be the worst case for a quicksort algorithm. k=0;
For instance, in our quick sort in C program, where the last element is selected as the pivot point, 
the worst case occurs if the array is already sorted.
T(n) = T(0) + T(n-1) + (n)
T(0) is one cycle, hence,
T(n) = T(n-1) + (n) 
T(n) = T(n^2 - n)
This gives T(n) the worst case of O(n^2)

Average case : O(n log2(n))
T(n) = T(n-1) + (n) This gives T(n) the worst case of O(n^2)



int partition (int arr[], int low, int high)
{
int pivot = arr[high];//pivot -> last element
int i = (low - 1);

for (int j = low; j <= high- 1; j++)
{
   if (arr[j] <= pivot)
   {
      i++;
      swap(&arr[i], &arr[j]);
   }
   //else arr[j] > pivot, Now 'i' points a number bigger than pivot
}

   swap(&arr[i + 1], &arr[high]);
   return (i + 1);
}
*/