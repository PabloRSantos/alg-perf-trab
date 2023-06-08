#include <stdio.h>
#include <stdlib.h>

int partition(int* vet, int left, int right) {
  int posPivot = left;
  int i, j;
  for (i = left + 1; i <= right; i++) {
    if (vet[i] < vet[posPivot]) {
      int aux = vet[i];
      for (j = i - 1; j >= posPivot; j--) {
        vet[j + 1] = vet[j];
      }
      vet[posPivot] = aux;
      posPivot++;
    }
  }
  return posPivot;
}

void quickSort(int* vet, int left, int right) {
  if (left < right) {
    int q = partition(vet, left, right);
    quickSort(vet, left, q - 1);
    quickSort(vet, q + 1, right);
  }
}
