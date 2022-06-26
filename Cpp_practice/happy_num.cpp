#include <iostream>
#include <map>
#include <math.h>
#include <unordered_map>
using namespace std;
/* A happy number is the one with its digits e.g. 19= 1^2 + 9^2 = 82
then 8^2 + 2^2 = 68...
...
converges to 1.

//Given a linked list, determine if it has a cycle loop in it.
One method is hashmap(freq), other is two-pointer Tortoise and hare
if struct Node {
    int position; <--- can tell loop
    int value; 
    struct Node * next;
}
*/
class hash_map {//similar to my algo, with its use of hash_map
public:
    map<int,int> map;
    //unordered_set<int> set;
public:
    bool isHappy(int n)
    {
        while(n != 1){//if num=1, return true
            if(map[n] == 0)//set.find(n) == set.end()
                map[n]++;
            else//num already happened
                return false;

            int sum=0;
            while(n != 0){
                sum+= pow(n%10,2);
                n=n/10;
            }
            n= sum;
        }
        return n==1;
    }
};
class cycle_detect {
public:
    int next(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        return sum;
    }
public:
/*Floyd's cycle detection algorithm is a pointer algorithm that uses only two pointers, 
which move through the sequence at different speeds. 
If there is a loop, they will meet in the loop. 
It is also called the "tortoise and the hare algorithm"
*/
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));   
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1 ;
    }
};

class Sherry_algo {
    public:
    map<int,int> frequency; 
bool isHappy(int n)
{
     //constraints n= [0,2^31 - 1]
    int i=0,j=0;
    bool state;
    int digits[31];//the largest num will have all 31 bits set
    int sum=0;
    for(j=0;j<31;j++)
        digits[j]= 0;

    int dividor = 10;
    while(n >dividor)//then n/dividor=0
    {
        digits[i] = (n%dividor)/(dividor/10);
        printf("[%d] = %d ",i,digits[i]);
        n = n- (n%dividor);
        dividor *= 10;
        i++;
    }
    
    for(j=0; j <i;j++)
    {
        sum += digits[j]*digits[j];
    }
    cout <<"sum="<< sum << endl;
    frequency[sum]++;
    if(frequency[sum] > 2)
        return false;//endless loop
    else if (sum == 1 || n ==1)
        return true;
    else
        state = isHappy(sum);//recursive
    return state; 
}
};
int main (void){
    Sherry_algo s;
    cycle_detect leetcode;
    hash_map hmap;
    bool state;
    int num;
    while(num <= 1000){
        printf("\nEnter a number:");
    cin >> num; 
    state = hmap.isHappy(num);
    if(state == true)
        cout << num << " is Happy :-)";
    else
        cout << endl<< num << " IS NOT HAPPY";
    
    }
}
