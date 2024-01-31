#include <iostream>
#include <cmath>
using namespace std;
 
// Returns true if `n` is a power of four
bool checkPowerOf4(unsigned n)
{
    // find `log4(n)`
    double i = log(n) / log(4);
 
    // return true if `log4(n)` is an integer
    return i == trunc(i);
}
// Returns true if the binary representation of `n` is a palindrome
bool isPalindrome(unsigned n)
{
}
//https://www.techiedelight.com/power-function-implementation-recursive-iterative/
//calculate pow(x,n), iteratively recursively and bitwise
 
int main()
{
    unsigned n = 256;
 
    if (checkPowerOf4(n))
        cout << n << " is a power of 4"<<endl;
    else
        cout << n << " is not a power of 4"<<endl;

    int x=5,y=67;
    cout << (x^y) << " is same as XOR operation " <<(x | y) - (x & y)<<endl;
 
    return 0;
}