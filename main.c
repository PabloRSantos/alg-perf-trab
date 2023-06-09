#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "binarySearch.h"
#include "linearSearch.h"
#include "generateData.h"


int main() {
  char file[] = "./data/x.bin";
  int i, j;
  clock_t start, end;
  double time;

  double quickSortTotalTime = 0;
  double selectionSortTotalTime = 0;
  double linearSearchTotalTime = 0;
  double binarySearchTotalTime = 0;

  for(i = 1; i <= TOTAL_FILES; i++) {
    file[7] = i + '0';
    int size = getDataSize(file);
    printf("\n\n\nTamanho array: %d\n", size);
    int* dataset = (int*) malloc(sizeof(int) * size);
    dataset = getData(file);

    printf("QUICK SORT\n");
    start = clock();
    quickSort(dataset, 0, size - 1);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    quickSortTotalTime += time;
    printf("Tempo de execução: %f segundos\n\n\n", time);


    printf("SELECTION SORT\n");
    start = clock();
    selectionSort(dataset, size);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    selectionSortTotalTime += time;
    printf("Tempo de execução: %f segundos\n\n\n", time);
  
    printf("LINEAR SEARCH\n");
    int indices[3] = { 0, size / 2, size };
    for(j = 0; j < 3; j++) {
        int targetValue = dataset[indices[j]];

	      start = clock();
        linearSearch(dataset, targetValue);
        end = clock();
        time = ((double) (end - start)) / CLOCKS_PER_SEC;
        linearSearchTotalTime += time;

        printf("Tempo de execução indice %d: %f segundos\n", indices[j], time);
    }

    printf("\n\n\nBINARY SEARCH\n");
    for(j = 0; j < 3; j++) {
        int targetValue = dataset[indices[j]];

	      start = clock();
        binarySearch(dataset, 0, size - 1, targetValue);
        end = clock();
        time = ((double) (end - start)) / CLOCKS_PER_SEC;
        binarySearchTotalTime += time;

        printf("Tempo de execução indice %d: %f segundos\n", indices[j], time);
    }

  }

  printf("\n\nTEMPO MÉDIO\n");
  printf("QUICKSORT: %f\n", quickSortTotalTime / 5);
  printf("SELECTION SORT: %f\n", selectionSortTotalTime / 5);
  printf("BINARY SEARCH: %f\n", binarySearchTotalTime / 5);
  printf("LINEAR SEARCH: %f\n", linearSearchTotalTime / 5);
}