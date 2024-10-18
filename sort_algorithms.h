//sort_algorithms.h
#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

//declaração das funções de ordenação
void bubbleSort(int arr[], int n, int *comparisons, int *swaps);
void selectionSort(int arr[], int n, int *comparisons, int *swaps);
void insertionSort(int arr[], int n, int *comparisons, int *swaps);
void mergeSort(int arr[], int l, int r, int *comparisons, int *swaps);
void heapSort(int arr[], int n, int *comparisons, int *swaps);
void quickSort(int arr[], int low, int high, int *comparisons, int *swaps);

/*void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void heapSort(int arr[], int n);
void quickSort(int arr[], int low, int high);*/

#endif // SORT_ALGORITHMS_H
