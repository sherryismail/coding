// #include <stdio.h>
// #include <stdint.h>
// #include <stdlib.h>
// #include <string.h>
#include <iostream>
using namespace std;

int * pascal(int rowIndex) {
     //base case
    if(rowIndex==0){
        int * cur = new int;
        *cur= 1;
        printf("%d\n", cur[0]);
        return cur;
    }
    else
    {
        int i=0;
        int * prev = pascal(rowIndex-1);
        int * curr = new int[rowIndex+1];
        curr[i] = 1;//first element of each row is 1
        printf("%d ", curr[i]);
        for(i=1; i < rowIndex; i++)//total n+1 elements
        {
            curr[i] = prev[i-1] + prev[i];
            printf("%d ", *(curr+i));
        }
        curr[i]= 1;//i is incremented to final pos of row
        printf("%d\n", curr[i]);
        delete(prev);
        return curr;
    }
}
int main() {
  
  /* Put any tests here. */
  int row = 0, returnSize;
  cout <<"Enter number: ";
  cin >> row;

  int * res = pascal(row);
  cout << row <<" row in pascals triangle is:"<< endl;
  for(int i=0; i <= row; i++)
  {
    cout<< " "<< *(res++);
  }
  return 0;
}