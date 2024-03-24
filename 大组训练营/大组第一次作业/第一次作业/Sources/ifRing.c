#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"

int ifRing(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("���ɻ�\n");
        return 0; // �������ֻ��һ���ڵ�������ǻ�
    }

    Node* fast = head; // ��ָ�룬ÿ���ƶ������ڵ�
    Node* slow = head; // ��ָ�룬ÿ���ƶ�һ���ڵ�

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next; // ��ָ��ÿ���ƶ������ڵ�
        slow = slow->next;       // ��ָ��ÿ���ƶ�һ���ڵ�

        if (fast == slow) {
            printf("�ɻ�\n");
            return 1; // ����ָ������������ɻ�
        }
    }
    printf("���ɻ�\n");
    return 0; // ��ָ�뵽������ĩβ��������
}