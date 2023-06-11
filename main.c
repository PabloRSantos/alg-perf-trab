#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "binarySearch.h"
#include "linearSearch.h"
#include "generateData.h"

int main()
{
  char dataFilePath[] = "./data/x.bin";
  char indiceFilePath[] = "./data/x.indice.bin";
  int i, j;
  clock_t start, end;
  double time;

  double quickSortTotalTime = 0;
  double selectionSortTotalTime = 0;
  double linearSearchTotalTime = 0;
  double binarySearchTotalTime = 0;

  for (i = 1; i <= TOTAL_FILES; i++)
  {
    dataFilePath[7] = i + '0';
    indiceFilePath[7] = i + '0';

    int size = getDataSize(dataFilePath);
    printf("Tamanho array: %d\n\n\n", size);

    int *dataset = (int *)malloc(sizeof(int) * size);
    dataset = getData(dataFilePath);

    printf("QUICK SORT\n");
    start = clock();
    quickSort(dataset, 0, size - 1);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    quickSortTotalTime += time;
    printf("Tempo de execução: %f segundos\n\n", time);

    printf("SELECTION SORT\n");
    start = clock();
    selectionSort(dataset, size);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    selectionSortTotalTime += time;
    printf("Tempo de execução: %f segundos\n\n", time);

    int *indiceDataset = (int *)malloc(sizeof(int) * size);
    indiceDataset = getData(indiceFilePath);

    printf("LINEAR SEARCH\n");
    double linearSearchTime = 0;
    for (j = 0; j < size; j++)
    {
      int targetValue = dataset[indiceDataset[j]];

      start = clock();
      linearSearch(dataset, targetValue, size);
      end = clock();
      time = ((double)(end - start)) / CLOCKS_PER_SEC;
      linearSearchTotalTime += time;
      linearSearchTime += time;
    }
    printf("Tempo de execução: %f segundos\n\n", linearSearchTime);

    printf("BINARY SEARCH\n\n");
    double binarySearchTime = 0;
    for (j = 0; j < size; j++)
    {
      int targetValue = dataset[indiceDataset[j]];

      start = clock();
      binarySearch(dataset, 0, size - 1, targetValue);
      end = clock();
      time = ((double)(end - start)) / CLOCKS_PER_SEC;
      binarySearchTotalTime += time;
      binarySearchTime += time;
    }
    printf("Tempo de execução: %f segundos\n\n", binarySearchTime);

    free(dataset);
    free(indiceDataset);
  }

  printf("TEMPO MÉDIO\n\n");
  printf("QUICKSORT: %f\n", quickSortTotalTime / 5);
  printf("SELECTION SORT: %f\n", selectionSortTotalTime / 5);
  printf("BINARY SEARCH: %f\n", binarySearchTotalTime / 5);
  printf("LINEAR SEARCH: %f\n", linearSearchTotalTime / 5);
}