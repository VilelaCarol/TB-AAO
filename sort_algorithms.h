#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

//declaração das funções de ordenação
void bubbleSort(int arr[], int n, int *comparisons, int *swaps);
void selectionSort(int arr[], int n, int *comparisons, int *swaps);
void insertionSort(int arr[], int n, int *comparisons, int *swaps);
void mergeSort(int arr[], int l, int r, int *comparisons, int *swaps);
void merge(int arr[], int l, int m, int r, int *comparisons, int *swaps);  
void heapSort(int arr[], int n, int *comparisons, int *swaps);
void heapify(int arr[], int n, int i, int *comparisons, int *swaps);
void quickSort(int arr[], int low, int high, int *comparisons, int *swaps);
int partition(int arr[], int low, int high, int *comparisons, int *swaps);

#endif // SORT_ALGORITHMS_H
