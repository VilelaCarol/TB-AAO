#include "sort_algorithms.h"

//implementação do bubblesort com contador de comparações e swaps
void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j+1]) {
                // Troca arr[j] e arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}

//implementação do selectionsort
void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca arr[i] e arr[minIndex]
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        (*swaps)++;
    }
}
/*void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca arr[i] e arr[minIndex]
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}*/

//implementação do insertionsort
void insertionSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            // Troca arr[j+1] e arr[j]
            arr[j+1] = arr[j];
            j = j - 1;
            (*swaps)++;
        }
        arr[j+1] = key;
    }
}

/*void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}*/

//implementação do mergesort
void mergeSort(int arr[], int l, int r, int *comparisons, int *swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons, swaps);
        mergeSort(arr, m+1, r, comparisons, swaps);
        merge(arr, l, m, r, comparisons, swaps);
    }
}
/*void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}*/

//implementação do heapsort
void heapSort(int arr[], int n, int *comparisons, int *swaps) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, swaps);
    }
    for (i = n - 1; i >= 0; i--) {
        // Troca arr[0] e arr[i]
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, comparisons, swaps);
    }
}
/*void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--) {
        // Troca arr[0] e arr[i]
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}*/

//implementação do quicksort
void quickSort(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}
/*void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/

