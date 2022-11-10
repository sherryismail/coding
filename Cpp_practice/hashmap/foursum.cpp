#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <threesum.cpp>
using namespace std;
/* https://fizzbuzzed.com/top-interview-questions-1/
GGiven an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/
class fourSum{
    //g++ .\hashmap\foursum.cpp -I .\hashmap\ -DUSED_AS_LIB
    public:
    vector<vector<int>> twopointer(vector<int>& nums, int target) {
        vector<vector<int>> output;
        //sort(nums.begin(), nums.end());
        //T= a+b+c+d
        for (int i=0; i < nums.size(); i++)
        {
            if( i!=0 && nums[i] == nums[i-1])
                continue;//1st num fixed, T-A = b+c+d.... X=b_c_d
           
            for(int j=i+1; j < nums.size(); j++)
            {
                if(j!= i+1 && nums[j] == nums[j-1])
                    continue;//2nd num fixed, T-A-B = c+d
               
                 //two pointers from now on
                 int k=j+1;
                 int l = nums.size() -1;
                 int fourth_num;
                 while (k<l)
                 {
                    fourth_num = target - nums[i] - nums[j]- nums[k];
                    if(nums[l] == fourth_num)
                    {
                        output.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k < nums.size() && nums[k] == nums[k-1])
                        k++; 
                        while(l >=0 && nums[l] == nums[l-1])
                        l--;
                    }
                    else if(nums[l]>fourth_num)// l is too high 
                        l--;
                    else if (nums[l] < fourth_num)
                    k++;
                 }
                   
            }
        }
        return output;
    }//Time complexity : O(N^2 + N) = O(N^2)
    vector<vector<int>> reuse_threesum(vector<int>& nums, int target)
    {
        threeSum s3;
        vector<vector<int>> output;
        for (int i=0; i < nums.size(); i++)
        {
            //skip the duplication
            if (i > 0 && nums[i - 1] == nums[i]) 
                continue;
            vector<int> subset(nums.begin()+i+1, nums.end());
            vector<vector<int>> subOutput = s3.twopointers(nums,target - nums[i]);
            for(int j = 0; j < subOutput.size(); j++) {
                subOutput[j].insert(subOutput[j].begin(), nums[i]);
                output.push_back(subOutput[j]);
            } //TODO: bug here
        }

        return output;
    }
};

int main(void)
{
    vector<int> input = {-2,-1,0,0,1,2};//sorted array
    fourSum s;
    int target = 1;
    vector<vector<int>> output = s.twopointer(input, target);
    cout<< "Two pointers: Number of possibilities to have "<<target << " is " <<output.size()<< endl;;
    //print a vector of vectors vector<vector<>>
    for (auto &i:output)
    {
        for(auto const &j:i)
            cout << " " << j;
        cout <<endl;
    }
    output = s.reuse_threesum(input, target);
    cout<< "Recursive: Number of possibilities to have "<<target << " is " <<output.size()<< endl;;
    //print a vector of vectors vector<vector<>>
    for (auto &i:output)
    {
        for(auto const &j:i)
            cout << " " << j;
        cout <<endl;
    }
}