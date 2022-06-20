#include <iostream>
#include <vector>
using namespace std;
//sort array by Parity
vector<int> sortArraybyParity(vector<int> &nums)
{
    vector<int> output;
    for(int i=0;i< nums.size();i++)
    {
        if(nums[i] %2==0)
        output.push_back(nums[i]);
    }
    for(int i=0;i< nums.size();i++)
    {
        if(nums[i] %2!=0)
        output.push_back(nums[i]);
    }
    return output;
}
int main(void)
{
    vector<int> input = {3,5,4,7};
    vector<int> output = sortArraybyParity(input);
     for(int i=0;i < output.size(); i++)
     cout << output[i] <<" ";
     
}