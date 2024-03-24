#define _CRT_SECURE_NO_WARNINGS 1
#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>

//��ʼ��
void InitLQueue(LQueue* Q) {
	Node* p;
	p = (Node*)malloc(sizeof(Node));//Ϊָ��ڵ��ָ�����ռ�
	p->next = NULL;
	Q->front = Q->rear = p;
	Q->rear->next = NULL;
}

//���
Status EnLQueue(LQueue** Q, QElemType* data) {
	// ȷ�������ָ����Ч
	if (!Q || !(*Q) || !data) {
		return FALSE;
	}

	// �����½ڵ�
	Node* s = (Node*)malloc(sizeof(Node));
	if (!s) {
		return FALSE;
	}

	// �����½ڵ����ݺ�ָ����
	s->data = data;
	s->next = NULL;

	// �����½ڵ㵽����β��
	if ((*Q)->rear == NULL) {
		// ����Ϊ��ʱ���� front ָ��
		(*Q)->front = s;
	}
	else {
		// ���зǿ�ʱ���½ڵ���ڶ���β��
		(*Q)->rear->next = s;
	}
	// ���� rear ָ��Ϊ�½ڵ�
	(*Q)->rear = s;

	return TRUE;
}

//����
Status DeLQueue(LQueue** Q) {
	if (!Q || !(*Q) || IsEmptyLQueue(*Q) != 1) {
		return FALSE;
	}

	Node* p = (*Q)->front->next;
	(*Q)->front->next = p->next;
	if ((*Q)->rear == p) {
		(*Q)->rear = (*Q)->front;
	}
	free(p);

	return TRUE;
}


//�ж��Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear)
	{
		return 0;
	}
	return 1;
}

//���г���
int LengthLQueue(LQueue* Q) {//����һ���ڵ����͵�ָ��
	Node* p;
	//��pָ����е�ͷָ��
	p = Q->front;
	//����һ������������¼���е�ǰ����
	int length = 0;
	while (p)//��ָ��p��ָ�Ľڵ㲻Ϊ��ʱִ��ѭ����
	{
		length++;
		p = p->next;
	}
	return length;//���ص�ǰ���еĳ���
}

//�鿴ͷԪ��
Status GetHeadLQueue(LQueue** Q, QElemType* e) {
	//�����ж϶����Ƿ�Ϊ��
	if (IsEmptyLQueue(*Q) == 0) {
		return 0;
	}
	*e = *((*Q)->front->data); // ��ͷ�ڵ�����ݸ�ֵ�� e
	return 1;
}

//��ն���
void ClearLQueue(LQueue* Q) {
	Node* p, *q;
	p = Q->front;
	Q->front = Q->rear = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
}

//���ٶ���
void DestoryLQueue(LQueue** Q) {
	Node* p, * q;
	p = (*Q)->front;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	(*Q)->front = (*Q)->rear = NULL;
	free(*Q);
	*Q = NULL;
}

//����
/*Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	Node* p = Q->front;

	while (p != NULL) {
		foo(p->data);
		p = p->next;
	}
	q
	return 1;
}*/

//���
void LPrint(LQueue* q) {

	Node* p = q->front;
	printf("Front:>");
	//��������ÿ����Ч����е����ݴ�ӡ
	while (p != NULL)
	{
		printf("%d ", *(p->data));
		p = p->next;
	}
	printf("<:Tail.\n");
}
