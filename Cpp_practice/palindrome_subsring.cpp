#include <iostream>
#include <string.h>
using namespace std;
//Given a string find all non-single letter substrings that are palindromes. For instance:
int find_palindromes_in_sub_string(const string& input, int j, int k) {
  int count = 0;
  //start with a small window and widen it at every iter
  for (; j >= 0 && k < input.length(); --j, ++k)
  {
    if (input[j] != input[k]) {      
      break;
    } 
    cout << input.substr(j, k - j + 1) << endl;
    ++count;
  }
  return count;
}

int find_all_palindrome_substrings(const string& input) {
  int count = 0;
  //str = aabbbaa
  /* at every index, make a window and widen it*/
  for (int i = 0; i < input.length(); ++i) {    
    count += find_palindromes_in_sub_string(input, i - 1, i + 1);
    count += find_palindromes_in_sub_string(input, i, i + 1);//??
  }
  return count;
}

int main() {
  string str = "aabbbaa";

  cout << "Total palindrome substrings: "  << find_all_palindrome_substrings(str) << endl;
}