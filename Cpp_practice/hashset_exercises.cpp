#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void sets_and_iterators()
{
    unordered_set<int> hashset;
    hashset.insert(3);
    hashset.insert(1);
    hashset.insert(4);
    hashset.insert(2);
    unordered_set<int>::iterator it;
    //method 1 - with a for loop
    for(it= hashset.begin(); it != hashset.end();it++)
        cout << *it << " ";
    cout <<endl;
    
    hashset.erase(2);
    //method 2
    for( auto &itr:hashset)
        cout << itr << " ";
    cout <<endl;
    // check if the key is in the hash set
    if (hashset.count(2) <= 0) {
        cout << "Key 2 is not in the hash set." << endl;
    }
    //find without a for loop
    unordered_set<int>::iterator i;
    int num=5;
    i= hashset.find(num);
    if(i != hashset.end())
        printf("Found key %d in the hashset\n", *i);
    else
        cout << num<<" not found in the hashset"<<endl;
    
    unordered_set<std::string> myset = {"sand","water","hello","ice","foam"};
    cout << "Num of Buckets "<< myset.bucket_count() <<endl;
    for (const std::string& x: myset)
        cout << x << " is in bucket #" << myset.bucket(x) << std::endl;
    cout << "Size of bucket#3="<<myset.bucket_size(3)<<endl;
}
void vector_set_convert()
{
    vector<int> nums1 = {3,2,4,5,3,5,6,1};
    cout << "Original vector with duplicate numbers is "<<endl;
    for(auto &i:nums1)
        cout << i << " ";

    //method 1
    unordered_set<int> set1(nums1.begin(), nums1.end());
    cout <<endl<< "Vector to set convert 1 "<<endl;
    for( auto i:set1)
        cout << i << " "; 

    //method 2
    cout << endl<< "Vector to set convert 2 "<<endl;
    unordered_set<int> set2;
    // Traverse the Vector
    for (int x : nums1)
        set2.insert(x);
    for( auto i:set2)
        cout << i << " "; 

    //convert back
    cout <<endl << "Hash set to vector: "<<endl;
    vector<int> nums2 (set1.begin(), set2.end());
    //nums2.push_back(i);
    for(auto &i:nums2)
        cout << i << " ";
}
bool find_duplicate()
{
    //find only if a duplicate exists, not the position of a duplicate
    vector<int> nums = {3,2,4,5,4,3,4};
    unordered_set<int> set (nums.begin(), nums.end());
    //method 1
    //return nums.size() > set.size();
    //if vector is larger, return true.
    //unordered_set removed duplicates during insertion
    //method 2
    for(auto i:nums)
    {
        if(set.count(i)>0){
            cout <<endl<<endl<< "Duplicates exist "<<endl;
            return true;
            //if we want indexes of duplicate numbers, use hashmap. Not hashset.
        }
        else
            set.insert(i);
    }
    cout << "No Duplicates found "<<endl;
    return false;
}
int main (void)
{
    sets_and_iterators();
    vector_set_convert();
    find_duplicate();
    return 0;
}
//method 2 - vector<int>