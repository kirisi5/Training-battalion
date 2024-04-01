#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void generateRandomArray2(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // 生成0到999之间的随机数
    }
}

int test2() {
    const int dataSize = 100;
    const int numTests = 100000;
    int* data = (int*)malloc(dataSize * sizeof(int)); // 使用动态内存分配为数组分配内存
    clock_t start, end;
    double cpu_time_used;

    // 初始化随机数种子
    srand(time(NULL));

    // 测试插入排序
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        insertionSort(data, dataSize);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("插入排序 %d 个数据 %d 次所用的时间为 %f 秒\n", dataSize, numTests, cpu_time_used);

    // 测试归并排序
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        mergeSort(data, 0, dataSize - 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("归并排序 %d 个数据 %d 次所用的时间为 %f 秒\n", dataSize, numTests, cpu_time_used);

    // 测试快速排序
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        quickSort(data, 0, dataSize - 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序 %d 个数据 %d 次所用的时间为 %f 秒\n", dataSize, numTests, cpu_time_used);

    // 测试计数排序
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        countingSort(data, dataSize, 1000); // 这里假设范围为0到999，可以根据实际情况调整
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("计数排序 %d 个数据 %d 次所用的时间为 %f 秒\n", dataSize, numTests, cpu_time_used);

    // 测试基数排序
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        radixSort(data, dataSize);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("基数排序 %d 个数据 %d 次所用的时间为 %f 秒\n", dataSize, numTests, cpu_time_used);

    return 0;
}