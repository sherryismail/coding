#include <iostream>
using namespace std;
//rule of thumb a * b = GCD * LCM. So you can find one using the other
//method 1
int gcd(int a,int b)
{
    if(a == 0)
    return b;
//a is != 0 so b%a is safe but check inside recursion if b%a argument = 0
    return gcd(b%a,a);
}
int gcd2(int a,int b)
{//not good with negative numbers
    if(a == 0 || b==0)
        return 0;
    else if( a==b)
        return a;
    else if (a>b)
        return gcd2(a-b,b);
    else
        return gcd2(a,b-a);
}
int lcm(int a, int b)
{
    int lcm, i=2;
    if(a>b)
        lcm = a;
    else
        lcm = b;
    while(lcm % b != 0)
    {
        lcm = lcm * i;
        i++;
    }
    return lcm;
}
int main()
{
    int a,b;
    while(1)
    {
        std::cout << "Enter two numbers separated by space: ";
        std::cin >> a >> b;
        std::cout <<"GCD is "<< gcd(a,b)<<endl;
        std::cout <<"GCD2 is "<< gcd2(a,b)<<endl;
        std::cout <<"LCM is "<< lcm(a,b)<<endl;
    }
    

}