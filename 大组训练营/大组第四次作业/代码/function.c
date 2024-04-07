#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新结点
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入结点
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// 查找结点
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

// 删除结点
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 中序遍历（递归）
void inorderTraversalRecursive(TreeNode* root) {
    if (root != NULL) {
        inorderTraversalRecursive(root->left);
        printf("%d ", root->data);
        inorderTraversalRecursive(root->right);
    }
}

// 中序遍历（非递归）
void inorderTraversalIterative(TreeNode* root) {
    TreeNode* stack[100];
    int top = -1;
    while (1) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        if (top == -1) {
            break;
        }
        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

// 层序遍历
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        TreeNode* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

