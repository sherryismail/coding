// number pyramid

// indent format code Shift + Alt + F
#include <stdio.h>
/*1                  1
12                21
123              321
1234            4321
12345          54321
123456        654321
1234567      7654321
12345678    87654321
123456789  987654321
1234567891010987654321*/
void split_pyramid(int num)
{
    fflush(stdout);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= 2 * num; j++)
        {
            if (j <= i)
                printf("%d", j);
            else if (j > (2 * num - i))
                printf("%d", 2 * num - j + 1);
            else
                printf(" ");
        }
        printf("\n");
    }
    // or use two series of for loops, second one is j--;
    // then enter "\n"
}
// Program in C to print the Number Diamond Pattern
/*
   1
  123
 12345
1234567
 12345
  123
   1 
*/
void numeric_diamond(int n)
{
    int i, j, k;
    int half_max = n/2 + 1;
    if(n %2 == 0)
        printf("Round off to the next odd number\n");
    for (i= 1; i <= half_max; i++)
    {
        for (j = i; j < half_max; j++)
        {
            printf(" ");
        }
        for (k = 1; k < (i * 2); k++)
        {
            printf("%d", k);
        }
        printf("\n");
    }
    for (i = half_max-1; i >= 1;i--)
    {
        for (j = half_max; j >i; j--)
        {
            printf(" ");
        }
        for (k = 1; k < (i * 2); k++)
        {
            printf("%d", k);
        }
        printf("\n");
    }
}
/*
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/
void pyramid(int rows)
{
    int peak_num = 2 * rows - 1;
    int j,diff = 1;
    for(int i=1; i <= rows; i++)
    {
        for(j=i;j <= rows - 1; j++)
            printf("  ");//each line has spaces first
        //now create a peak value each row reaches.
        //use diff=1 and then diff=-1 to count up/down
        diff = 1;
        j = i;
        peak_num = (2*i)-1;
        while(j>=i){
            printf("%d ", j);
            if (j== peak_num)
                diff = -1;//countdown
            j += diff;
        }
        printf("\n");
    }
}
/* for rows = 6
     * 
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *

*/
void star_pattern(int row)
{
    int i,j,k;
    for(i=1; i <= row; i++)
    {
        for(j=i; j <= row-1; j++)
            printf(" ");
        for(j=1; j <=i; j++)
            printf("* ");
        printf("\n");
    }
    //lower half of the star
    for(i=row-1; i >=1; i--)
    {
        for(j=i; j<=row-1; j++)
            printf(" ");
        for(j=1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}
//Hollow star Diamond
/* Enter num of rows: 6
      *
     * *
    *   *
   *     *
  *       *
  *       *
   *     *
    *   *
     * *
      *
*/
void hollow_star_diamond(int rows)
{
    int i,j;
    for(i=1;i < rows;i++)
    {
        for(j=i; j <= rows; j++)
            printf(" ");
        for(j=(2*i)-1; j>=1;j--)//j=2i-1 because the spaces span over 2x row number of cells
        {
            if(j==1|| j==(2*i-1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    //lower half of hollow star pattern
    for(i=rows-1;i >=1;i--)
    {
        for(j=i; j <= rows; j++)
            printf(" ");
        for(j=(2*i)-1; j>=1;j--)//j=2i-1 because the spaces span over 2x row number of cells
        {
            if(j==1|| j==(2*i-1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
void consecutive_char_triangle(int row)
{
    int i,j;
    for(i=1; i <= row; i++)
    {
        for(j=1; j <=i; j++)
            printf("%c", 'A' + j-1);
        printf("\n");
    }
for(i=1; i <= row; i++)
    {
    for(j=1; j <=i; j++)
            printf("%c", 'A'+ i-1);
        printf("\n");
    }
}
void main(void)
{
    int num = 0;
    printf("Enter num of rows: ");
    scanf("%d", &num);
    split_pyramid(num);
    numeric_diamond(num);
    pyramid(num);
    star_pattern(num);
    hollow_star_diamond(num);
    consecutive_char_triangle(num);
}