/*
TODO: CLEVER LOGIC of hashset DIFFICULT
Given an integer array nums and an integer k,
return true if there are two distinct indices i and j in the array
such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false*/
// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1121/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> s;

        if (k <= 0)
            return false;
        if (k >= nums.size())
            k = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) // remove the NUMS if they do not satisfy abs(i-j) <=k
                s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }
        // maintain a set s which contain unique values from nums[i - k] to nums[i - 1],
        // if nums[i] is in set s then return true else update the set.
        return false;
    }
    //method 2 - also accepted. 

    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
            {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};