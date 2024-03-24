#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS 1

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;//�����������ͣ�������ָ����

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


//��ջ
LinkStack* initLStack();//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
int getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
void clearLStack(LinkStack *s);//���ջ
void destroyLStack(LinkStack *s);//����ջ
int LStackLength(LinkStack *s);//���ջ����
void pushLStack(LinkStack *s,ElemType data);//��ջ
void popLStack(LinkStack *s,ElemType *data);//��ջ
void display(LinkStack* s);//�����ջ�� �� ջ��


#endif 
