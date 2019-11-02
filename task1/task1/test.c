#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define DataType int
#define SEQLIST_DEFAULT_SIZE 6

typedef struct SeqList
{
	DataType *base;
	size_t capacity;
	size_t size;
}SeqList;

void swap(DataType *elem1, DataType *elem2)
{
	DataType tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}
 

void SeqListReverse(SeqList *psl)
{
	int begin = 0;
	int end = psl->size - 1;
	while (begin < end)
	{
		swap(psl->base[begin], psl->base[end]);
		begin++;
		end--;
	}
}

void SeqListInit(SeqList *psl,int sz)
{
	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
	psl->size = 0;
}

void SeqListShow(SeqList *psl)
{
	printf("SeqList:");
	for (size_t i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}

int SeqListIsFull(SeqList *psl)
{
	return psl->size >= psl->capacity;
}

int SeqListPushBack(SeqList *psl, DataType x)
{
	if (SeqListIsFull(psl))
	{
		printf("push_back:顺序表已满，%d不能插入!\n", x);
		return -1;
	}
	psl->base[psl->size++] = x;
	return 1;
}

int main()
{
	SeqList mylist;
	SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);

}