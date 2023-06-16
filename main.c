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

#define RUN_TIMES 10

int main()
{
  int i, j, k, l;
  clock_t start, end;
  double time;
  char dataFilePath[PATH_LENGTH];
  char dataFileName[PATH_LENGTH];
  char dirName[DIR_LENGTH];

  double quickSortTotalTime = 0;
  double selectionSortTotalTime = 0;
  double linearSearchTotalTime = 0;
  double binarySearchTotalTime = 0;

  for (l = 0; l < DATA_TYPES - 1; l++)
  {
    getDirName(l, dirName);

    for (i = 1; i <= TOTAL_FILES; i++)
    {
      getFileName(i, dataFileName);
      getFilePath(dataFileName, dirName, dataFilePath);

      double quickSortRunTime = 0;
      double selectionSortRunTime = 0;

      int size = getDataSize(dataFilePath);
      printf("%d Arquivo (%s) tamanho: %d\n", i, dirName, size);

      int *dataset = (int *)malloc(sizeof(int) * size);

      for (k = 0; k < RUN_TIMES; k++)
      {
        dataset = getData(dataFilePath);
        start = clock();
        quickSort(dataset, 0, size - 1);
        end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        quickSortTotalTime += time;
        quickSortRunTime += time;

        dataset = getData(dataFilePath);
        start = clock();
        selectionSort(dataset, size);
        end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        selectionSortTotalTime += time;
        selectionSortRunTime += time;
      }

      printf("\nTEMPO MÉDIO - RODADAS %d\n", RUN_TIMES);
      printf("QUICKSORT: %f\n", quickSortRunTime / RUN_TIMES);
      printf("SELECTION SORT: %f\n\n", selectionSortRunTime / RUN_TIMES);

      free(dataset);
    }
  }

  getDirName(3, dirName);
  for (i = 1; i <= TOTAL_FILES; i++)
  {
    getFileName(i, dataFileName);
    getFilePath(dataFileName, dirName, dataFilePath);

    int size = getDataSize(dataFilePath);
    printf("%d Arquivo (%s) tamanho: %d\n", i, dirName, size);

    int *dataset = (int *)malloc(sizeof(int) * size);
    dataset = getData(dataFilePath);

    double linearSearchTime = 0;
    double binarySearchTime = 0;
    for (j = 0; j < size; j++)
    {
      int targetValue = dataset[j];
      start = clock();
      linearSearch(dataset, targetValue, size);
      end = clock();
      time = ((double)(end - start)) / CLOCKS_PER_SEC;
      linearSearchTime += time;

      start = clock();
      binarySearch(dataset, 0, size - 1, targetValue);
      end = clock();
      time = ((double)(end - start)) / CLOCKS_PER_SEC;
      binarySearchTime += time;
    }
    linearSearchTotalTime += linearSearchTime / size;
    binarySearchTotalTime += binarySearchTime / size;

    printf("\nTEMPO MÉDIO - RODADAS %d\n", size);
    printf("BINARY SEARCH: %f\n", binarySearchTime / size);
    printf("LINEAR SEARCH: %f\n\n", linearSearchTime / size);

    free(dataset);
  }

  int RUNS = RUN_TIMES * TOTAL_FILES * DATA_TYPES;

  printf("\nTEMPO MÉDIO FINAL\n\n");
  printf("QUICKSORT: %f\n", quickSortTotalTime / RUNS);
  printf("SELECTION SORT: %f\n", selectionSortTotalTime / RUNS);
  printf("BINARY SEARCH: %f\n", binarySearchTotalTime / TOTAL_FILES);
  printf("LINEAR SEARCH: %f\n", linearSearchTotalTime / TOTAL_FILES);
}