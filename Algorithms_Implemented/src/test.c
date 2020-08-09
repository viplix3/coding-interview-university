#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

#define TEST_ARRAY_SIZE 10

void printArray(int *array, int arraySize){
	int i = 0;

	for(; i<arraySize; i++)
		printf("%d \t", array[i]);
	printf("\n");
}

int main(int argc, char *argv[]){

	int testArrayAlternated[] = {0, 9, 1, 8, 2, 7, 3, 6, 4, 5};
	int testArrayReversed[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int testArraySorted[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int testArrayRepeated[] = {3, 3, -1, -1, 2, 2, 0, 0, 1, 1};

	printf("\n****** Alternated array sorting test ******\n");
	printf("Input array\n");
	printArray(testArrayAlternated,TEST_ARRAY_SIZE);
	insertionSort(testArrayAlternated, TEST_ARRAY_SIZE);
	printf("Sorted array\n");
	printArray(testArrayAlternated, TEST_ARRAY_SIZE);

	printf("\n****** Reversed array sorting test ******\n");
	printf("Input array\n");
	printArray(testArrayReversed,TEST_ARRAY_SIZE);
	insertionSort(testArrayReversed, TEST_ARRAY_SIZE);
	printf("Sorted array\n");
	printArray(testArrayReversed, TEST_ARRAY_SIZE);

	printf("\n****** Sorted array sorting test ******\n");
	printf("Input array\n");
	printArray(testArraySorted,TEST_ARRAY_SIZE);
	insertionSort(testArraySorted, TEST_ARRAY_SIZE);
	printf("Sorted array\n");
	printArray(testArraySorted, TEST_ARRAY_SIZE);

	printf("\n****** Repeated array sorting test ******\n");
	printf("Input array\n");
	printArray(testArrayRepeated,TEST_ARRAY_SIZE);
	insertionSort(testArrayRepeated, TEST_ARRAY_SIZE);
	printf("Sorted array\n");
	printArray(testArrayRepeated, TEST_ARRAY_SIZE);


	return 0;
}