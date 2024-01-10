#include <bits/stdc++.h>//getline()
#include <exception>
#include <cmath>
using namespace std;
class Calculator : public exception {
    
public:
    Calculator() {};
    int power(int n, int p)
    {
        if (n <0 || p < 0)
            throw range_error("n and p should be non-negative");
        int ans = pow(n,p);
        return ans;
    }
};
int main()
{
    
    // string S;
    // int i;
    // getline(cin, S);
    // try {
    //     i= stoi(S);
    //     cout << i<<endl;
    // } catch (exception &e) {
    //     cout << "Bad String";
    // }
    Calculator myCalculator=Calculator();
    int T,n,p;
     cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    return 0;
}