#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void generaterandomarray(int arr[], int n, const char* FILEname) {
    FILE* FILE = fopen(FILEname, "w");
    if (FILE == NULL) {
        fprintf(stderr, "�޷����ļ� %s\n", FILEname);
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 1000; // ����0��999֮��������
        fprintf(FILE, "%d\n", num);
    }

    fclose(FILE);
}

int test3_1() {
    const int datasize = 100;
    const char* FILEname = "testdata.txt";

    int* arr = (int*)malloc(datasize * sizeof(int)); // ʹ�ö�̬�ڴ����Ϊ��������ڴ�
    generaterandomarray(arr, datasize, FILEname);

    printf("�����ɲ������ݲ����浽�ļ� %s\n", FILEname);

    return 0;
}

void readarrayfromFILE(int arr[], int n, const char* FILEname) {
    FILE* FILE = fopen(FILEname, "r");
    if (FILE == NULL) {
        fprintf(stderr, "�޷����ļ� %s\n", FILEname);
        exit(1); 
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(FILE, "%d", &arr[i]) != 1) {
            fprintf(stderr, "��ȡ�ļ�ʱ��������\n");
            exit(1);
        }
    }

    fclose(FILE);
}

void writearraytoFILE(int arr[], int n, const char* FILEname) {
    FILE* FILE = fopen(FILEname, "w");
    if (FILE == NULL) {
        fprintf(stderr, "�޷����ļ� %s\n", FILEname);
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
    int* data = (int*)malloc(datasize * sizeof(int)); // ʹ�ö�̬�ڴ����Ϊ��������ڴ�

    // ���ļ��ж�ȡ����
    readarrayfromFILE(data, datasize, inputFILEname);

    // ���������㷨��������
    insertionSort(data, datasize);

    // ������������д���ļ�
    writearraytoFILE(data, datasize, outputFILEname);

    printf("�ѽ����������ݱ��浽�ļ� %s\n", outputFILEname);

    free(data); // Free dynamically allocated memory

    return 0;
}