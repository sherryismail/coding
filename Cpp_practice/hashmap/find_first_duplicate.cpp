/*
Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.
A simple way to solve this problem is to count the occurrence of each character first. 
And then go through the results to find out the first unique character.
We can also use a hash map to achieve this goal.
ReturnType aggregateByKey_hashmap(vector<Type>& keys) {
    // Replace Type and InfoType with actual type of your key and value
    unordered_map<Type, InfoType> hashtable;
    for (Type key : keys) {
        if (hashmap.count(key) > 0) {
            update hashmap[key];
        }
        // Value can be any information you needed (e.g. index)
        hashmap[key] = value;
    }
    return needed_information;
}

*/
#include <iostream>
#include <unordered_map>
using namespace std;
class hashmap {
public:
    /*  METHOD 1 - THIS IS ALSO AN ACCEPTED SOLUTION
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> alphabet;//int is >1 if repeated
        // vector<pair<int,int>> umap(26);  can also be used
        int index=s.length();
    for (int i=0; i< s.length(); i++) {
        if (alphabet.find(s[i]) != alphabet.end()) {
            alphabet[s[i]].second++;//frequency
        }
        else
        {
            alphabet[s[i]].first=i;//index of char in a string
            alphabet[s[i]].second=1;//frequency
        }
    }
        for(auto it = alphabet.begin(); it != alphabet.end(); it++)
        {
            if(it->second.second == 1 && it->second.first < index)
                index = it->second.first;
            
        }
    return index< s.length() ? index: -1;
        
    }
    */
   //METHOD 2
    int firstUniqChar(string s) {
        unordered_map<char, int> alphabet;
        for (char& c : s) {
            alphabet[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (alphabet[s[i]] == 1) return i;
        }
        return -1;
    }
};