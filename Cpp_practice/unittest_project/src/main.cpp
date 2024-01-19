#include <cmath>
#include <cstdio>
#include <iostream>
#include "prime.hpp"
using namespace std;
#ifndef GOOGLE_TEST_ACTIVE
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, i=0;
    cin >> T;
    int * input = (int *) malloc (sizeof(int) * T);
    while(i < T){
        cin >> input[i];
        i++;
    }
    is_it_prime(input,T);
    return 0;
}
#endif