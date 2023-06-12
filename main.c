#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "binarySearch.h"
#include "linearSearch.h"
#include "generateData.h"
#include "path.h"

#define RUN_TIMES 100

int main()
{
  int i, j, k, l;
  clock_t start, end;
  double time;
  char dataFilePath[PATH_LENGTH];
  char dataFileName[PATH_LENGTH];
  char indiceFilePath[PATH_LENGTH];
  char indiceFileName[PATH_LENGTH];
  char dirName[DIR_LENGTH];

  double quickSortTotalTime = 0;
  double selectionSortTotalTime = 0;
  double linearSearchTotalTime = 0;
  double binarySearchTotalTime = 0;

  for (l = 0; l < DATA_TYPES; l++)
  {
    getDirName(l, dirName);

    for (i = 1; i <= TOTAL_FILES; i++)
    {
      getFileName(i, dataFileName);
      getFilePath(dataFileName, dirName, dataFilePath);

      getIndiceFileName(i, indiceFileName);
      getFilePath(indiceFileName, dirName, indiceFilePath);

      double quickSortRunTime = 0;
      double selectionSortRunTime = 0;
      double linearSearchRunTime = 0;
      double binarySearchRunTime = 0;

      int size = getDataSize(dataFilePath);
      printf("%d Arquivo (%s) tamanho: %d\n", i, dirName, size);

      int *dataset = (int *)malloc(sizeof(int) * size);
      dataset = getData(dataFilePath);
      int *indiceDataset = (int *)malloc(sizeof(int) * size);
      indiceDataset = getData(indiceFilePath);

      for (k = 0; k < RUN_TIMES; k++)
      {
        // printf("QUICK SORT\n");
        start = clock();
        quickSort(dataset, 0, size - 1);
        end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        quickSortTotalTime += time;
        quickSortRunTime += time;
        // printf("Tempo de execução: %f segundos\n\n", time);

        // printf("SELECTION SORT\n");
        start = clock();
        selectionSort(dataset, size);
        end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        selectionSortTotalTime += time;
        selectionSortRunTime += time;
        // printf("Tempo de execução: %f segundos\n\n", time);

        // printf("LINEAR SEARCH\n");
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
        linearSearchRunTime += linearSearchTime;
        // printf("Tempo de execução: %f segundos\n\n", linearSearchTime);

        // printf("BINARY SEARCH\n");
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
        binarySearchRunTime += binarySearchTime;
        // printf("Tempo de execução: %f segundos\n\n\n", binarySearchTime);
      }

      printf("\nTEMPO MÉDIO - RODADAS %d\n\n", RUN_TIMES);
      printf("QUICKSORT: %f\n", quickSortRunTime / RUN_TIMES);
      printf("SELECTION SORT: %f\n", selectionSortRunTime / RUN_TIMES);
      printf("BINARY SEARCH: %f\n", binarySearchRunTime / RUN_TIMES);
      printf("LINEAR SEARCH: %f\n\n", linearSearchRunTime / RUN_TIMES);

      free(dataset);
      free(indiceDataset);
    }
  }

  int RUNS = RUN_TIMES * TOTAL_FILES;

  printf("\nTEMPO MÉDIO FINAL\n\n");
  printf("QUICKSORT: %f\n", quickSortTotalTime / RUNS);
  printf("SELECTION SORT: %f\n", selectionSortTotalTime / RUNS);
  printf("BINARY SEARCH: %f\n", binarySearchTotalTime / RUNS);
  printf("LINEAR SEARCH: %f\n", linearSearchTotalTime / RUNS);
}