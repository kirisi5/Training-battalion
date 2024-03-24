#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"


Node* rollBack1(Node* head) {

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        //new_head一直找到链表中的最后一个元素的地址 
        Node* new_head = rollBack1(head->next);
        //出递归后，将链表 
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
}

Node* rollBack2(Node* head) {
    Node* pre = NULL;
    Node* cur = head; 
    Node* next = head;
    while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

Node* rollBack(Node* head) {
    int choice;
    printf("1. 递归反转\n");
    printf("2. 迭代反转\n");
    printf("请选择操作：");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head->next = rollBack1(head->next);
            break;
        case 2:
            head -> next = rollBack2(head->next);
            break;       
        default:
            printf("无效的选择，请重新输入。\n");
    }
    
}