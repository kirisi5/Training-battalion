#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"
#define _CRT_SECURE_NO_WARNINGS 1


//创建含有头结点的链表
Node* createNode() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (!head) {
        return NULL;
    }//判断head是否为NULL
    head->next = NULL;
    Node* p1 = head;
    while (1) {
        Node* p2 = (Node*)malloc(sizeof(Node));
        if (!p2) {
            // 释放已分配的内存
            while (head != p1) {
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            free(head);
            return NULL;
        }
        printf("请输入一个整数（输入0结束）：");
        scanf("%d", &p2->data);
        if (p2->data == 0) {
            break;
        }
        p2->next = NULL;
        p1->next = p2;
        p1 = p2;
    }
    return head;
}

//实现指定位置的插入
void insertNode(Node* head, int position, int value) {
    if (position < 1) {
        // 位置无效，可以抛出异常或返回错误代码
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        // 内存分配失败，可以抛出异常或返回错误代码
        return;
    }
    newNode->data = value;
    newNode->next = NULL; // 初始化新节点的next指针为NULL

    if (position == 1) { // 如果插入位置为1，进行头插
        newNode->next = head->next; // 将新节点设置为头节点
        head->next = newNode; // 更新头节点的next指针
        head = newNode; // 将头节点更新为新节点
        return;
    }

    // 如果插入位置不是1，进行尾插
    Node* p = head;
    for (int i = 1; i < position && p->next != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        // 位置超出链表长度，可以抛出异常或返回错误代码
        return;
    }
    newNode->next = p->next; // 将新节点的next指针指向当前节点的next指针
    p->next = newNode; // 更新当前节点的next指针为新节点
}


// 删除链表指定的结点
Node* removeNodde(Node* L, int value) {
    Node* p, * q;
    p = L;
    q = L->next;
    while (q != NULL && q->data != value) {
        p = q;
        q = q->next;
    }//寻找删除结点
    if (q != NULL){
        p->next = q->next;
    }
    else {
        printf("The node is not found!\n");
    }
    free(q);
    return L;
}

// 打印链表
void printList(Node* head) {
    Node* current = head->next; // 从头结点的下一个节点开始遍历
    printf("head -> ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        if (current == NULL) {
            break; // 到达最后一个节点，跳出循环
        }
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int singleLists() {
    int a, b, c,choice;
    Node* head = createNode();
    do {
        printf("单链表ADT\n");
        printf("1. 打印链表\n");
        printf("2. 插入节点\n");
        printf("3. 删除节点\n");
        printf("4. 释放链表内存\n");
        printf("5. 奇偶调换\n");
        printf("6. 找中点\n");
        printf("7. 是否成环\n");
        printf("8. 反转\n");
        printf("9. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // 打印链表
                printList(head);
                break;
            case 2:
                //插入结点
                printf("请输入想要插入的位置和值：");
                scanf("%d,%d", &a, &b);
                insertNode(head,a,b);
                break;
            case 3:
                // 删除节点
                printf("请输入想要删除的值：");
                scanf("%d", &c);
                removeNodde(head,c);
                break;
            case 4:
                // 释放链表内存
                freeList(head);
                break;
            case 5:
                //奇偶调换
                SchangeParity(head);
                break;
            case 6:
                //找中点
                findCentre(head);
                break;
            case 7:
                //是否成环
                ifRing(head);
                break;
            case 8:
                //反转
                rollBack(head);
                break;
            case 9:
                printf("感谢使用，再见！\n");
                break;
            default:
                printf("无效的选择，请重新输入。\n");
        }
    } while (choice != 9);
    return 0;
}

