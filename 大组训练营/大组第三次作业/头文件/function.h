#ifndef FUNCTION_H
#define FUNCTION_H

void insertionSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void countingSort(int arr[], int n, int range);
void countingSortForRadix(int arr[], int n, int exp);
void radixSort(int arr[], int n);


#endif 