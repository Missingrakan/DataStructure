#pragma once

#include "common.h"

void PrintArray(int *ar, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void InsertSort(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int j = i;
		while (j > left && ar[j] < ar[j - 1])
		{
			Swap(&ar[j], &ar[j - 1]);
			j--;
		}
	}
}

void InsertSort_1(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tmp = ar[i];
		int j = i;
		while (j > left && tmp < ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = tmp;
	}
}

void InsertSort_2(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		ar[0] = ar[i];
		int j = i;
		while (ar[0] < ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = ar[0];
	}
}

void BinInsertSort(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tmp = ar[i];
		int low = left;
		int high = i - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (ar[i] >= ar[mid])
				low = mid + 1;
			if (ar[i] < ar[mid])
				high = mid - 1;
		}

		for (int j = i; j>low; --j)
		{
			ar[j] = ar[j - 1];
		}
		ar[low] = tmp;
	}
}

void TestSort(int *ar, int left, int right)
{
	InsertSort(ar, left, right);
	InsertSort_1(ar, left, right);
	InsertSort_2(ar, left, right);
	BinInsertSort(ar, left, right);
	PrintArray(ar, left, right);
}

void TestSortEfficiency()
{
	int n = 20000;
	int *a = (int*)malloc(sizeof(int)* n);
	int *a1 = (int*)malloc(sizeof(int)* n);
	int *a2 = (int*)malloc(sizeof(int)* n);
	int *a3 = (int*)malloc(sizeof(int)* n);
	int *a4 = (int*)malloc(sizeof(int)* n);
	int *a5 = (int*)malloc(sizeof(int)* n);
	int *a6 = (int*)malloc(sizeof(int)* n);
	int *a7 = (int*)malloc(sizeof(int)* n);
	int *a8 = (int*)malloc(sizeof(int)* n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
		a6[i] = a[i];
		a7[i] = a[i];
		a8[i] = a[i];
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