#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int i;
	DynamicArray *array = initializeArray();
	printf("***** Array initialized *****\n");
	printArray(array);

	printf("\n***** Pushing elements in array for 0 to %d. ", DEFAULT_ARRAY_CAPACITY+4);
	printf("Size of array should increase to %d in between insertion *****\n", 2*DEFAULT_ARRAY_CAPACITY);
	for(i=0; i<DEFAULT_ARRAY_CAPACITY+4; i++)
		push(array, i);
	printArray(array);

	printf("\n***** Popping elements from array. Capacity should decrease after operation *****\n");
	for(i=0; i<(int)(DEFAULT_ARRAY_CAPACITY); i++)
		pop(array);
	printArray(array);

	printf("\n***** Inserting 16 on the beginning of the array *****\n");
	prepend(array, 16);
	printArray(array);

	printf("\n***** Deleting element at index 4 from array printed *****\n");
	deleteElementFormLoc(array, 4);
	printArray(array);

	printf("\n***** Setting 555 on indices 7, 11 and 4 *****\n");
	setItem(array, 7, 555);
	setItem(array, 11, 555);
	printArray(array);

	printf("\n***** Inserting 555 on index 2 *****\n");
	insert(array, 2, 555);
	printArray(array);

	printf("\n***** Inserting 555 on index 1 *****\n");
	insert(array, 1, 555);
	printArray(array);

	printf("\n***** Inserting 555 on index 4 *****\n");
	insert(array, 4, 555);
	printArray(array);

	printf("\n***** Removing first occurence of 555 from array *****\n");
	removeElement(array, 555, FALSE_FLAG);
	printArray(array);

	printf("\n***** Removing all the occurences of 555 from the array *****\n");
	removeElement(array, 555, TRUE_FLAG);
	printArray(array);

	printf("\n***** Finding element 1 and printing its index *****\n");
	i = find(array, 1);
	printf("\n***** 1 found at location %d *****\n", i);
	printArray(array);


	return 0;
}