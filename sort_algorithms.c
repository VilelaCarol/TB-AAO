#include "sort_algorithms.h"

// Implementação do Bubble Sort com contador de comparações e swaps
void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}

// Implementação do Selection Sort com contador de comparações e swaps
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
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        (*swaps)++;
    }
}

// Implementação do Insertion Sort com contador de comparações e swaps
void insertionSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;  
            arr[j+1] = arr[j];
            j = j - 1;
            (*swaps)++;
        }

        if (j >= 0) {
            (*comparisons)++;
        }

        arr[j+1] = key;
    }
}




// Implementação do Merge Sort com contador de comparações (sem trocas reais)
void mergeSort(int arr[], int l, int r, int *comparisons, int *swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons, swaps);
        mergeSort(arr, m+1, r, comparisons, swaps);
        merge(arr, l, m, r, comparisons, swaps);
    }
}

void merge(int arr[], int l, int m, int r, int *comparisons, int *swaps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
}

// Implementação do Heap Sort com contador de comparações e swaps
void heapSort(int arr[], int n, int *comparisons, int *swaps) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, swaps);
    }
    for (i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*swaps)++;
        heapify(arr, i, 0, comparisons, swaps);
    }
}

void heapify(int arr[], int n, int i, int *comparisons, int *swaps) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        (*comparisons)++;
        if (arr[l] > arr[largest]) {
            largest = l;
        }
    }

    if (r < n) {
        (*comparisons)++;
        if (arr[r] > arr[largest]) {
            largest = r;
        }
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*swaps)++;
        heapify(arr, n, largest, comparisons, swaps);
    }
}



// Implementação do Quick Sort com contador de comparações e swaps
void quickSort(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

int partition(int arr[], int low, int high, int *comparisons, int *swaps) {
    int pivot = arr[high];
    int i = (low - 1);
    int temp;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++; 
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swaps)++;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swaps)++;
    return (i + 1);
}
