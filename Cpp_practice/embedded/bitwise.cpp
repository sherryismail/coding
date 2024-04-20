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
 
bool isPalindrome(unsigned int n)
{
    unsigned int rev = 0, original = n;
    while (n > 0)
    {
        rev <<= 1;// bitwise left shift 'rev' by 1 and prepare the LSB
        if (n&1 == 1)//if LSB is 1
            rev |= 1;//set bit       
        n >>= 1;
    }
    return (rev == original? true:false);
}
//https://www.techiedelight.com/power-function-implementation-recursive-iterative/
//calculate pow(x,n), iteratively recursively and bitwise
int pow_recursive(int x, int y)
{
    //base case
    if (x == 0)
        return 1;
    else if (x ==1 || y == 1)
        return x;
    //recursive case
    else
    {
        return x * pow_recursive(x,y-1);
    }
}
int main()
{
    unsigned n = 256;
 
    if (checkPowerOf4(n))
        cout << n << " is a power of 4"<<endl;
    else
        cout << n << " is not a power of 4"<<endl;

    int x=5,y=67;
    cout << (x^y) << " is same as XOR operation " <<(x | y) - (x & y)<<endl;
    n = 9;
    bool ret = isPalindrome(n);
    cout <<"isPalindrome("<<n<<") = "<<ret <<endl;
    x = 2, y=5;
    cout << "pow_recursive("<<x<<","<<y<<")="<<pow_recursive(x,y)<<endl;
 
    return 0;
}