#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Compute.h"
extern char buffer[256];
int main()
{
    char str[1024] = { 0 };//������ÿ��Ԫ�ظ�ֵΪ'\0'
    printf("����������������ʽ:\n");
    scanf("%s", str);
    int number = transform(str);
    if (number == -1)
    {
        printf("���ʽת������:\n");
    }
    else if (number == 1)
    {
        printf("ת����ı��ʽ: %s\n", buffer);
    }
    else
    {
        return 0;
    }
    //�ɹ����ɺ�׺���ʽ


    //�·������׺���ʽ
    int num = calculate(buffer);
    if (num == 999)
    {
        return 0;
    }
    printf("%d\n", num);
}