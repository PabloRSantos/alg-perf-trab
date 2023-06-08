#include <stdlib.h>
#include <stdio.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função para realizar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Percorre o array
    for (i = 0; i < n - 1; i++) {
        // Encontra o elemento mínimo no subarray não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Troca o elemento mínimo com o primeiro elemento não ordenado
        swap(&arr[min_idx], &arr[i]);
    }
}
