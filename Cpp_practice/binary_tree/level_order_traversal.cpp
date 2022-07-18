#include <bits/stdc++.h>	
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
 1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  
         level order : 1->2->5->3->6->4
*/
//breadth first search (BFS). Level order is NOT the same as In Order traversal
    void levelOrder(Node * root) {
        if(!root) return;
        queue<Node *> q;
        q.push(root);

        while(q.size() >0)
        {
            Node * curr = q.front();
            q.pop();
            //check this level first
            cout << curr->data << " ";
            //queue in next level elements for display next time
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);   
        }
    }
    void Inorder(Node * root)
    {
        if(!root) return;
        cout << root->data <<" ";
        if(root->left)
            Inorder(root->left);
       
        if(root->right)
            Inorder(root->right);
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;
    cout << "Enter total elements in a binary tree: ";
    std::cin >> t;
     cout << "Enter elements separated by space: ";
    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    cout << "Level order traversal: ";
	myTree.levelOrder(root);
    cout << endl<< "In order traversal: ";
    myTree.Inorder(root);
    return 0;
}
