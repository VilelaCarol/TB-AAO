#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_algorithms.h"

//função para gerar vetores de teste
void generateArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    int n = 10000;
    int arr[n];
    clock_t start, end;
    double cpu_time_used;

    generateArray(arr, n);

    start = clock();
    bubbleSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do bubbleSort: %f\n", cpu_time_used);

    generateArray(arr, n);

    start = clock();
    selectionSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do selectionSort: %f\n", cpu_time_used);

    generateArray(arr, n);

    start = clock();
    insertionSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do insertionSort: %f\n", cpu_time_used);

    generateArray(arr, n);

    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do mergeSort: %f\n", cpu_time_used);

    generateArray(arr, n);

    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do heapSort: %f\n", cpu_time_used);

    generateArray(arr, n);

    start = clock();
    quickSort(arr, 0, n-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do quickSort: %f\n", cpu_time_used);

    return 0;
}