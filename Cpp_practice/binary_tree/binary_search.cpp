//
//  main.cpp
//  Huffman
//
//  Created by Vatsal Chanana

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int freq;
    char data;
    node *left;
    node *right;
} node;

struct deref : public binary_function<node *, node *, bool>
{
    bool operator()(const node *a, const node *b) const
    {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *, vector<node *>, deref> spq;

node *huffman_hidden(string s)
{

    spq pq;
    vector<int> count(256, 0);

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {

        node *n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];

        if (count[i] != 0)
            pq.push(n_node);
    }

    while (pq.size() != 1)
    {

        node *left = pq.top();
        pq.pop();
        node *right = pq.top();
        pq.pop();
        node *comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);
    }

    return pq.top();
}

void print_codes_hidden(node *root, string code, map<char, string> &mp)
{

    if (root == NULL)
        return;

    if (root->data != '\0')
    {
        mp[root->data] = code;
    }

    print_codes_hidden(root->left, code + '0', mp);
    print_codes_hidden(root->right, code + '1', mp);
}

/*
Huffman coding assigns variable length codewords to fixed ...
//https://www.hackerrank.com/challenges/tree-huffman-decoding/forum?h_l=interview&isFullScreen=true&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit
*/
//Recursive method copied from comments
void recursive_decode_huff(node* root,node* node, string s) {
    if(node->data) {
        cout << node->data;
        recursive_decode_huff(root, root, s);
    }
    else if(s.empty()) return;//IMPORTANT
    else if(s.at(0) == '0') recursive_decode_huff(root, node->left, s.substr(1));
    else recursive_decode_huff(root, node->right, s.substr(1));
}
void decode_huff(node * root, string s) {
    recursive_decode_huff(root,root,s);
}
/*I tried recursive method. But not useful
because the knowledge of root node is lost once you land a leaf
*/
void decode_huff1(node * root, string s) {
    int i=0;
    node * current = root;
    while(i < s.length())
    {
        if(s[i] == '1')
                current = current->right;
            else
                current = current->left;
    //Important to NOT check the leaf node first
    //otherwise this algo does not work. It would skip a value
        if(!current->left && !current->right){
             printf("%c", current->data);//leaf node has valid char
               current = root;//start back from root for searching
        }
        i++;
    }
}
//inorder traversal of binary tree
void print_tree(node * root)
{
    if(root == nullptr)
    return;
    if(root->left)
        print_tree(root->left);
    cout << root->freq << " ";
    if(root->right)
        print_tree(root->right);
}
int main()
{

    string s;
    std::cin >> s;
    node *tree = huffman_hidden(s);
    string code = "";
    map<char, string> mp;

    print_codes_hidden(tree, code, mp);
    string coded;

    for (int i = 0; i < s.length(); i++)
        coded += mp[s[i]];
    decode_huff1(tree, coded);
    
    cout << endl<< "The In-order traversal is ";
    node * root = new node;
    root->freq = 1;
    root->left =  new node;
    root->left->freq = 2;
    root->right = new node;
    root->right->freq = 3;
    root->left->left = new node;
    root->left->left->freq = 4;
    root->left->right = new node;
    root->left->right->freq = 5;
    root->right->left = new node;
    root->right->left->freq = 6;
    root->right->right = new node;
    root->right->right->freq = 7;
    print_tree(root);

    return 0;
}