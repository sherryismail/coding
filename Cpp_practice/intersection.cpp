#include <iostream>
#include <vector>
#include <map>
// #include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> arr1, vector<int> arr2, int size1, int size2)
{
    map<int,int> freq;
    vector<int> r;
    //populate the map with frequency of arr1
    for( auto &i:arr1)
    {
        if(freq.find(i) == freq.end())
        {
            freq[i] = 1;
        }
        else
            freq[i]++;
    }
    //find if 
    for(int &i: arr2){
        if(freq.find(i) != freq.end())
        {
            if(freq[i] > 0){//if value already exists and this was set to 1
                r.push_back(i);size2= freq.get(arr2[i]);
                freq[i]--;
            }
        }//else, for arr2[10]=20 did not exist in arr1, so freq.end reaches
    }
    return r;
}
int main ()
{
    string userinput;
    int size1, size2, input;
    puts("Enter size of first array:");
    cin >> size1;
    vector<int>  arr1(size1);

    for (auto &it : arr1) {// arr1.push_back(input);
        cin >> it;
    }

    puts("Enter size of second array:");
    cin >> size2;
    vector<int>  arr2(size2);
    for (auto &it : arr2) {
        cin >> it;
    }
    
    vector<int> arr3 = intersection(arr1, arr2, size1, size2);
    puts("Intersection is:");
    for(int i=0;i < arr3.size(); i++)
        cout << arr3[i] << " ";//space separated

    return 0;

}