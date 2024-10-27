#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "sort_algorithms.h"
#include <locale.h>

// Função para obter o tempo em milissegundos com maior precisão
double get_time_in_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

// Função para gerar vetor aleatório
void generateArray(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 10000;  // Números aleatórios entre 0 e 9999
    }
}

// Função para gerar vetor em ordem decrescente (Base 2)
void generateReverseArray(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = n - i;  
    }
}

// Função para gerar vetor com 50% ordenado e 50% aleatório (melhor caso)
void generateHalfOrderedArray(int vetor[], int n) {
    for (int i = 0; i < n / 2; i++) {
        vetor[i] = i;  
    }
    for (int i = n / 2; i < n; i++) {
        vetor[i] = rand() % 10000; 
    }
}


// Função genérica para testar algoritmos sem limites de índice (Bubble, Selection, Insertion, Heap)
void testSortAlgorithm(void (*sortFunction)(int[], int, int*, int*), const char *algorithmName, int vetor[], int n) {
    int comparisons = 0, swaps = 0;
    double start, end, ms_time_used;

    start = get_time_in_ms();
    sortFunction(vetor, n, &comparisons, &swaps);
    end = get_time_in_ms();
    ms_time_used = end - start;

    printf("%s - Tamanho: %d, Tempo: %.3f ms, Comparações: %d, Trocas: %d\n", 
           algorithmName, n, ms_time_used, comparisons, swaps);
}

// Função para testar algoritmos com índices (Merge Sort, Quick Sort)
void testSortAlgorithmWithIndices(void (*sortFunction)(int[], int, int, int*, int*), const char *algorithmName, int vetor[], int l, int r) {
    int comparisons = 0, swaps = 0;
    double start, end, ms_time_used;

    start = get_time_in_ms();
    sortFunction(vetor, l, r, &comparisons, &swaps);
    end = get_time_in_ms();
    ms_time_used = end - start;

    printf("%s - Intervalo: [%d, %d], Tempo: %.3f ms, Comparações: %d, Trocas: %d\n", 
           algorithmName, l, r, ms_time_used, comparisons, swaps);
}

int main() {
     setlocale(LC_ALL, "pt_BR.UTF-8");
    int small_size = 100;
    int medium_size = 1000;
    int large_size = 10000;

    int vetor_pequeno[small_size];
    int vetor_medio[medium_size];
    int vetor_grande[large_size];

   //  Base 1: Vetor Pequeno (100 elementos) com números gerados aleatoriamente
    generateArray(vetor_pequeno, small_size);
    testSortAlgorithm(bubbleSort, "Bubble Sort - Base 1 (100 elementos)", vetor_pequeno, small_size);
    generateArray(vetor_pequeno, small_size);  
    testSortAlgorithm(selectionSort, "Selection Sort - Base 1 (100 elementos)", vetor_pequeno, small_size);
    generateArray(vetor_pequeno, small_size);
    testSortAlgorithm(insertionSort, "Insertion Sort - Base 1 (100 elementos)", vetor_pequeno, small_size);
    generateArray(vetor_pequeno, small_size);
    testSortAlgorithm(heapSort, "Heap Sort - Base 1 (100 elementos)", vetor_pequeno, small_size);
    generateArray(vetor_pequeno, small_size);
    testSortAlgorithmWithIndices(mergeSort, "Merge Sort - Base 1 (100 elementos)", vetor_pequeno, 0, small_size - 1);
    generateArray(vetor_pequeno, small_size);
    testSortAlgorithmWithIndices(quickSort, "Quick Sort - Base 1 (100 elementos)", vetor_pequeno, 0, small_size - 1);

    // Base 2: Vetor Médio (1000 elementos) em ordem decrescente
    generateReverseArray(vetor_medio, medium_size);
    testSortAlgorithm(bubbleSort, "Bubble Sort - Base 2 (1000 elementos)", vetor_medio, medium_size);
    generateReverseArray(vetor_medio, medium_size);
    testSortAlgorithm(selectionSort, "Selection Sort - Base 2 (1000 elementos)", vetor_medio, medium_size);
    generateReverseArray(vetor_medio, medium_size);
    testSortAlgorithm(insertionSort, "Insertion Sort - Base 2 (1000 elementos)", vetor_medio, medium_size);
    generateReverseArray(vetor_medio, medium_size);
    testSortAlgorithm(heapSort, "Heap Sort - Base 2 (1000 elementos)", vetor_medio, medium_size);
    generateReverseArray(vetor_medio, medium_size);
    testSortAlgorithmWithIndices(mergeSort, "Merge Sort - Base 2 (1000 elementos)", vetor_medio, 0, medium_size - 1);
    generateReverseArray(vetor_medio, medium_size);
    testSortAlgorithmWithIndices(quickSort, "Quick Sort - Base 2 (1000 elementos)", vetor_medio, 0, medium_size - 1);

    //Base 3: Vetor Grande (10.000 elementos) com 50% dos elementos já ordenados
    generateHalfOrderedArray(vetor_grande, large_size);
    testSortAlgorithm(bubbleSort, "Bubble Sort - Base 3 (10.000 elementos)", vetor_grande, large_size);
    generateHalfOrderedArray(vetor_grande, large_size);
    testSortAlgorithm(selectionSort, "Selection Sort - Base 3 (10.000 elementos)", vetor_grande, large_size);
    generateHalfOrderedArray(vetor_grande, large_size);
    testSortAlgorithm(insertionSort, "Insertion Sort - Base 3 (10.000 elementos)", vetor_grande, large_size);
    generateHalfOrderedArray(vetor_grande, large_size);
    testSortAlgorithm(heapSort, "Heap Sort - Base 3 (10.000 elementos)", vetor_grande, large_size);
    generateHalfOrderedArray(vetor_grande, large_size);
    testSortAlgorithmWithIndices(mergeSort, "Merge Sort - Base 3 (10.000 elementos)", vetor_grande, 0, large_size - 1);
    generateHalfOrderedArray(vetor_grande, large_size);
    testSortAlgorithmWithIndices(quickSort, "Quick Sort - Base 3 (10.000 elementos)", vetor_grande, 0, large_size - 1);

    return 0;
}