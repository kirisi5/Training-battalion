#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 插入排序
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 归并排序
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int)); // 使用动态内存分配
    int* R = (int*)malloc(n2 * sizeof(int)); // 使用动态内存分配

    // 检查内存分配是否成功
    if (L == NULL || R == NULL) {
        // 处理内存分配失败的情况
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 释放动态分配的内存
    free(L);
    free(R);
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// 快速排序
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 计数排序
void countingSort(int arr[], int n, int range) {
    int* output = (int*)malloc(n * sizeof(int)); // 使用动态内存分配为输出数组分配内存
    int* count = (int*)malloc((range + 1) * sizeof(int)); // 使用动态内存分配为计数数组分配内存
    int i;

    if (output == NULL || count == NULL) {
        // 处理内存分配失败的情况
        printf("内存分配失败\n");
        return;
    }

    for (i = 0; i <= range; ++i)
        count[i] = 0;

    for (i = 0; i < n; ++i)
        ++count[arr[i]];

    for (i = 1; i <= range; ++i)
        count[i] += count[i - 1];

    for (i = 0; i < n; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; i < n; ++i)
        arr[i] = output[i];

    // 释放动态分配的内存
    free(output);
    free(count);
}


// 基数排序
void countingSortForRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int)); // 使用动态内存分配
    int i, * count = (int*)calloc(10, sizeof(int)); // 使用动态内存分配并初始化为0

    // 检查内存分配是否成功
    if (output == NULL || count == NULL) {
        // 处理内存分配失败的情况
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

    // 释放动态分配的内存
    free(output);
    free(count);
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

