#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

bool HeapIsEmpty(Heap *php)
{
	return php->size == 0;
}

bool HeapIsFull(Heap *php)
{
	return php->size >= php->capacity;
}

void HeapInit(Heap *php, int sz)
{
	php->capacity = sz;
	php->size = 0;
	php->heap = (DataType*)malloc(sizeof(DataType) * sz);
}

void HeapDestroy(Heap *php)
{
	php->size = php->capacity = 0;
	free(php->heap);
	php->heap = NULL;
}

void _AdjustUp(Heap *php, int start)
{
	int j = start;
	int i = (j - 1) / 2;
	while (j > 0)
	{
		if (php->heap[j] < php->heap[i])
		{
			Swap(&(php->heap[j]), &(php->heap[i]));
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
}

bool HeapInsert(Heap *php, DataType x)
{
	if (HeapIsFull(php))
	{
		printf("堆已满，%d无法存入!\n");
		return false;
	}

	php->heap[php->size] = x;
	_AdjustUp(php, php->size);
	php->size++;
	return true;
}

void HeapShow(Heap *php)
{
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->heap[i]);
	}
	printf("\n");
}

DataType HeapTop(Heap *php)
{
	if (!HeapIsEmpty(php))
	{
		return php->heap[0];
	}
}

//void _AdjustDown(Heap *php, int start)
//{
//	int i = start;
//	int j = 2 * i + 1;
//	while (j < php->size)
//	{
//		if (j + 1<php->size && php->heap[j]>php->heap[j + 1])
//			j++;
//		if (php->heap[j] < php->heap[i])
//		{
//			Swap(&(php->heap[j]), &(php->heap[i]));
//			i = j;
//			j = 2 * i + 1;
//		}
//		else
//			break;
//	}
//}
void _AdjustDown(Heap *php, int start)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < php->size)
	{
		if (j + 1 < php->size && php->heap[j] > php->heap[j + 1])//如果有右子树
			j++;
		if (php->heap[j] < php->heap[i])
		{
			Swap(&(php->heap[j]), &(php->heap[i]));
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

bool HeapRemove(Heap *php)
{
	if (HeapIsEmpty(php))
		return false;
	php->heap[0] = php->heap[php->size - 1];
	php->size--;
	_AdjustDown(php, 0);
	return true;
}