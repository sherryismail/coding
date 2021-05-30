#include <bits/stdc++.h>

using namespace std;
/*
Array is sorted in 3 swaps.
First Element: 1
Last Element: 3
*/
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void swap(int * x, int * y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    // Write your code here
    int number = 0;
    for (int i=0; i < a.size(); i++)
    {
        for (int j=0; j < i; j++)
        {
            if (a[j] > a[i])
            {
                swap(&a[j],&a[i]);
                number++;
            }
        }
    }
    cout << "Array is sorted in "<<number <<" swaps."<<endl;
    cout << "First Element: " <<a[0] <<endl;
    cout << "Last Element: "<<a [a.size() - 1] << endl;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
