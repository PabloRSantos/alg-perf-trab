#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50000
#define FILE_PATH "./data/5.bin"

int main() {
    FILE* dataFile;

    dataFile = fopen(FILE_PATH, "w+b");

    if(dataFile == NULL) {
		return 0;
	}

	int i;
	for(i = 0; i < SIZE; i++){
		int value = rand();
	    fwrite(&value, sizeof(int), 1, dataFile);
	}

    fclose(dataFile);
    return 0;
}