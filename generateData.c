#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generateData.h"

void generateAsc(int *values, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		values[i] = i;
	}
}

void generateDesc(int *values, int size)
{
	int i;
	int j = 0;
	for (i = size; i > 0; i--)
	{
		values[j] = i;
		j++;
	}
}

void generateRand(int *values, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		values[i] = rand();
	}
}

void generateIndices(int *indices, int size)
{
	int orderedIndices[size];
	int i;

	for (i = 0; i < size; i++)
	{
		indices[i] = rand() % (size + 1);
	}
}

int main()
{
	FILE *dataFile;
	FILE *indiceFile;
	int i;
	char filePath[] = "./data/x.bin";
	char indiceFilePath[] = "./data/x.indice.bin";

	for (i = 1; i <= TOTAL_FILES; i++)
	{
		int size = INIT_SIZE + i * SIZE_INTERVAL;
		filePath[7] = i + '0';
		indiceFilePath[7] = i + '0';
		dataFile = fopen(filePath, "w+b");
		indiceFile = fopen(indiceFilePath, "w+b");

		if (dataFile == NULL || indiceFile == NULL)
		{
			return 0;
		}

		int values[size];
		int indices[size];

		generateIndices(indices, size);

		// generateAsc(values, size);
		// generateDesc(values, size);
		generateRand(values, size);

		int j;
		for (j = 0; j < size; j++)
		{
			fwrite(&values[j], sizeof(int), 1, dataFile);
			fwrite(&indices[j], sizeof(int), 1, indiceFile);
		}

		fclose(dataFile);
		fclose(indiceFile);
	}

	return 0;
}