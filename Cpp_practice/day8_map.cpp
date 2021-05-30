#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include<limits> //used to get numeric limits
using namespace std;

#define MAX_ABOUT_LEN 100

void add_to_phonebook(std::map<string,long> * phonebook, string name, long number)
{  
    map<string,long>::iterator it;
    it = phonebook->find(name);//or phonebook->count(name)>0
    if (it != phonebook->end())
    {
        //element found, skip adding!
        //testcase overwrite?
         // Access the Key from iterator
        string key = it->first;
        // Access the Value from iterator
        int value = it->second;
    }
    else 
    {
        //element not found
        phonebook->insert(std::pair<string,long>(name, number));
    }
}

void search_phonebook (map<string,long> * phonebook, string entry)
{
    map<string,long>::iterator it;
    it = phonebook->find(entry);//or phonebook->count(name)>0
    if (it != phonebook->end())
    {
        string key = it->first;
        int value = it->second;
        cout << it->first << "=" << it->second << endl;
    }
    else 
    {
        cout << "Not found" <<endl;
    }
}
int main ()
{
    std::map<string, long> phonebook;
    int num = 0;
    std::cin >> num;
    //testcase out of range
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string delimiter = " ";
    std::string entry;
    for (int i = 0; i < num ; i++)
    {
        getline (cin, entry);    //space is a delimiter
        size_t post = entry.find(delimiter, 0);
        if (post >= entry.length());//testcase
        string name = entry.substr(0, post);
        long number = stoi(entry.substr(post+1, entry.length()));
        //if invalid number testcase
        //if less than num entries
        add_to_phonebook(&phonebook, name, number);
    }
    //read unknown number of lines
  vector<string> user_inp;
  int i=0;
    for (int i=0; std::getline(std::cin, entry); i++ )
    {
        user_inp.push_back(entry);
    }
    for (i=0; i < user_inp.size(); i++)
    {
        search_phonebook(&phonebook, user_inp[i]);
    }
  return 0;
}
