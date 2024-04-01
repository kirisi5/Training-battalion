#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void generateRandomArray2(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // ����0��999֮��������
    }
}

int test2() {
    const int dataSize = 100;
    const int numTests = 100000;
    int* data = (int*)malloc(dataSize * sizeof(int)); // ʹ�ö�̬�ڴ����Ϊ��������ڴ�
    clock_t start, end;
    double cpu_time_used;

    // ��ʼ�����������
    srand(time(NULL));

    // ���Բ�������
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        insertionSort(data, dataSize);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�������� %d ������ %d �����õ�ʱ��Ϊ %f ��\n", dataSize, numTests, cpu_time_used);

    // ���Թ鲢����
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        mergeSort(data, 0, dataSize - 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�鲢���� %d ������ %d �����õ�ʱ��Ϊ %f ��\n", dataSize, numTests, cpu_time_used);

    // ���Կ�������
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        quickSort(data, 0, dataSize - 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�������� %d ������ %d �����õ�ʱ��Ϊ %f ��\n", dataSize, numTests, cpu_time_used);

    // ���Լ�������
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        countingSort(data, dataSize, 1000); // ������跶ΧΪ0��999�����Ը���ʵ���������
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�������� %d ������ %d �����õ�ʱ��Ϊ %f ��\n", dataSize, numTests, cpu_time_used);

    // ���Ի�������
    start = clock();
    for (int i = 0; i < numTests; i++) {
        generateRandomArray2(data, dataSize);
        radixSort(data, dataSize);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�������� %d ������ %d �����õ�ʱ��Ϊ %f ��\n", dataSize, numTests, cpu_time_used);

    return 0;
}