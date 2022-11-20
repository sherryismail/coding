#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
/*
returned: 1 1 2010
due: 31 12 2009
Test case : "23 12 1234
            19 9 2468" , expected output = 0, my output = 1500
should be 1 day late but expect 10,000 Hackos fine */
string rtrim(const string &);
vector<string> split(const string &);
struct date {
    int day;
    int month;
    int year;
};

int decide_fine(struct date * libr_dates)
{
    struct date * returned = &libr_dates[0];
    struct date * due = &libr_dates[1];
    if (returned->year > due->year)
        return 10000;
    else if ( returned->year == due->year)//same year
    {
        if (returned->month > due->month)
        {
            return (500 * (returned->month - due->month));
        } 
        else if (returned->month == due->month) //same month
        {
            if (returned->day > due->day) 
            {
                return (15 * (returned->day - due->day));
            }
            else //within due dat
                return 0;
        }
        else 
        {//returned->month < due->month)
            return 0;
        }
    }
    else {// returned->year < due->year
        return 0;
    }
    return -1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    struct date library_dates[2];
    for (int i = 0; i < 2; i++) 
    {
        string date_temp;
        getline(cin, date_temp);

        vector<string> date_full = split(rtrim(date_temp));
    
        library_dates[i].day = stoi(date_full[0]);
        library_dates[i].month = stoi(date_full[1]);
        library_dates[i].year = stoi(date_full[2]);
    }
    int fine = decide_fine(library_dates);
    cout << fine;
    return 0;
}

string rtrim(const string &str) {
    string s(str);
    // TODO: Understand what happens here to convert 3-12-2015 date format
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