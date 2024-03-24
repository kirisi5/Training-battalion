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
        //new_headһֱ�ҵ������е����һ��Ԫ�صĵ�ַ 
        Node* new_head = rollBack1(head->next);
        //���ݹ�󣬽����� 
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
    printf("1. �ݹ鷴ת\n");
    printf("2. ������ת\n");
    printf("��ѡ�������");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head->next = rollBack1(head->next);
            break;
        case 2:
            head -> next = rollBack2(head->next);
            break;       
        default:
            printf("��Ч��ѡ�����������롣\n");
    }
    
}