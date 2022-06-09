#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int factorial(int);
// Complete the factorial function below.
int factorial(int n) {
    int out;//return in the end of func
    if (n > 1)
        out = factorial(n -1) * n;
    else
    {
        out = 1;
    }
    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cout << getenv("OUTPUT_PATH") << endl;
    int result = factorial(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
