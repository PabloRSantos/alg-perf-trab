#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDataSize(char *file)
{
	FILE *dataFile = fopen(file, "r");

	if (dataFile == NULL)
	{
		return 0;
	}

	fseek(dataFile, 0, SEEK_END);
	int fileSize = ftell(dataFile);
	fclose(dataFile);

	return fileSize / sizeof(int);
}

int *getData(char *file)
{
	int i;
	FILE *dataFile = fopen(file, "r");

	if (dataFile == NULL)
	{
		return 0;
	}

	int fileLength = getDataSize(file);
	int *data = (int *)malloc(sizeof(int) * fileLength);

	if (data == NULL)
	{
		return NULL;
	}

	for (i = 0; i < fileLength; i++)
	{
		fread(&data[i], sizeof(int), 1, dataFile);
	}
	fclose(dataFile);

	return data;
}
