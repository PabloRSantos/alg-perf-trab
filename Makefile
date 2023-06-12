run:
	gcc main.c quickSort.c selectionSort.c linearSearch.c binarySearch.c data.c path.c -o main && ./main

run-generatedata:
	gcc generateData.c path.c -o main && ./main