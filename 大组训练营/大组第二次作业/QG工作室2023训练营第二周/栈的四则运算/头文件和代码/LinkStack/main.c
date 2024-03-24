#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Compute.h"
extern char buffer[256];
int main()
{
    char str[1024] = { 0 };//将数组每个元素赋值为'\0'
    printf("请输入四则运算表达式:\n");
    scanf("%s", str);
    int number = transform(str);
    if (number == -1)
    {
        printf("表达式转换错误:\n");
    }
    else if (number == 1)
    {
        printf("转化后的表达式: %s\n", buffer);
    }
    else
    {
        return 0;
    }
    //成功换成后缀表达式


    //下方计算后缀表达式
    int num = calculate(buffer);
    if (num == 999)
    {
        return 0;
    }
    printf("%d\n", num);
}