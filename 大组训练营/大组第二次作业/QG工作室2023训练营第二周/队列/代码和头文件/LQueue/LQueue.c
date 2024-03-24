#define _CRT_SECURE_NO_WARNINGS 1
#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>

//初始化
void InitLQueue(LQueue* Q) {
	Node* p;
	p = (Node*)malloc(sizeof(Node));//为指向节点的指针分配空间
	p->next = NULL;
	Q->front = Q->rear = p;
	Q->rear->next = NULL;
}

//入队
Status EnLQueue(LQueue** Q, QElemType* data) {
	// 确保传入的指针有效
	if (!Q || !(*Q) || !data) {
		return FALSE;
	}

	// 创建新节点
	Node* s = (Node*)malloc(sizeof(Node));
	if (!s) {
		return FALSE;
	}

	// 设置新节点数据和指针域
	s->data = data;
	s->next = NULL;

	// 插入新节点到队列尾部
	if ((*Q)->rear == NULL) {
		// 队列为空时更新 front 指针
		(*Q)->front = s;
	}
	else {
		// 队列非空时将新节点接在队列尾部
		(*Q)->rear->next = s;
	}
	// 更新 rear 指针为新节点
	(*Q)->rear = s;

	return TRUE;
}

//出队
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


//判断是否为空
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear)
	{
		return 0;
	}
	return 1;
}

//队列长度
int LengthLQueue(LQueue* Q) {//声明一个节点类型的指针
	Node* p;
	//让p指向队列的头指针
	p = Q->front;
	//声明一个变量用来记录队列当前长度
	int length = 0;
	while (p)//当指针p所指的节点不为空时执行循环体
	{
		length++;
		p = p->next;
	}
	return length;//返回当前队列的长度
}

//查看头元素
Status GetHeadLQueue(LQueue** Q, QElemType* e) {
	//首先判断队列是否为空
	if (IsEmptyLQueue(*Q) == 0) {
		return 0;
	}
	*e = *((*Q)->front->data); // 将头节点的数据赋值给 e
	return 1;
}

//清空队列
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

//销毁队列
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

//遍历
/*Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	Node* p = Q->front;

	while (p != NULL) {
		foo(p->data);
		p = p->next;
	}
	q
	return 1;
}*/

//输出
void LPrint(LQueue* q) {

	Node* p = q->front;
	printf("Front:>");
	//将队列中每个有效结点中的数据打印
	while (p != NULL)
	{
		printf("%d ", *(p->data));
		p = p->next;
	}
	printf("<:Tail.\n");
}
