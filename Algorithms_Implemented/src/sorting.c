#include "sorting.h"

void swap(int *a, int *b){
	int placeholder = *b;
	*b = *a;
	*a = placeholder;
}

// This function will sort a given array in asecding order (in-place).
void insertionSort(int *array, int arraySize){
	int key, outerIter, innerIter;
	outerIter = 0;

	while(outerIter < arraySize){
		key = array[outerIter];
		innerIter = outerIter - 1;

		while((innerIter >= 0) && (array[innerIter] > key)){
			array[innerIter + 1] = array[innerIter];
			--innerIter;
		}
		array[innerIter + 1] = key;
		++outerIter;
	}
}

void selectionSort(int *array, int arraySize){
	int minimumElementIndex, outerIter, iter;
	outerIter = 0;

	while(outerIter < arraySize){
		minimumElementIndex = outerIter;
		for(iter = outerIter; iter < arraySize; iter++)
			if(array[iter] < array[minimumElementIndex])
				minimumElementIndex = iter;
		swap(&array[outerIter], &array[minimumElementIndex]);
		++outerIter;
	}
}