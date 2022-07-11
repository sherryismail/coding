#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
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
class hashmap{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
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
    }
};

int main(void)
{
    vector<int> input = {-2,-1,0,0,1,2};//sorted array
    hashmap s;
    int target = 1;
    vector<vector<int>> output = s.fourSum(input, target);

    cout<< "Number of possibilities to have "<<target << " is " <<output.size()<< endl;;
    //print a vector of vectors vector<vector<>>
    for (auto &i:output)
    {
        for(auto const &j:i)
            cout << " " << j;
        cout <<endl;
    }
}