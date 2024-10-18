#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_algorithms.h"

//função para gerar vetores de teste
void generateArray(int vetor_pequeno[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        vetor_pequeno[i] = rand() % 1000;
    }
}

int main() {
    int small_size = 100;
    int vetor_pequeno[small_size];
    //variaveis para contagem de comparações e trocas
    int comparisons = 0, swaps = 0;
    clock_t start, end;
    double cpu_time_used;

    generateArray(vetor_pequeno, small_size);

    start = clock();
    bubbleSort(vetor_pequeno, small_size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do bubbleSort: %f\n", cpu_time_used);
    printf("Comparações: %d, Trocas: %d\n", comparisons, swaps);

    generateArray(vetor_pequeno, small_size);

    start = clock();
    selectionSort(vetor_pequeno, small_size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do selectionSort: %f\n", cpu_time_used);
    printf("Comparações: %d, Trocas: %d\n", comparisons, swaps);

    generateArray(vetor_pequeno, small_size);

    start = clock();
    insertionSort(vetor_pequeno, small_size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do insertionSort: %f\n", cpu_time_used);
    printf("Comparações: %d, Trocas: %d\n", comparisons, swaps);

    generateArray(vetor_pequeno, small_size);

    start = clock();
    mergeSort(vetor_pequeno, 0, small_size-1, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do mergeSort: %f\n", cpu_time_used);
    printf("Comparações: %d, Trocas: %d\n", comparisons, swaps);

    generateArray(vetor_pequeno, small_size);

    start = clock();
    heapSort(vetor_pequeno, small_size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do heapSort: %f\n", cpu_time_used);
    printf("Comparações: %d, Trocas: %d\n", comparisons, swaps);

    generateArray(vetor_pequeno, small_size);

    start = clock();
    quickSort(vetor_pequeno, 0, small_size-1, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do quickSort: %f\n", cpu_time_used);
    printf("Comparações: %d, Trocas: %d\n", comparisons, swaps);

    return 0;
}