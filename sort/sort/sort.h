#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>
#include <time.h>

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void PrintArray(int *arr, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int *arr, int left, int right)
{
	for (int i = left+1; i <= right; i++)
	{
		int j = i;
		while (j > left && arr[j] < arr[j-1])
		{
			Swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}

void InsertSort_1(int *arr, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tmp = arr[i];
		int j = i;
		while (j > left && tmp < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
	}
}

void InsertSort_2(int *arr, int left,int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		arr[0] = arr[i];
		int j = i;
		while (arr[0] < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = arr[0];
	}
}

void BinInsertSort(int *arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int tmp = arr[i];
		int low = left;
		int high = i - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[i] >= arr[mid])
				low = mid + 1;
			if (arr[i] < arr[mid])
				high = mid - 1;
		}

		for (int j = i; j>low; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[low] = tmp;
	}
}

void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	//InsertSort_1(arr, left, right);
	InsertSort_2(arr, left, right);
	//BinInsertSort(arr, left, right);

	PrintArray(arr, left, right);
}


void TestSortEfficiency()
{
	int n = 10000;
	int *a = (int*)malloc(sizeof(int)* n);
	int *a1 = (int*)malloc(sizeof(int)* n);
	int *a2 = (int*)malloc(sizeof(int)* n);
	srand((unsigned)time(NULL));
	for (int i = 0; i<n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
	}

	time_t start = clock();
	InsertSort(a, 0, n - 1);
	time_t end = clock();
	printf("InsertSort: %u\n", end - start);

	start = clock();
	InsertSort_1(a1, 0, n - 1);
	end = clock();
	printf("InsertSort_1: %u\n", end - start);

	start = clock();
	BinInsertSort(a2, 0, n - 1);
	end = clock();
	printf("BinInsertSort: %u\n", end - start);
}

#endif /*_SORT_H_*/