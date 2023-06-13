#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generateData.h"
#include "path.h"

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
	int i;

	for (i = 0; i < INDEX_SIZE; i++)
	{
		indices[i] = rand() % (size + 1);
	}
}

int main()
{
	FILE *dataFile;
	FILE *indiceFile;
	int i, l;
	char dataFilePath[PATH_LENGTH];
	char dataFileName[PATH_LENGTH];
	char indiceFilePath[PATH_LENGTH];
	char indiceFileName[PATH_LENGTH];
	char dirName[DIR_LENGTH];

	for (l = 0; l < DATA_TYPES; l++)
	{
		getDirName(l, dirName);

		for (i = 1; i <= TOTAL_FILES; i++)
		{
			getFileName(i, dataFileName);
			getFilePath(dataFileName, dirName, dataFilePath);

			getIndiceFileName(i, indiceFileName);
			getFilePath(indiceFileName, dirName, indiceFilePath);

			dataFile = fopen(dataFilePath, "w+b");
			indiceFile = fopen(indiceFilePath, "w+b");

			if (dataFile == NULL || indiceFile == NULL)
			{
				return 0;
			}

			int size = INIT_SIZE + i * SIZE_INTERVAL;
			int values[size];
			int indices[INDEX_SIZE];

			generateIndices(indices, size);

			if (l == 0)
			{
				generateRand(values, size);
			}
			else if (l == 1)
			{

				generateAsc(values, size);
			}
			else
			{

				generateDesc(values, size);
			}

			int j;
			for (j = 0; j < size; j++)
			{
				fwrite(&values[j], sizeof(int), 1, dataFile);
			}
			for (j = 0; j < INDEX_SIZE; j++)
			{
				fwrite(&indices[j], sizeof(int), 1, indiceFile);
			}

			fclose(dataFile);
			fclose(indiceFile);
		}
	}

	return 0;
}