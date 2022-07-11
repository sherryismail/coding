#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;
/* https://fizzbuzzed.com/top-interview-questions-1/
Given an array nums of n integers, are there elements a, b, c in nums
such that a + b + c = 0? Find all unique triplets in the array which give the sum of zero.

Note: The solution set must not contain duplicate triplets.
Example: Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is: [ [-1, 0, 1], [-1, -1, 2] ]
*/
class hashmap
{
public:
//method 1
    vector<vector<int>> threeSum(vector<int> &nums, int target) // time complexity O(n^2)
    {
        vector<vector<int>> output;
        //sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)//1
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); ++j)//2
            {
                int third_num = target-nums[i] - nums[j];
                if (seen.count(third_num))
                {
                    output.push_back({nums[i], nums[j], third_num});
                    // Skip duplicates
                    while (nums[j + 1] == nums[j] && j + 1 < nums.size())
                        ++j;
                }
                seen.insert(nums[j]);
            }
        }
        return output;
    }

//method 2 brute force time complexity O(N^3)
    vector<vector<int>> bruteForce(vector<int> &nums, int target)
    {
        vector<vector<int>> output;
        // sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue; // skip over same values and check j>=i+1
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (k != j + 1 && nums[k] == nums[k - 1])
                        continue;
                    if (nums[i] + nums[j] + nums[k] == target)
                    {
                        output.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return output;
        
    }

    vector<vector<int>> twopointers(vector<int> &nums, int target){
    /*method 3
    _ _ _ _ _ _
   |_|_|_|_|_|_|
    i j-->   <-k  = two pointers
*/
        vector<vector<int>> output;
        for(int i=0; i < nums.size(); i++)
        {
            int j=i+1;
            int k = nums.size() - 1;
            int diff;
            while (j<k)
            {
                diff = target - nums[i] - nums[j] - nums[k];
                if(diff == 0){
                    output.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while (j<k && nums[j] == nums[j-1])
                        j++;//Never let j refer to the same value twice (in an output) to avoid duplicates
                }
                else if(diff > 0)//k is too big so reduce --k
                    k--;
                else if (diff < 0)//nums too small so move j in a sorted array to a higher number
                    j++;
            }
        }
        return output;
    }
};
int main(void)
{
    vector<int> input = {-4,-1,-1,0,1,2};//sorted array
    hashmap s;
    int target = 0;
    vector<vector<int>> output = s.twopointers(input, target);

    cout<< "Number of possibilities to have "<<target << " is " <<output.size()<< endl;;
    //print a vector of vectors vector<vector<>>
    for (auto &i:output)
    {
        for(auto const &j:i)
            cout << " " << j;
        cout <<endl;
    }
}