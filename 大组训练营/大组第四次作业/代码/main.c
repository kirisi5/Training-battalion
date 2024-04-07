#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    TreeNode* root = NULL;
    int value;
    char choice;

    do {
        printf("请输入要插入到二叉搜索树中的值：");
        scanf("%d", &value);
        root = insert(root, value);
        printf("是否要插入另一个值？(y/n)：");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("中序遍历（递归）：");
    inorderTraversalRecursive(root);
    printf("\n");

    printf("中序遍历（迭代）：");
    inorderTraversalIterative(root);
    printf("\n");

    printf("层序遍历：");
    levelOrderTraversal(root);
    printf("\n");

    printf("请输入要在二叉搜索树中搜索的值：");
    scanf("%d", &value);
    TreeNode* found = search(root, value);
    if (found != NULL) {
        printf("找到了：%d\n", found->data);
    }
    else {
        printf("未找到\n");
    }

    printf("请输入要从二叉搜索树中删除的值：");
    scanf("%d", &value);
    root = deleteNode(root, value);
    printf("删除后的中序遍历：");
    inorderTraversalRecursive(root);
    printf("\n");

    return 0;
}