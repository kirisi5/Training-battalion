#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void generateRandomArray1(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

// ���������㷨�ĺ���
void testSortingAlgorithms(int data_sizes[], int num_sizes) {
    for (int i = 0; i < num_sizes; i++) {
        int n = data_sizes[i];
        int* arr = malloc(n * sizeof(int));

        // �����������
        generateRandomArray1(arr, n);

        clock_t start, end;

        // ���Բ�������
        start = clock();
        insertionSort(arr, n);
        end = clock();
        printf("Insertion Sort time for %d elements: %f seconds\n", n, (double)(end - start) / CLOCKS_PER_SEC);

        // �����������
        generateRandomArray1(arr, n);

        // ���Թ鲢����
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        printf("Merge Sort time for %d elements: %f seconds\n", n, (double)(end - start) / CLOCKS_PER_SEC);

        // �����������
        generateRandomArray1(arr, n);

        // ���Կ�������
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        printf("Quick Sort time for %d elements: %f seconds\n", n, (double)(end - start) / CLOCKS_PER_SEC);

        // �����������
        generateRandomArray1(arr, n);

        // ���Ի�������
        start = clock();
        radixSort(arr, n);
        end = clock();
        printf("Radix Sort time for %d elements: %f seconds\n", n, (double)(end - start) / CLOCKS_PER_SEC);

        // �ͷ��ڴ�
        free(arr);

        printf("\n");
    }
}

int test1() {
    int data_sizes[] = { 10000, 50000, 200000 };
    int num_sizes = sizeof(data_sizes) / sizeof(data_sizes[0]);

    testSortingAlgorithms(data_sizes, num_sizes);

    return 0;
}