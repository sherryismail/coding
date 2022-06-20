#include <iostream>
using namespace std;
#include <map>

void types_of_dynamic_array()
{
    int size1, size2;
    puts("Enter size of first array:");
    cin >> size1;
    int * arr1 {new int[size1]};//int * arr2 =new int[size2];
   // getline(cin, userinput);
    for(int i=0;i < size1; i++)
        cin >>arr1[i];//space separated
}

void hashmap()
{
    map<int, string> mp;
    map<int,string>::iterator it;
    mp.insert(pair<int,string> (1, "Python"));
    mp.insert(pair<int, string>(3, "C")); 
	mp.insert(pair<int, string>(2, "Java"));
    //mp[3] = "Pearl"; //other way to add element in map
	mp[4] = "JavaScript";
	mp[5] = "R Programming";
    for(it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " at " <<it->second << endl;
    }
    mp.erase(2);
    //like a linked list, [3] will be skipped in the list
    //now added back
    mp[2] = "New value to fill the gap";
    mp.erase(mp.find(4), mp.end()); //removing multiple elements from the map
        for(it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " at " <<it->second << endl;

    }
    std::cout<<endl<<"Size of the map="<<mp.size(); //this will return the number of elements present in the map
	
	it = mp.find(3) ;
    if(it == mp.end()) 
        cout <<endl<< "Key-value pair not present in a map" ; 
    else
        cout <<endl<< "\nKey-value pair present : " 
          << it->first << "->" << it->second ; 
		 
    map<string,int> map2;
    map<string, int>::iterator it2;
    map2.insert(pair<string,int>("Hello",1));
    map2.insert(pair<string,int>("World",2));
    it2 = map2.find("Hello");

    if(it2 == map2.end()) 
        cout <<endl<< "Key-value pair not present in a map" ; 
    else
        cout <<endl<< "\nKey-value pair present : " 
          << it2->first << "->" << it2->second ;
}
int main (void)
{
    int x=1;
    cout <<"The num is "<< x<<endl;
    //if namespace is not used, then call this
    std::cout <<"Scope resolver"<<endl;
    /*
    std::cout <- all function/class from C++ standard library
    lib1::cout <- all function/class from specific library

    */
   hashmap();
   types_of_dynamic_array();
    return 0;
}

