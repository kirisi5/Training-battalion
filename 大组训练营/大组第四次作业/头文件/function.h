#ifndef _FUNCTION_H
#define _FUNCTION_H

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* createNode(int value);
TreeNode* insert(TreeNode* root, int value);
TreeNode* search(TreeNode* root, int value);
TreeNode* deleteNode(TreeNode* root, int value);
void inorderTraversalRecursive(TreeNode* root);
void inorderTraversalIterative(TreeNode* root);
void levelOrderTraversal(TreeNode* root);

#endif 