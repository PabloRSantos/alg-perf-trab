#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return arr[i];
        }
    }
    return -1;
}
