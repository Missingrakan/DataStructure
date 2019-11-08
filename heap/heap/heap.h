#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>

#define DataType int


typedef struct Heap
{
	DataType *heap;
	size_t   capacity;
	size_t   size;
}Heap;

void HeapInit(Heap *php, int sz);
void HeapDestroy(Heap *php);

bool HeapInsert(Heap *php, DataType x);
void HeapShow(Heap *php);
DataType HeapTop(Heap *php);
bool HeapRemove(Heap *php);

void _AdjustUp(Heap *php, int start);
void _AdjustDown(Heap *php, int start);



#endif/*_HEAP_H_*/