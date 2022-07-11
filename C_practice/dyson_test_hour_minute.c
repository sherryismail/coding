#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
/* 4 digits 00:00 of time between 00:00 to 23:59. FInd out the number of possible combinations of valid time
given A,B,C and D. 4 digits. 
    NUM0    NUM1 :  NUM2    NUM3
    0,1,2   0=1-9:  0-5     0-9
            1=1-9:
            2=0-3:
          */
int factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}
int findunique(int *arr, int N)
{
    int repeat[2] = {0, 0}; //find duplicate
    //max 2 numbers can have duplicates
    //option 1: 4 duplicates of 1 number
    //option 2: 3 duplicates of 1 number
    //option 3: 2 duplicates of 2 numbers
    //option 4: 2 duplicates of 1 number
    int i, j, k, integers[10]; //10 digits with indexes representing their frequency
    memset(&integers[0], 0, 10 * 4);
    for (i = 0; i < N; i++)
    {
        integers[arr[i]]++;
    }
    j = 0;
    for (i = 0; i < 10; i++)//why was it i=k
    {
        if (integers[i] >= 1)
        {
            repeat[j]++;
            --integers[i]; //do not post decrement
            if (integers[i] == 0)
            {
                j++;
            }

            i--; //go over it again
        }
    }
    return (24 / ((factorial(repeat[0])) * factorial(repeat[1])));
}
int method1(int *options)
{
    int possible_combos[24][4];
    int num_of_combos = findunique(options, 4);
    //num_of_possible_combination = n!/(m! * p!), if some numbers are repeated m and p times
    printf("num of possible digit combos %d\n", num_of_combos);
    int i = 0, j = 0, k = 0, l = 0;
    int times = 0, count = 0;
    //find all possible combinations
    while (times < num_of_combos)
    {
        for (int i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (j != i)
                {
                    for (k = 0; k < 4; k++)
                    {
                        if (k != j && k != i)
                        {
                            for (l = 0; l < 4; l++)
                            {
                                if (l != i && l != j && l != k)
                                {
                                    possible_combos[times][0] = options[i];
                                    possible_combos[times][1] = options[j];
                                    possible_combos[times][2] = options[k];
                                    possible_combos[times][3] = options[l];
                                    times++;
                                    //printf("times=%d, %d %d %d %d\n", times, options[i], options[j], options[k], options[l]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //iterate through all possible_combos to check valid numbers
    for (i = 0; i < num_of_combos; i++)
    {
        //check correct hour digit
        if (possible_combos[i][0] <= 2)
        {
            //NUM1 either 0,1,2
            //if NUM1 is 2 , then NUM2 must be 0-3
            if (possible_combos[i][0] == 2 && (possible_combos[i][1] > 3))
            {
                continue;
            }
            else
            {
                //NUM1 is 0 or 1, NUM2 does not need to be checked
                //next check if NUM3 is :0x to :5x
                if (possible_combos[i][2] <= 5)
                {
                    printf("%d%d:%d%d, \t", possible_combos[i][0], possible_combos[i][1], possible_combos[i][2], possible_combos[i][3]);
                    count++;
                }
            }
        }
    }
    return count;
}
void main(void)
{
    int T = 4, options[4] = {0, 0, 0, 0};
    while (T)
    {
        --T;
        scanf("%d", &options[T]);
    }
    int count = method1(&options[0]);
    printf("\nvalid time formats: %d\n", count);
    //method2(&count[0]);
    //return 0;
}

/*for (l=0; l < 4; l++)
                        {   
                            if (l == i || l == j|| l==k)
                            continue;
                            else{
                                possible_combos[times][0] = options[i];
                                possible_combos[times][1] = options[j];
                                possible_combos[times][2] = options[k]; 
                                possible_combos[times][3] = options[l];
                                */