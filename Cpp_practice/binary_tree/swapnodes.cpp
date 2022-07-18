#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 *                                 Depth
    1               1            [1]
   / \             / \
  2   3     ->    3   2          [2]
   \   \           \   \
    4   5           5   4        [3]
    In-order traversal of left tree is 2 4 1 3 5 and of right tree is 3 5 1 2 4.

6
2 3
4 -1
7 8
-1 -1
-1 -1
-1 -1
1
1
4 2 1 7 3 8 
After swap
7 3 8 1 4 2
 */
 struct Node{
     int data;
     int level;
     Node * left;
     Node * right;
 };
 Node * createNode(int data)
 {
     Node * newNode = new Node();
     newNode->data = data;
     newNode->left = nullptr;
     newNode->right = nullptr;
     return newNode;
 }
void swap(vector<int> &indexes)
{
    int temp = indexes[0];
    indexes[0] = indexes[1];
    indexes[1] = temp;
}
void swapKNode(Node * curr, int k)
{
    //base case
    if (curr== nullptr || (curr->left==nullptr && curr->right==nullptr) )
        return ;
    if(curr->level == k)
        swap(curr->left, curr->right);
    // Recur for left and right subtrees
    swapKNode(curr->left, k);
    swapKNode(curr->right, k);
 }
void InOrder(Node * root)
{
    if(root->left)
        InOrder(root->left);
    cout << root->data<<" ";
    if(root->right)
        InOrder(root->right);
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int rows = indexes.size();
    int j=0;
    //convert user input into a newly created binary tree
    vector<vector<int>> result;//[queries.size()];
    queue<Node *> q;
    Node * root = createNode(1);
    root->level = 1;
    q.push(root);
    
    for(int i=0; i < rows; i++)
    {
        Node * curr = q.front();
        q.pop();
        if(curr != nullptr)
        {
            //check if any left side nodes to add
            if(indexes[i][0] != -1){
                curr->left = createNode(indexes[i][0]);
                curr->left->level = curr->level+1;
            } else {
                curr->left = nullptr;
            }
            //check if right should be added
            if(indexes[i][1] != -1){
                curr->right = createNode(indexes[i][1]);
                curr->right->level = curr->level+1;
            } else {
                    curr->right = nullptr;
                }
        q.push(curr->left);
        q.push(curr->right);
        }
        else {//there are be more lines to process 
        i--;
        }
    }
    //print existing order
    InOrder(root);
    cout <<endl<< "After swap"<<endl;
    for(int i=0; i < queries.size();i++)
    {
        Node * curr = root;
        swapKNode(root, queries[i]);
    }
    InOrder(root);
    return result;//TODO: fill result with in-order traversal at each swap
}
/*
Input: 5
2 3
-1 4
-1 5
-1 -1
-1 -1
1
2
2 4 1 3 5
After swap : 3 5 1 2 4

3
2 3
-1 -1
-1 -1
2
1
1
Output 3 1 2 
        2 1 3

11
2 3
4 -1
5 -1
6 -1
7 8
-1 9
-1 -1
10 11
-1 -1
-1 -1
-1 -1
2
2
4
Output: 
2 9 6 4 1 3 7 5 11 8 10
2 6 9 4 1 3 7 5 10 8 11
         1                     1                          1             
        / \                   / \                        / \            
       /   \                 /   \                      /   \           
      2     3    [s]        2     3                    2     3          
     /      /                \     \                    \     \         
    /      /                  \     \                    \     \        
   4      5          ->        4     5          ->        4     5       
  /      / \                  /     / \                  /     / \      
 /      /   \                /     /   \                /     /   \     
6      7     8   [s]        6     7     8   [s]        6     7     8
 \          / \            /           / \              \         / \   
  \        /   \          /           /   \              \       /   \  
   9      10   11        9           11   10              9     10   11 
*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
