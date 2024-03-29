#include <bits/stdc++.h>//getline()
#include <exception>
#include <cmath>
using namespace std;
int main()
{
    string S;
    int i;
    getline(cin, S);
    try {
        i= stoi(S);
        cout << i<<endl;
    } catch (exception &e) {
        cout << "Bad String";
    }
    return 0;
}


/*Read a string, , and print its integer value; 
if  cannot be converted to an integer, print Bad String.
Note: You must use the String-to-Integer and exception handling constructs built into your submission language. If you attempt to use loops/conditional statements, you will get a  score.

Input Format
A single string, S.
Constraints
1 <= |S| <= 6, where |S| is the length of string S.
S is composed of either lowercase letters (a-z) or decimal digits (0-9).
Output Format
Print the parsed integer value of , or Bad String if  cannot be converted to an integer.

Sample Input 0
3
Sample Output 0
3
Sample Input 1
za
Sample Output 1
Bad String
Explanation

Sample Case 0 contains an integer, so it should not raise an exception 
when we attempt to convert it to an integer. 
Thus, we print the 3.
Sample Case 1 does not contain any integers, so an attempt to convert it 
to an integer will raise an exception. Thus, our exception handler 
prints Bad String. */