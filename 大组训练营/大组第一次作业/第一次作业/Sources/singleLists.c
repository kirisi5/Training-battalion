#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"
#define _CRT_SECURE_NO_WARNINGS 1


//��������ͷ��������
Node* createNode() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (!head) {
        return NULL;
    }//�ж�head�Ƿ�ΪNULL
    head->next = NULL;
    Node* p1 = head;
    while (1) {
        Node* p2 = (Node*)malloc(sizeof(Node));
        if (!p2) {
            // �ͷ��ѷ�����ڴ�
            while (head != p1) {
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            free(head);
            return NULL;
        }
        printf("������һ������������0��������");
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

//ʵ��ָ��λ�õĲ���
void insertNode(Node* head, int position, int value) {
    if (position < 1) {
        // λ����Ч�������׳��쳣�򷵻ش������
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        // �ڴ����ʧ�ܣ������׳��쳣�򷵻ش������
        return;
    }
    newNode->data = value;
    newNode->next = NULL; // ��ʼ���½ڵ��nextָ��ΪNULL

    if (position == 1) { // �������λ��Ϊ1������ͷ��
        newNode->next = head->next; // ���½ڵ�����Ϊͷ�ڵ�
        head->next = newNode; // ����ͷ�ڵ��nextָ��
        head = newNode; // ��ͷ�ڵ����Ϊ�½ڵ�
        return;
    }

    // �������λ�ò���1������β��
    Node* p = head;
    for (int i = 1; i < position && p->next != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        // λ�ó��������ȣ������׳��쳣�򷵻ش������
        return;
    }
    newNode->next = p->next; // ���½ڵ��nextָ��ָ��ǰ�ڵ��nextָ��
    p->next = newNode; // ���µ�ǰ�ڵ��nextָ��Ϊ�½ڵ�
}


// ɾ������ָ���Ľ��
Node* removeNodde(Node* L, int value) {
    Node* p, * q;
    p = L;
    q = L->next;
    while (q != NULL && q->data != value) {
        p = q;
        q = q->next;
    }//Ѱ��ɾ�����
    if (q != NULL){
        p->next = q->next;
    }
    else {
        printf("The node is not found!\n");
    }
    free(q);
    return L;
}

// ��ӡ����
void printList(Node* head) {
    Node* current = head->next; // ��ͷ������һ���ڵ㿪ʼ����
    printf("head -> ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        if (current == NULL) {
            break; // �������һ���ڵ㣬����ѭ��
        }
    }
    printf("NULL\n");
}

// �ͷ������ڴ�
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
        printf("������ADT\n");
        printf("1. ��ӡ����\n");
        printf("2. ����ڵ�\n");
        printf("3. ɾ���ڵ�\n");
        printf("4. �ͷ������ڴ�\n");
        printf("5. ��ż����\n");
        printf("6. ���е�\n");
        printf("7. �Ƿ�ɻ�\n");
        printf("8. ��ת\n");
        printf("9. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // ��ӡ����
                printList(head);
                break;
            case 2:
                //������
                printf("��������Ҫ�����λ�ú�ֵ��");
                scanf("%d,%d", &a, &b);
                insertNode(head,a,b);
                break;
            case 3:
                // ɾ���ڵ�
                printf("��������Ҫɾ����ֵ��");
                scanf("%d", &c);
                removeNodde(head,c);
                break;
            case 4:
                // �ͷ������ڴ�
                freeList(head);
                break;
            case 5:
                //��ż����
                SchangeParity(head);
                break;
            case 6:
                //���е�
                findCentre(head);
                break;
            case 7:
                //�Ƿ�ɻ�
                ifRing(head);
                break;
            case 8:
                //��ת
                rollBack(head);
                break;
            case 9:
                printf("��лʹ�ã��ټ���\n");
                break;
            default:
                printf("��Ч��ѡ�����������롣\n");
        }
    } while (choice != 9);
    return 0;
}

