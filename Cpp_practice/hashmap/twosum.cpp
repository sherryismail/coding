#include <iostream>
#include <map>
#include <vector>
using namespace std;
/*{2,7,11,15} and target value is 9. Find two elements that add up to target value. Find their indexes
if it was onyl find numbers, then unordered_set was enough. Here find more information i.e. indexes
store values are pairs.
                 | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
*/class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        int diff;
        vector<int> results;
        for(int i=0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            map<int,int>::iterator it;
            it = mymap.find(diff);
            if (it != mymap.end())
            {
                results.push_back(mymap[diff]);//the value at mymap[diff](which is actually the index of the nums[i])
                results.push_back(i);//the index of this number used as a reference
                return results;//only one valid answer exists
                
            }else //number not found, so add it to database for next iter use
                mymap[nums[i]]=i;//map[num](here num=key to search with) = index(value of our interest)
                // mymap.insert({nums[i],i});
        }
        cout << "nothing found";
        return results;//return empty if no matching pairs found
        //time complexity O(n)
    }

    vector<int> bruteForce(vector<int>& nums, int target) {
        vector<int> pair;
        int diff;
        for (int i=0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            for (int j=0; j<nums.size(); j++)
            {
                if(nums[j]==diff && i != j)
                {
                    pair.push_back(i);
                    pair.push_back(j);
                    return pair;//only one valid answer exists
                }
            }
        }
        return pair;
        //time complexity N^2
    }
    vector<int> twopointers(vector<int>& nums, int target) {
        int j= 0;
        int k= nums.size()-1;
        vector<int> pair;
        int diff;
        while ( j < k)
        {
            diff = target - nums[j] - nums[k];
            if(diff == 0)
            {
                pair.push_back(j);
                pair.push_back(k);
                break;
            }else if (diff <0)
                k--;
            else if (diff >0)
                j++;
        }
        return pair;
    }
};
int main(void)
{
    vector<int> input = {2,7,11,-15};
    Solution s;
    int target = -4;
    vector<int> output = s.twoSum(input,target);
    vector<int>::iterator it;
    cout << "hashmap->";
        for(it = output.begin(); it != output.end(); it++)
        {
            cout << " "<< *it;
        }
        cout <<endl<<"brute force->";
    output = s.bruteForce(input,target);
        for(it = output.begin(); it != output.end(); it++)
        {
            cout << " "<< *it;
        }
    cout <<endl<<"two pointers->";
    output = s.twopointers(input,target);
        for(it = output.begin(); it != output.end(); it++)
        {
            cout << " "<< *it;
        }
}