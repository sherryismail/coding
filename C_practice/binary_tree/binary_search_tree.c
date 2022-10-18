#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {    
    int data;
    struct node *left;
    struct node *right;
};
typedef enum {
    false,true,
} bool;

struct node* insert( struct node* root, int data ) {
	if(root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
	} else {
		struct node* cur;
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
/* Find Lowest Common Ancestor of two values
6
4 2 3 1 7 6
     4
    /\
   2   7
  / \  /
 1   3 6
v1=1, v2=7. Then LCA is 4*/
struct node *lca( struct node *root, int v1, int v2 ) {
    //search for v1.store ptr. for each level search, compare ptrs
    if(v1>root->data && v2>root->data)
        return lca(root->right,v1,v2);
    else if(v1<root->data && v2<root->data)
        return lca(root->left,v1,v2);
    else {
        /*Use this v1 and v2 are always unique
    LCA node will be some value in between
    if v1<data but v2>data 
    or v1>data but v2<data
    then this must be common node*/
        return root;
        }
}
int get_smallest_num(struct node * root)
{
    if(!root->left)
        return root->data;
    else
        return get_smallest_num(root->left);
}
bool check_BST(struct node * root, int min, int max){
    if(root == NULL)
        return true;//dont punish the leaf node
    if(root->data <= min || root->data >= max)
        return false;//if tree breaks the BST criteria
    else //go down one level. root->data is maxima for LHS. root->data is a minima for RHS
        return (check_BST(root->left, min, root->data) && check_BST(root->right,root->data, max));
}
/* Is This a Binary Search Tree?
 * Hint: helper function may be needed*/
bool checkBST(struct node* root) {
        return check_BST(root, 0, 10000);
	}
/* WHat is the maximum height of BST? */
int getHeight(struct node* root) {
    if (!root->left && !root->right)
        return 0;//leaf node
        // if(root->left)
        // getHeight(root->left);
    int left=0, right=0;
    if(root->left)
        right = getHeight(root->left);
    if(root->right)
        right = getHeight(root->right);
    return 1+ (left>right? left: right); 
}
bool isSameTree(struct node * p, struct node * q){
    int pval, qval; 
    if (p== NULL && q == NULL)
        return true;
    if(p== NULL || q == NULL)
        return false;
    if(p->data != q->data)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main() {
    struct node* root = NULL;
    int t;
    int data;
    printf("Enter the total number of entries:");
    scanf("%d", &t);
    printf("Enter the numbers in the sequence you want BST to work:");
    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
	printf("BST height is %d\n",getHeight(root));
    printf("Is this BST? %s\n", checkBST(root)? "true":"false");
    int v1=1, v2=5;
    printf("LCA of %d and %d is %d\n", v1,v2,lca(root,v1,v2)->data);
    printf("Smallest num is %d", get_smallest_num(root));
    return 0;
}
