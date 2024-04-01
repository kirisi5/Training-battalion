#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��������
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

// �鲢����
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int)); // ʹ�ö�̬�ڴ����
    int* R = (int*)malloc(n2 * sizeof(int)); // ʹ�ö�̬�ڴ����

    // ����ڴ�����Ƿ�ɹ�
    if (L == NULL || R == NULL) {
        // �����ڴ����ʧ�ܵ����
        printf("�ڴ����ʧ��\n");
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

    // �ͷŶ�̬������ڴ�
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

// ��������
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

// ��������
void countingSort(int arr[], int n, int range) {
    int* output = (int*)malloc(n * sizeof(int)); // ʹ�ö�̬�ڴ����Ϊ�����������ڴ�
    int* count = (int*)malloc((range + 1) * sizeof(int)); // ʹ�ö�̬�ڴ����Ϊ������������ڴ�
    int i;

    if (output == NULL || count == NULL) {
        // �����ڴ����ʧ�ܵ����
        printf("�ڴ����ʧ��\n");
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

    // �ͷŶ�̬������ڴ�
    free(output);
    free(count);
}


// ��������
void countingSortForRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int)); // ʹ�ö�̬�ڴ����
    int i, * count = (int*)calloc(10, sizeof(int)); // ʹ�ö�̬�ڴ���䲢��ʼ��Ϊ0

    // ����ڴ�����Ƿ�ɹ�
    if (output == NULL || count == NULL) {
        // �����ڴ����ʧ�ܵ����
        printf("�ڴ����ʧ��\n");
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

    // �ͷŶ�̬������ڴ�
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

