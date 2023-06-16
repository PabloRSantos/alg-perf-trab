#include "string.h"

void getFileName(int index, char *fileName)
{
  strcpy(fileName, "x.bin");
  fileName[0] = index + '0';
}

void getFilePath(char *fileName, char *dirName, char *filePath)
{
  strcpy(filePath, "./data/");
  strncat(filePath, dirName, strlen(dirName));
  strncat(filePath, fileName, strlen(fileName));
}

void getDirName(int index, char *dirName)
{
  switch (index)
  {
  case 0:
    strcpy(dirName, "rand.");
    break;
  case 1:
    strcpy(dirName, "asc.");
    break;
  case 2:
    strcpy(dirName, "desc.");
    break;
  default:
    strcpy(dirName, "search.");
    break;
  }
}
