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

void generateSearch(int *values, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		values[i] = i;
	}
}

int main()
{
	FILE *dataFile;
	int i, l;
	char dataFilePath[PATH_LENGTH];
	char dataFileName[PATH_LENGTH];
	char dirName[DIR_LENGTH];

	for (l = 0; l < DATA_TYPES; l++)
	{
		getDirName(l, dirName);

		for (i = 1; i <= TOTAL_FILES; i++)
		{
			getFileName(i, dataFileName);
			getFilePath(dataFileName, dirName, dataFilePath);

			dataFile = fopen(dataFilePath, "w+b");
			if (dataFile == NULL)
			{
				return 0;
			}

			int size = l < 3 ? (INIT_SIZE + i * SIZE_INTERVAL) : (SEARCH_INIT_SIZE + i * SEARCH_SIZE_INTERVAL);
			int values[size];

			if (l == 0)
			{
				generateRand(values, size);
			}
			else if (l == 1)
			{
				generateAsc(values, size);
			}
			else if(l == 2)
			{

				generateDesc(values, size);
			}
			else
			{
				generateSearch(values, size);
			}

			int j;
			for (j = 0; j < size; j++)
			{
				fwrite(&values[j], sizeof(int), 1, dataFile);
			}

			fclose(dataFile);
		}
	}

	return 0;
}