#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

int main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	int i = 0;
	HeapInit(&hp, sz);
	for (i = 0; i < sz; i++)
	{
		HeapInsert(&hp, arr[i]);
	}
	HeapShow(&hp);
	HeapRemove(&hp);
	HeapShow(&hp);
	HeapRemove(&hp);
	HeapShow(&hp);
	HeapDestroy(&hp);
	return 0;
}
