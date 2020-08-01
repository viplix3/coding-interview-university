#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>

#define TRUE_FLAG 1
#define FALSE_FLAG 0
#define EXIT_FLAG -1
#define DOUBLING_FACTOR 2
#define DEFAULT_ARRAY_CAPACITY 16
#define ZERO_FLAG 0
#define QUARTER_FACTOR 0.25

typedef struct{
	int size;
	unsigned capacity;
	int *data;
} DynamicArray;

DynamicArray *initializeArray(); 
int size(DynamicArray *array_object);
unsigned capacity(DynamicArray *array_object);
int isEmpty(DynamicArray *array_object);
int isFull(DynamicArray *array_object);
int getItem(DynamicArray *array_object, int index);
void setItem(DynamicArray *array_object, int index, int item);
void resizeArray(DynamicArray *array_object, int new_size);
void checkAndResize(DynamicArray *array_object);
void push(DynamicArray *array_object, int item);
void prepend(DynamicArray *array_object, int item);
void insert(DynamicArray *array_object, int index, int item);
int pop(DynamicArray *array_object);
void deleteElementFormLoc(DynamicArray *array_object, int index);
void removeElement(DynamicArray *array_object, int item, int removeAll);
int find(DynamicArray *array_object, int item);
void printArray(DynamicArray *array);

#ifdef __cplusplus
};
#endif
#endif