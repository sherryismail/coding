#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include "prime_test.hpp"
using namespace std;
int is_it_prime(int * input, int T)
{
    int prime = 1;
    for (int i=0; i < T; i++)
    {
        prime = 1;
        if (input[i] == 0 || input[i] == 1)
            prime = 0; 
        else if (input[i] == 2)
            prime = 1;
        else
        {
            for (int j=2; j <= ceil(sqrt(input[i])); j++)//  input[i]/j check fails at input=1
        {
                if (input[i] % j == 0)//0 is not prime
                {
                prime = 0;
                break;
                }
        }
        }

        if (prime == 0)
            cout << "Not prime" << endl;
        else
            cout << "Prime" << endl;
    }
    return 0;
}
#ifndef GOOGLETEST
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     int T,num, i=0;
//     cin >> T;
//     int * input = (int *) malloc (sizeof(int) * T);
//     while(i < T){
//         cin >> input[i];
//         i++;
//     }
//     is_it_prime(input,T);
//     return 0;
// }
#endif