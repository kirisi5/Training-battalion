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
}StackNode, *LinkStackPtr;//定义数据类型，后者是指针型

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


//链栈
LinkStack* initLStack();//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
int getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
void clearLStack(LinkStack *s);//清空栈
void destroyLStack(LinkStack *s);//销毁栈
int LStackLength(LinkStack *s);//检测栈长度
void pushLStack(LinkStack *s,ElemType data);//入栈
void popLStack(LinkStack *s,ElemType *data);//出栈
void display(LinkStack* s);//输出从栈顶 至 栈底


#endif 
