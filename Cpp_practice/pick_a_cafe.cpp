/*uppose Andy and Doris want to choose a restaurant for dinner,
 and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. 
If there is a choice tie between answers, output all of them with no order requirement. 
You could assume there always exists an answer.
Input: 
list1 = ["Shogun","Tapioca Express","Burger King","KFC"], 
list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1)
Burger King has higher index number as a sum and is less priority
*/
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class hashmap {
    public:
        
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> cafes;//wont work (list1.begin(), list1.end());
        vector<string> common;
        //method 2: create a map<int,string> and return map.begin()->second; to return the smallest
        int first_choice = 1001;
        
        for(int i=0; i < list1.size();i++)
            cafes[list1[i]]=i;//nam eofrestaurant is key, index is stored as some non-zero value
        unordered_map<string,int>::iterator it;
        for(int i=0; i < list2.size(); i++)
        {
            it = cafes.find(list2[i]);
            if(it != cafes.end())
            {
                //store the smaller of the two indexes
                if(first_choice> cafes[list2[i]] + i)
                {
                    first_choice = cafes[list2[i]] + i;
                    common.clear();
                    common.push_back(it->first);
                }
                else if(first_choice ==cafes[list2[i]] + i)
                    common.push_back(list2[i]);
            }
        }
        return common;
    }
};
int main (void)
{
    vector<string> a = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> b = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};//expected answer Shogun
    hashmap s;
    vector<string> c = s.findRestaurant(a,b);
    for(int i=0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;
    a={"Shogun","Tapioca Express","Burger King","KFC"};
    b = {"KFC","Shogun","Burger King"};//expected output: shogun only
    c = s.findRestaurant(a,b);
    for(int i=0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;
    //edge case
    a= {"Shogun","Tapioca Express","Burger King","KFC"};
    b = {"KFC","Burger King","Tapioca Express","Shogun"};
    c = s.findRestaurant(a,b);//Expected: ["KFC","Burger King","Tapioca Express","Shogun"]
    for(int i=0; i < c.size(); i++)
        cout << c[i] << " ";
}