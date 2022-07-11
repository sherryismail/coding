/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.*/
#include <iostream>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    bool method1(string s) {//another user
        string st;
        map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        st.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if(mp[st.back()] == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        return st.size() ? 0 : 1;
    }
    bool method2(string s) {
        stack<char> sk;
        for(auto &i:s)
        {
            if(i=='[' || i=='{' || i== '(')
                sk.push(i);
            else
            {
                //its closing bracket
                if(sk.empty())//edge case
                    return false;
                if((i==']' && sk.top() != '[') ||
                  (i=='}' && sk.top() != '{') ||
                  (i==')' && sk.top() != '('))
                    return false;
                sk.pop();
            }
        }
        if(sk.empty())
            return true;
        else return false;
    }
};