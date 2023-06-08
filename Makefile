run:
	gcc main.c quickSort.c selectionSort.c linearSearch.c binarySearch.c data.c -o main && ./main

run-generatedata:
	gcc generateData.c -o main && ./main