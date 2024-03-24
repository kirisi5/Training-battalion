#include <stdio.h>
#include <stdlib.h>
#include "doubleLists.h"
#define _CRT_SECURE_NO_WARNINGS 1

// 创建双向链表
_Node* createDuList() {
    _Node* head = (_Node*)malloc(sizeof(_Node));
    if (!head) {
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    _Node* p = head;

    int data;
    while (1) {
        printf("请输入一个整数（输入0结束）：");
        scanf("%d", &data);
        if (data == 0) {
            break;
        }

        _Node* new_Node = (_Node*)malloc(sizeof(_Node));
        if (!new_Node) {
            // 释放已分配的内存
            while (p != head) {
                _Node* temp = p;
                p = p->prev;
                free(temp);
            }
            free(head);
            return NULL;
        }

        new_Node->data = data;
        new_Node->next = NULL;
        new_Node->prev = p;
        p->next = new_Node;
        p = new_Node;
    }

    return head;
}

// 在指定位置插入节点
void insertDuList(_Node* head, int position, int value) {
    if (position < 1) {
        // 位置无效，可以抛出异常或返回错误代码
        return;
    }
    _Node* new_Node = (_Node*)malloc(sizeof(_Node));
    if (!new_Node) {
        // 内存分配失败，可以抛出异常或返回错误代码
        return;
    }
    new_Node->data = value;
    new_Node->next = NULL;
    new_Node->prev = NULL;

    if (position == 1) { // 如果插入位置为1，进行头插
        new_Node->next = head->next;
        head->next->prev = new_Node;
        head->next = new_Node;
        new_Node->prev = head;
        return;
    }

    _Node* p = head;
    for (int i = 1; i < position && p->next != NULL; i++) {
        p = p->next;
    }
    if (p->next == NULL) {
        // 位置超出链表长度，可以抛出异常或返回错误代码
        return;
    }
    new_Node->next = p->next;
    new_Node->prev = p;
    p->next->prev = new_Node;
    p->next = new_Node;
}

// 删除指定位置的节点
void deleteNodeAtPosition(_Node* head, int position) {
    if (position < 1) {
        // 位置无效，可以抛出异常或返回错误代码
        return;
    }

    _Node* p = head;
    if (position == 1) { // 如果删除位置为1，进行头删
        if (p->next == NULL) {
            // 链表为空或只有一个节点，无法删除
            return;
        }
        _Node* temp = p->next;
        p->next = temp->next;
        if (temp->next) {
            temp->next->prev = p;
        }
        free(temp);
        return;
    }

    for (int i = 1; i < position && p->next != NULL; i++) {
        p = p->next;
    }
    if (p->next == NULL) {
        // 位置超出链表长度，可以抛出异常或返回错误代码
        return;
    }

    _Node* temp = p->next;
    p->next = temp->next;
    if (temp->next) {
        temp->next->prev = p;
    }
    free(temp);
}

// 打印双向链表
void printDuList(_Node* head) {
    _Node* p = head->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放双向链表内存
void freeDuList(_Node* head) {
    _Node* p = head->next;
    while (p) {
        _Node* temp = p;
        p = p->next;
        free(temp);
    }
    free(head);
}

int doubleLists() {
    int a, b, c, choice;
    _Node* head = createDuList();
    // 创建链表
   
    do {
        printf("双链表ADT\n");
        printf("1. 打印链表\n");
        printf("2. 插入节点\n");
        printf("3. 删除节点\n");
        printf("4. 释放链表内存\n");
        printf("5. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // 打印链表
            printDuList(head);
            break;
        case 2:
            //插入结点
            printf("请输入想要插入的位置和值：");
            scanf("%d,%d", &a, &b);
            insertDuList(head,a,b);
            break;
        case 3:
            // 删除节点
            printf("请输入想要删除的值：");
            scanf("%d", &c);
            deleteNodeAtPosition(head,c);
            break;
        case 4:
            // 释放链表内存
            freeDuList(head);
            break;
        case 5:
            printf("感谢使用，再见！\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    } while (choice != 5);
    return 0;
}