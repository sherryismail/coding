
#include <stdio.h>
#include <stdint.h>
#include <string.h>
/* Find the smallest number missing in the array, given
    values in A[] 1 to 100,000. N= number of possible elements 100,000
*/
#define MAX_NUM 100000
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i=0; 
    int missing = 1;
    int check[MAX_NUM];//memset to zero
    int num;
    for (i=0; i < N; i++)
    {
        if (*A == 0)
            continue;
        else {
        num = *A;
        check[num] += 1;
        }
        A++;
    }
    i=1;
    
    while (1)
    {
        if (check[i] <= 0)
        {
            missing = i;
            printf("found %d\n", missing);
            break;
        }
        i++;
    }
    return missing;
}
void main(){
    int a[7] = {1,2,3,6,7,3,4};
    int x = solution(&a[0],7);
    printf("X is %d", x);
}
/*given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].*/