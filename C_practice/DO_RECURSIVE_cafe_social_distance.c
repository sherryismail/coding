
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
//seat=1 in my algrithm is occupied seat or not permitted seat
//seat=0 means avialable
long long largest(long long * S, int M)
{
    int i=0;
    long long maxima =0;
    for (i=0; i < M; i++)
    {
        if (S[i]> maxima)
        maxima = S[i];
    }
    return maxima;
}
long long getMaxAdditionalDinersCount(long long N, long long K, int M, long long* S) {
  //fd Write your code here
  int * seating=(int *)malloc(N);
  long long permittedSeats=0;
  long long maxima=largest(S,M)-1; 
  int i=0,j=0;
    printf("Max is %u, ", maxima);
    //set all seats to zerp
    for (i=0; i < N; i++)
      *(seating+i)=0;
      //display all flags set to zero
  for (i=0; i < N; i++)
  {
      printf("[%u] ", *(seating+i));
  }
  printf("\n");

    //flag the indexes where person sits, then flag K seats above and below it
  for (i=0;i<M;i++)
  {
    seating[S[i]-1]=1;
    printf("seat [%u] filled, ", S[i]);
    for (j=1; j<=K;j++)
    {
      if(S[i]+j-1 < N){//flag K neighbour
        seating[S[i]+j-1]++;
      }
      if(S[i]-j-1 >=0){
        seating[S[i]-j-1]++;
      }
    }
  }

  for (i=0; i <N; i++)
  {
      printf("[%u] ", seating[i]);
  }

  for (i=0;i<maxima; )
  {
    if(seating[i] >0)
    {
        i++;
    }   
    else//seat was free
    {
      permittedSeats++;
      for(j=1;j<=K;j++)
      {
          seating[i+j]++;
      }
      i=i+K;
    }
  }

  for (i=maxima; i <N;)
  {
      if(seating[i] == 0)
      {
      permittedSeats++;
      for(j=1;j<=K;j++)
      {
        seating[i+j]++;
      }
      i=i+K;
      }
      else
      i++;
  }
   printf("\nfinal: ");
  for (i=0; i <N; i++)
  {
      printf("[%u] ", seating[i]);
  }
  return permittedSeats;
}

void main() {
    long long extra;

// long long S[2]={2,6}; 
//    extra=getMaxAdditionalDinersCount(10,1,2,(long long *)&S);
//   printf("\nFree seats = %lld", extra);
  
   long long S1[3]={11,6,14};
   extra=getMaxAdditionalDinersCount(15,2,3,(long long *)&S1);
  printf("\nFree seats = %lld", extra);
}
/*
A cafeteria table consists of a row of NN seats, numbered from 11 to NN from left to right. 
Social distancing guidelines require that every diner be seated such that K seats to their left 
and K seats to their right (or all the remaining seats to that side if there are fewer than KK) remain empty.
There are currently MM diners seated at the table, the iith of whom is in seat S_i
​
No two diners are sitting in the same seat, and the social distancing guidelines are satisfied.
Determine the maximum number of additional diners who can potentially sit at the table without 
social distancing guidelines being violated for any new or existing diners, 
assuming that the existing diners cannot move and that the additional diners will cooperate to 
maximize how many of them can sit down.
Please take care to write a solution which runs within the time limit.

N = 10
K = 1
M = 2
S = [2, 6]
Expected Return Value = 3
Sample test case #2
N = 15
K = 2
M = 3
S = [11, 6, 14]
Expected Return Value = 1
In the first case, the cafeteria table has N=10 seats, with two diners currently at seats 22 and 66 respectively. 
The table initially looks as follows, with brackets covering the K=1 seat to the left and right of each existing
 diner that may not be taken.
  1 2 3 4 5 6 7 8 9 10
  [   ]   [   ]
Three additional diners may sit at seats 4, 8, and 10 without violating the social distancing guidelines.
In the second case, only 1 additional diner is able to join the table, by sitting in any of the first 3 seats.
*/