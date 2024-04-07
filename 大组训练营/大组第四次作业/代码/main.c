#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    TreeNode* root = NULL;
    int value;
    char choice;

    do {
        printf("������Ҫ���뵽�����������е�ֵ��");
        scanf("%d", &value);
        root = insert(root, value);
        printf("�Ƿ�Ҫ������һ��ֵ��(y/n)��");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("����������ݹ飩��");
    inorderTraversalRecursive(root);
    printf("\n");

    printf("�����������������");
    inorderTraversalIterative(root);
    printf("\n");

    printf("���������");
    levelOrderTraversal(root);
    printf("\n");

    printf("������Ҫ�ڶ�����������������ֵ��");
    scanf("%d", &value);
    TreeNode* found = search(root, value);
    if (found != NULL) {
        printf("�ҵ��ˣ�%d\n", found->data);
    }
    else {
        printf("δ�ҵ�\n");
    }

    printf("������Ҫ�Ӷ�����������ɾ����ֵ��");
    scanf("%d", &value);
    root = deleteNode(root, value);
    printf("ɾ��������������");
    inorderTraversalRecursive(root);
    printf("\n");

    return 0;
}