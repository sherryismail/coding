#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
/*
Given a binary tree, print it vertically. The following example illustrates the vertical order traversal.
           1
        /    \ 
       2      3
      / \   /   \
     4   5  6   7
               /  \ 
              8   9          
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9

But sometimes vertical order traversal will wrongly print 12 before 9 in this
            1
          /    \ 
         2       3
        /      /  \
       4    5  6    7
                  /  \
                 8 10  9 
                     \
                     11
                       \
                        12
Use Level order traversal to make sure that nodes of a vertical line are printed in the same order as they appear in the tree
          1
         / \
        2   3
         \
          4
           \
            5
             \
              6
    Top view of the above binary tree is
    2 1 3 6
*/
struct Node
{
    int key;
    int hd;
    struct Node * left;
    struct Node * right;
};
Node * newNode(int data)
{
    Node * newNode = new Node;
    newNode->key = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
class bruteforce{//Time complexity O(m*n) = O(n^2) if the depths are equal to nodes
public:
    //recursive func to find max and min distance
void findMinMax(Node * root, int *min, int * max, int base)
{
    if(!root)//base case
        return;
    if(base < *min)
        *min = base;
    else if (base > *max)
        *max = base;
    if(root->left)//recursive case
        findMinMax(root->left, min, max, base -1);
    if(root->right)
        findMinMax(root->right, min, max, base + 1);

}
//recursive func to print all nodes on a given distance
// counter is horizontal distance of current node with respect to root
void printNode(Node * root, int distance, int counter)
{
    if(root == nullptr)
    return ;
    if(distance ==counter){
        cout << distance << " : "<<root->key << " "<<endl;
        return ;
    }
    printNode(root->left, distance, counter-1);
    printNode(root->right, distance, counter+1);
}
void verticalOrder(Node * root)
{
    //find max and min distance from root = 0. to find the span.
    int min =0, max = 0, base = 0;
    findMinMax(root,&min,&max, base);
    cout << "max and min are "<< max <<" " << min<<endl;
    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for(int i=min; i <= max; i++)
    {//third argument is for comparison with depth and iteration through the tree. 
    //otherwise the Node.counter could store its depth
        printNode(root,i,0);
    }
}
};
class hashmap
{
    //time complexity : O(n)
    //insertion and retrieval is O(1)
public:
    // Create a map and store vertical order in map using
    map<int, vector<int>> mp;//key is horizontal distance, vector stores all nodes at that distance
    //distance as passed as 0 starting from root node
    void getVerticalOrder(Node * root, int distance)
    {
        if(!root)
            return;
        mp[distance].push_back(root->key);
        getVerticalOrder(root->left, distance -1);
        getVerticalOrder(root->right, distance +1);
    }
    void verticalOrder(Node * root)
    {
        //populate the map
        getVerticalOrder(root,0);
        //now map is populated with index=distance from root
        // value filled with all nodes that are at this distance
        map<int, vector<int>>::iterator it;
        for (it = mp.begin(); it!= mp.end(); it++)
            {
                cout << it->first <<":";
                for(int i=0; i < it->second.size(); i++)
                    cout << it->second[i]<< " ";
                cout << endl;
            }
    }
    void verticalSum(Node * root)
    {
        map<int, vector<int>>::iterator it;
        int sum=0;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            sum=0;
            for(int j=0; j < it->second.size(); j++)
            {
                sum += it->second[j];
            }
            cout << it->first <<":" << sum<<endl;
        }
    }
};
class queue_bfs
{//Time complexity: O(n), map had time complexity of BST -> O(n*logn)
//space complexity: O(n)
public:
    unordered_map<int, vector<int>> mp;
    void verticalOrder(Node *root)
    {
         // Base case
        if (!root) return;
        int min = 0, max = 0;
        int distance = 0;
        queue<pair<int, Node *>> q;
        q.push({distance,root});
        while (q.size()>0)//tricky. Do not use (!q.size()), why??
        {
            pair<int, Node *> curr = q.front();
            q.pop();
            
            distance = curr.first;
            Node *node = curr.second;
            if (curr.second == nullptr)
                continue; // see other queue elements in the while loop
            // add this node to the database
            mp[distance].push_back(node->key);
            // check its neighbours
            if (node->left)
                q.push({distance - 1, node->left});
            if (node->right)
                q.push({distance + 1, node->right});
            if(q.size() == 0) cout << "Empty queue";
            // check that you are spreading out of root
            if (min > distance)
                min = distance;
            else if (max < distance)
                max = distance;
        }
        for (int i = min; i <= max; i++)
        {
            cout << i << " : ";
            // at each map entry, print all the nodes stored in vector<int>
            for (int j = 0; j < mp[i].size(); j++)
            {
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
    } // end of func
    void topView(Node * root)
    {
        map<int,int> mp;//key = distance, value = First node that appears in top search
        //it can also be map<int,int>
        queue<pair<int, Node *>> q;
        int distance = 0;
        q.push({0,root});
        while(q.size()>0)
        {
            pair<int, Node *> curr = q.front();
            q.pop();
            distance = curr.first;
            Node * node = curr.second;
            if(!node)
                break;
            //only add to map if it occured first time in breadth first search
            if(mp.count(distance) == 0)
                mp[distance] = node->key;
            if(node->left)
                q.push({distance -1,node->left});
            if(node->right)
                q.push({distance+1,node->right});
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
        cout << i -> second << " ";
        }
    }
};

int main()
{
    // //test case
    // Node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
    // root->right->left->right = newNode(8);
    // root->right->right->right = newNode(9);

    //test case for top level view
Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(10);
	root->right->right->left->right = newNode(11);
	root->right->right->left->right->right = newNode(12);  

    //test case
    // Node * root = newNode(1);
    // root->left = newNode(2);
	// root->right = newNode(3);
	// root->left->right = newNode(4);
	// root->left->right->right = newNode(5);
    // root->left->right->right->right = newNode(6);

    cout << "Vertical order traversal brute force is \n";
    bruteforce sol;
    sol.verticalOrder(root);
    hashmap hm;
    cout << "\nVertical order traversal method by simple mapping \n";
    hm.verticalOrder(root);
    queue_bfs qb;
    cout << "\nLevel order traversal method queue+BFS \n";
    qb.verticalOrder(root);

    cout << "The sum of all nodes at each height are\n";
    hm.verticalSum(root);

    cout <<"Top view of the Binary Search tree is:\n";
    qb.topView(root);
    return 0;
}