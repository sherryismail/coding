/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Input: s = "egg", t = "add"
Output: true
Input: s = "foo", t = "bar"
Output: false
Input: s = "paper", t = "title"
Output: true
*/
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class hash_map {
public:
    bool isIsomorphic(string s, string t) {
        return IsOkay(s,t) && IsOkay(t,s);//check two way maps
    }
    bool IsOkay(string s, string t){
        map<char,char> iso;
        //populate the map. all letters uniquely map one to one.
        for(int i=0; i < t.length();i++)
        {
            map<char,char>::iterator it;
            it = iso.find(t[i]);
            if(it != iso.end())
            {
                //already mapped. check that key maps to the value
                if(iso[t[i]] != s[i])
                    return false;
            }else{
                //this letter is not mapped. add it
                iso[t[i]] = s[i];
            }
        }
        return true;
    }
};
int main(void)
{
    string a= "paper", b= "title";
    hash_map s;
    bool res = s.isIsomorphic(a,b);
    if(res==true)
    cout << a<<" and "<< b<< " are isomorphic";
    else
    cout << "not isomorphic strings";
    return 0;
}