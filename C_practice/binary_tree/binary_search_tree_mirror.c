
#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryTreeNode {
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
}BinaryTreeNode;
void mirror_tree(BinaryTreeNode* root) {
  if (root == NULL) {
    return;
  }
  // post-order traversal of the binary tree.
  if (root->left != NULL) {
    mirror_tree(root->left);
  }

  if (root->right != NULL) {
    mirror_tree(root->right);
  }

  // Let's swap the left and right nodes at current level.
  BinaryTreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
}

void main() {

  BinaryTreeNode* root = create_random_BST(15);
  display_level_order(root);
  mirror_tree(root);
  printf("\nMirrored tree =\n");
  display_level_order(root);
}