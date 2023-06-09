#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generateData.h"

void generateAsc(int* values, int size) {
	int i;
	for(i = 0; i < size; i++){
		values[i] = i;
	}
}

// TEMPO MÉDIO
// QUICKSORT: 67.545289
// SELECTION SORT: 67.434224
// BINARY SEARCH: 0.000005
// LINEAR SEARCH: 0.000175


void generateDesc(int* values, int size) {
	int i;
	for(i = size; i > 0; i--){
		values[i] = i;
	}
}

void generateRand(int* values, int size) {
	int i;
	for(i = 0; i < size; i++){
		values[i] = rand();
	}
}

int main() {
    FILE* dataFile;
	int i;
	char filePath[] = "./data/x.bin";

	for (i = 1; i <= TOTAL_FILES; i++) {
		int size = INIT_SIZE + i * SIZE_INTERVAL;
		filePath[7] = i + '0';
		dataFile = fopen(filePath, "w+b");

		if(dataFile == NULL) {
			return 0;
		}

		int values[size];
		// generateAsc(values, size);
		generateDesc(values, size);
		// generateRand(values, size);

		int j;
		for(j = 0; j < size; j++) {
			fwrite(&values[j], sizeof(int), 1, dataFile);
		}

		fclose(dataFile);
	}

    return 0;
}