#include <stdio.h>
#include <time.h>
#define SIZE 1000000

int linearSearch(int arr[], int target) {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}
