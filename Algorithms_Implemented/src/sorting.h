#ifndef SORTING_H
#define SORTING_H
#ifdef __cplusplus
extern "C" {
#endif

#define TRUE_FLAG 1
#define FALSE_FLAG 0
#define EXIT_FLAG -1

void swap(int *a, int *b);
void insertionSort(int *array, int arraySize);
void selectionSort(int *array, int araaySize);

#ifdef __cplusplus
};
#endif
#endif