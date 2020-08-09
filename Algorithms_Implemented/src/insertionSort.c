#include "sorting.h"

// THis function will sort a given array in asecding order (in-place).
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