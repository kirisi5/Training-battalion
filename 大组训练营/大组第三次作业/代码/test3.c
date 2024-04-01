#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void generaterandomarray(int arr[], int n, const char* FILEname) {
    FILE* FILE = fopen(FILEname, "w");
    if (FILE == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", FILEname);
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 1000; // 生成0到999之间的随机数
        fprintf(FILE, "%d\n", num);
    }

    fclose(FILE);
}

int test3_1() {
    const int datasize = 100;
    const char* FILEname = "testdata.txt";

    int* arr = (int*)malloc(datasize * sizeof(int)); // 使用动态内存分配为数组分配内存
    generaterandomarray(arr, datasize, FILEname);

    printf("已生成测试数据并保存到文件 %s\n", FILEname);

    return 0;
}

void readarrayfromFILE(int arr[], int n, const char* FILEname) {
    FILE* FILE = fopen(FILEname, "r");
    if (FILE == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", FILEname);
        exit(1); 
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(FILE, "%d", &arr[i]) != 1) {
            fprintf(stderr, "读取文件时发生错误\n");
            exit(1);
        }
    }

    fclose(FILE);
}

void writearraytoFILE(int arr[], int n, const char* FILEname) {
    FILE* FILE = fopen(FILEname, "w");
    if (FILE == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", FILEname);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(FILE, "%d\n", arr[i]);
    }

    fclose(FILE);
}

int test3_2() {
    const int datasize = 100;
    const char* inputFILEname = "testdata.txt";
    const char* outputFILEname = "sorteddata.txt";
    int* data = (int*)malloc(datasize * sizeof(int)); // 使用动态内存分配为数组分配内存

    // 从文件中读取数据
    readarrayfromFILE(data, datasize, inputFILEname);

    // 调用排序算法进行排序
    insertionSort(data, datasize);

    // 将排序后的数据写入文件
    writearraytoFILE(data, datasize, outputFILEname);

    printf("已将排序后的数据保存到文件 %s\n", outputFILEname);

    free(data); // Free dynamically allocated memory

    return 0;
}