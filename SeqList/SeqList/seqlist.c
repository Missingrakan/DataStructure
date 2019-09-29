#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void SeqListInit(SeqList *psl, int sz)
{
	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
	psl->size = 0;
}

void SeqListShow(SeqList *psl)
{
	assert(psl != NULL);
	printf("SeqList:");
	for (size_t i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}

bool SeqListIsFull(SeqList *psl)
{
	assert(psl != NULL);
	return psl->size >= psl->capacity;
}

bool SeqListIsEmpty(SeqList *psl)
{
	assert(psl != NULL);
	return psl->size == 0;
}

bool SeqListPushBack(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if (SeqListIsFull(psl))
	{
		printf("push_back:顺序表已满，%d不能插入!\n",x);
		return false;
	}
	psl->base[psl->size++] = x;
	return true;
}


bool SeqListPushFront(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if (SeqListIsFull(psl))
	{
		printf("push_front:顺序表已满，%d不能插入!\n");
		return false;
	}
	for (size_t i = psl->size; i > 0; i--)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
	return true;
}

bool SeqListPopBack(SeqList *psl)
{
	assert(psl != NULL);
	if (SeqListIsEmpty(psl))
	{
		printf("顺序表已空，无法删除!\n");
		return false;
	}
	psl->size--;
	return true;
}

bool SeqListPopFront(SeqList *psl)
{
	assert(psl != NULL);
	if (SeqListIsEmpty(psl))
	{
		printf("顺序表已空，无法删除!\n");
		return false;
	}
	for (size_t i = 0; i < psl->size -1; i++)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
	return true;
}

size_t SeqListLength(SeqList *psl)
{
	assert(psl != NULL);
	return psl->size;
}

size_t SeqListCapacity(SeqList *psl)
{
	assert(psl != NULL);
	return psl->capacity;
}

bool SeqListInsertByPos(SeqList *psl, int pos, DataType x)
{
	assert(psl != NULL);
	if (SeqListIsFull(psl))
	{
		printf("insert_pos:顺序表已满，%d不能插入!\n", x);
		return false;
	}
	if (pos < 0 || pos > psl->size)
	{
		printf("插入的位置不合法!\n");
		return false;
	}

	for (int i = psl->size; i > pos; i--)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[pos] = x;
	psl->size++;
	return true;
}

bool SeqListInsertByVal(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if (SeqListIsFull(psl))
	{
		printf("insert_val:顺序表已满，%d不能插入!\n", x);
		return false;
	}
	int i = 0;
	for ( i = psl->size - 1; i >= 0 && x < psl->base[i]; i--)
	{
		psl->base[i + 1] = psl->base[i];
	}
	psl->base[i + 1] = x;
	psl->size++;
	return true;
}