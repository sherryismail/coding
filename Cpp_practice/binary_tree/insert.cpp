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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }
    //iterative
    Node * insert_iterative(Node * root, int data) {
        Node * curr = root;
        Node * newNode = new Node (data);
        if(curr == nullptr){
            curr = newNode;
            return curr;
        }
       
        while(curr != nullptr)
        {
            //dont check if its null, check the directon to go first
            if(data < curr->data)
            {
                if(curr->left)
                    curr = curr->left;
                else{
                    curr->left = newNode;
                    break;
                }
            }else if(data >= curr->data){
                if(curr->right)
                    curr = curr->right;
                else {
                    curr->right = newNode;
                    break;
                }
            }
        }            
        return root;
    }
    //recursive
    Node * insert_recursive(Node * root, int data) {
        //base case: if you land on a node tht is empty
        if(!root)
            root = new Node(data);

        //ifyou land somewhere in between, compare
        if(data < root->data)
            root->left =  insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);
        return root;

    }

};

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
        root = myTree.insert_recursive(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
