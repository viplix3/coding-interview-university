// Implementation of DynamicArray (C++ vector) using C.
#include "dynamic_array.h"

// This function initalizes the array and allocates it the required memory.
DynamicArray* initializeArray(){
	//Allocating memory to the structure object
	DynamicArray *array_object = (DynamicArray*)malloc(sizeof(DynamicArray));

	//Allocating/Initializing the objects inside structures
	array_object->data = (int*)malloc(sizeof(int)*DEFAULT_ARRAY_CAPACITY);
	array_object->size = ZERO_FLAG;
	array_object->capacity = DEFAULT_ARRAY_CAPACITY;

	return array_object;
}

 // This his function will return the size/num of elements of/in DynamicArray in O(1)
int size(DynamicArray *array_object){
	return array_object->size;
}

// This function will return the maximum number of elements the DynamicArray can currently hold.
unsigned capacity(DynamicArray *array_object){
	return array_object->capacity;
}

// This function will return a boolean flag. 1 if Dynamic array is empty, 0 otherwise.
int isEmpty(DynamicArray *array_object){
	if(size(array_object))
		return FALSE_FLAG;
	return TRUE_FLAG;
}

// This function will return a boolean flag. 1 if Dynamic array is at its capacity, 0 otherwise.
int isFull(DynamicArray *array_object){
	if(size(array_object) == (int)capacity(array_object))
		return TRUE_FLAG;
	return FALSE_FLAG;
}

// This function will return the element at provided index for the DynamicArray. 
// Will raise an exception if the index is invalid.
int getItem(DynamicArray *array_object, int index){
	if( (index < ZERO_FLAG) || (size(array_object) < index)){
		printf("Provided index %d is invalid\n", index);
		return EXIT_FLAG;
	}
	return array_object->data[index];
}

// This function will change the element at provided index for the DynamicArray. 
// Will raise an exception if the index is invalid.
void setItem(DynamicArray *array_object, int index, int item){
	if( (index < ZERO_FLAG) || (size(array_object) < index)){
		printf("Provided index %d is invalid. It's either beyond capacity %d or next insertion index.\n", 
			index, capacity(array_object));
		printf("As array is not filled, element won't be inserted.\n");
		return;
	}
	array_object->data[index] = item;
	checkAndResize(array_object);
}

//This function will resize the array such that it can hold new_size elements.
//It new_size=-1, the size will be doubled.
void resizeArray(DynamicArray *array_object, int new_size){
	// Re-allocating the memory to the original data array
	array_object->data = (int*)(realloc(array_object->data, sizeof(int)*new_size));
	array_object->capacity = new_size;
}


//This checks if new element can be inserted in array.
//If not (array is at its capacity) array will be resized to 2x the current capacity.
void checkAndResize(DynamicArray *array_object){
	if(isFull(array_object)){
		printf("Dynamic Array is at its capacity. Resizing the capacity from %d to %d\n", 
			capacity(array_object), DOUBLING_FACTOR*capacity(array_object));
		//Increasing the array capacity to double of what it is currently 
		// so that item can be pushed.
		resizeArray(array_object, DOUBLING_FACTOR*capacity(array_object)); 
	}

	if((size(array_object) > 4) && (size(array_object) < (int)(QUARTER_FACTOR*capacity(array_object)))){
		printf("Dynamic Array is using less than quater of its capacity. ");
		printf("Resizing the capacity from %d to %d\n"
			, capacity(array_object), (int)(capacity(array_object) / DOUBLING_FACTOR));
		resizeArray(array_object, (int)(capacity(array_object) / DOUBLING_FACTOR));
	}
}

//This function will push elements to the end of DynamicArray.
// Array resizing will be done if required.
void push(DynamicArray *array_object, int item){
	checkAndResize(array_object);

	//Inserting iteam at the end of array
	setItem(array_object, size(array_object), item);
	array_object->size++;
}

//This function will insert iteam at the starting of the array.
void prepend(DynamicArray *array_object, int item){
	int i = size(array_object);
	array_object->size++;
	checkAndResize(array_object);

	for(; i>=ZERO_FLAG; i--) //Shifting all the elements to insert item at the beginning of the array.
		setItem(array_object, i+1, (getItem(array_object, i)));

	//Inserting the object in the deginning of the array
	setItem(array_object, ZERO_FLAG, item);
}


// This function will insert the element at provided index for the DynamicArray. 
// Will raise an exception if the index is invalid.
void insert(DynamicArray *array_object, int index, int item){
	int i = size(array_object);
	array_object->size++;
	checkAndResize(array_object);

	for(; i>=index; i--)
		setItem(array_object, i, getItem(array_object, i-1));

	setItem(array_object, index, item);
}

//This function will remove the item at the last idex of the array.
int pop(DynamicArray *array_object){
	int removed_item = getItem(array_object, size(array_object));
	array_object->size--;
	checkAndResize(array_object); //Reduce the capacity of array if size < 1/4 * capacity
	return removed_item;
}

//This function deleted elemets from the specified index of the array.
void deleteElementFormLoc(DynamicArray *array_object, int index){
	int removed_item = getItem(array_object, index);
	int __size__ = size(array_object);
	int i = index;

	for(; i<__size__; i++)
		setItem(array_object, i, (getItem(array_object, i+1)));

	array_object->size--;
	checkAndResize(array_object); //Reduce the capacity of array if size < 1/4 * capacity
}

//This function finds the element in the array and return its index if the elements is present, 
// -1 if it isn't.
int find(DynamicArray *array_object, int item){
	int i;
	int __size__ = size(array_object);

	for(i=0; i<__size__; i++)
		if(getItem(array_object, i) == item)
			return i;

	return EXIT_FLAG;
}

//This function first finds the iem in array and then removes it. 
// If multiple such elements are present, removeAll flag dictates what is to be done.
void removeElement(DynamicArray *array_object, int item, int removeAll){
	int i;
	int __size__ = size(array_object);

	while(find(array_object, item) != EXIT_FLAG){
		deleteElementFormLoc(array_object, find(array_object, item));
		if(!removeAll)
			break;
	}

	checkAndResize(array_object); //Reduce the capacity of array if size < 1/4 * capacity
}

// Prints the content of array
void printArray(DynamicArray *array_object){
	int i;
	int __size__ = size(array_object);

	if(isEmpty(array_object))
		printf("Nothing to print. Array is empty\n");
	else{
		printf("Array Stats\nArray size: %d\tArray capacity: %d\nArray contents: \n", __size__, 
			capacity(array_object));
		for(i=0; i<__size__; i++)
			printf("%d\t", getItem(array_object, i));
	}
	printf("\n");
}