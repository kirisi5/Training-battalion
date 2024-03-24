#include <stdio.h>
#include <stdlib.h>
#include "doubleLists.h"
#define _CRT_SECURE_NO_WARNINGS 1

// ����˫������
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
        printf("������һ������������0��������");
        scanf("%d", &data);
        if (data == 0) {
            break;
        }

        _Node* new_Node = (_Node*)malloc(sizeof(_Node));
        if (!new_Node) {
            // �ͷ��ѷ�����ڴ�
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

// ��ָ��λ�ò���ڵ�
void insertDuList(_Node* head, int position, int value) {
    if (position < 1) {
        // λ����Ч�������׳��쳣�򷵻ش������
        return;
    }
    _Node* new_Node = (_Node*)malloc(sizeof(_Node));
    if (!new_Node) {
        // �ڴ����ʧ�ܣ������׳��쳣�򷵻ش������
        return;
    }
    new_Node->data = value;
    new_Node->next = NULL;
    new_Node->prev = NULL;

    if (position == 1) { // �������λ��Ϊ1������ͷ��
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
        // λ�ó��������ȣ������׳��쳣�򷵻ش������
        return;
    }
    new_Node->next = p->next;
    new_Node->prev = p;
    p->next->prev = new_Node;
    p->next = new_Node;
}

// ɾ��ָ��λ�õĽڵ�
void deleteNodeAtPosition(_Node* head, int position) {
    if (position < 1) {
        // λ����Ч�������׳��쳣�򷵻ش������
        return;
    }

    _Node* p = head;
    if (position == 1) { // ���ɾ��λ��Ϊ1������ͷɾ
        if (p->next == NULL) {
            // ����Ϊ�ջ�ֻ��һ���ڵ㣬�޷�ɾ��
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
        // λ�ó��������ȣ������׳��쳣�򷵻ش������
        return;
    }

    _Node* temp = p->next;
    p->next = temp->next;
    if (temp->next) {
        temp->next->prev = p;
    }
    free(temp);
}

// ��ӡ˫������
void printDuList(_Node* head) {
    _Node* p = head->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// �ͷ�˫�������ڴ�
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
    // ��������
   
    do {
        printf("˫����ADT\n");
        printf("1. ��ӡ����\n");
        printf("2. ����ڵ�\n");
        printf("3. ɾ���ڵ�\n");
        printf("4. �ͷ������ڴ�\n");
        printf("5. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // ��ӡ����
            printDuList(head);
            break;
        case 2:
            //������
            printf("��������Ҫ�����λ�ú�ֵ��");
            scanf("%d,%d", &a, &b);
            insertDuList(head,a,b);
            break;
        case 3:
            // ɾ���ڵ�
            printf("��������Ҫɾ����ֵ��");
            scanf("%d", &c);
            deleteNodeAtPosition(head,c);
            break;
        case 4:
            // �ͷ������ڴ�
            freeDuList(head);
            break;
        case 5:
            printf("��лʹ�ã��ټ���\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    } while (choice != 5);
    return 0;
}