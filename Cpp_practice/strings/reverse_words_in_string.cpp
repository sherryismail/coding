/**
 * Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
#include <bits/stdc++.h>//#include <iostream>
#include <string>
#include <vector>
using namespace std;
class StringQs{
    public:
    string reverseWords1(string str)
    {
        reverse(str.begin(),str.end());
        str.insert(str.end(), ' ');
        int j=0;
        int n = str.length();//leads to iterator error if used inside the for loop
        for (int i=0; i < n; i++)
        {
            if (str[i] == ' ')
            {
                reverse(str.begin()+j, str.begin()+i);
                //upate the starting index of the next word to reverse
                j = i+1;
            }
        }
        return str;
    }
    
};
// Driver code
int main()
{
    string str = "I like this code";
    StringQs s;
    // Function call
    string rev = s.reverseWords1(str);
 
    // Print the reversed string
    cout << rev;
    return 0;
}