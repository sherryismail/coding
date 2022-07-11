#include <vector>
#include <iostream>
using namespace std;
//tricky DONT UNDERSTAND
//https://www.educative.io/m/all-possible-braces
/* Print all braces combinations for a given value n so that they are balanced. 
Here are a few examples: n=3
 { { { } } } 
 { { } { } } 
 { { } } { } 
 { } { { } } 
 { } { } { } 

n=2 
{ { } } 
{ } { } 
*/

void  print(vector<vector<char>> result){
  for(int i = 0; i < result.size(); i++){
    cout << "[ ";
    for(int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << " "; 
    }
    cout << "]" << endl;
  }
}

void print_all_braces_rec(
    int n,
    int left_count,
    int right_count,
    vector<char>& output, vector<vector<char>>& result) {

  if (left_count == n && right_count == n) {
    result.push_back(output);
  }

  if (left_count < n) {
    output.push_back('{');
    print_all_braces_rec(n, left_count + 1, right_count, output, result);
    //char top = output.front();cout <<  "-"<< left_count<< top << "-";
    output.pop_back();
  }

  if (right_count < left_count) {
    output.push_back('}');
    print_all_braces_rec(n, left_count, right_count + 1, output, result);
    output.pop_back();
  }
}

vector<vector<char>> print_all_braces(int n) {
  vector<vector<char>> result;
  vector<char> output;
  print_all_braces_rec(n, 0, 0, output, result);
  return result;
}

int main() {
  vector<vector<char>> result = print_all_braces(3);
  print(result);
}