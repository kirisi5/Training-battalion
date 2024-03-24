#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"

// ��������������ַa��b�е�ֵ�ĺ���
void swap(int* a, int* b) {
    int temp; // ��ʱ�������ڴ洢һ��ֵ
    temp = *a; // ��a��ֵ����temp
    *a = *b; // ��b��ֵ����a
    *b = temp; // ��temp��ֵ����b��ʵ�ֽ���
}

// ��������������Ԫ�صĹ���
void SchangeParity(Node* head) {
    Node* temp = head->next; // ��ʱָ�����ڱ�������

    // ֻ���������������������ڵ�����
    while (temp != NULL && temp->next != NULL) {
        // ����temp�ڵ��temp����һ���ڵ������
        swap(&temp->data, &temp->next->data);

        // ��temp�ƶ�����һ���ڵ㣨������һ���ڵ㣩
        temp = temp->next->next;
    }
}