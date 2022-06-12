#include<stdio.h>
#include<conio.h>
/*
This sorting algorithm, iterates through the array and finds 
the smallest number in the array and swaps it with the first 
element if it is smaller than the first element. Next, it 
goes on to the second element and so on until all elements are sorted.
Time complexity: O(N^2)
Space Complexity: O(1). no other array is used.
*/
void main()
{
int total_count,i,j,minimum,temp_value;
int a[20];
printf("\n Enter the Number of Elements: ");
scanf("%d",&total_count);
printf("\n Enter %d Elements: ",total_count);
for(i=0;i<total_count;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<total_count-1;i++)  //O(n)
{
   minimum=i;
   for(j=i+1;j<total_count;j++) //O(n-1)
   {
      if(a[minimum]>a[j])
         minimum=j;
   }
   // if(minimum!=i)
   {
      temp_value=a[i];
      a[i]=a[minimum];
      a[minimum]=temp_value;
   }
}
printf("\n The Sorted array in ascending order: ");
for(i=0;i<total_count;i++)
{
printf("%d ",a[i]);
}
getch();
}