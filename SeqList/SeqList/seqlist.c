#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

bool _SeqListInc(SeqList *psl)
{
	assert(psl != NULL);
	psl->base = (DataType *)realloc(psl->base, sizeof(DataType)*(psl->capacity + SEQLIST_INC_SIZE));
	if (psl->base == NULL)
		return false;
	psl->capacity += SEQLIST_INC_SIZE;
	printf("增容成功!");
	return true;
}


void swap(DataType *elem1, DataType *elem2)
{
	DataType tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

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
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
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
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
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
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
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
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
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

bool SeqListFindByPos(SeqList *psl, int pos, DataType *ret)
{
	assert(psl != NULL);
	if (pos<0 || pos > psl->size - 1)
	{
		printf("要查找的位置不合法!\n");
		return false;
	}
	*ret = psl->base[pos];
	return true;
}

int SeqListFindByVal(SeqList *psl, DataType key)
{
	assert(psl != NULL);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->base[i] == key)
			return i;
	}
	return -1;
}

bool SeqListDeleteByPos(SeqList *psl, int pos)
{
	assert(psl != NULL);
	if (pos < 0 || pos > psl->size - 1)
	{
		printf("要删除的位置不合法!\n");
		return false;
	}
	for (int i = pos; i < psl->size-1; i++)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
	return true;
}

bool SeqListDeleteByVal(SeqList *psl, DataType key)
{
	assert(psl != NULL);
	int index = SeqListFindByVal(psl,key);
	if (index == -1)
	{
		printf("要删除的数据不存在!\n");
		return false;
	}
	return SeqListDeleteByPos(psl, index);
}

bool SeqListModifyByPos(SeqList *psl, int pos, DataType x)
{
	assert(psl != NULL);
	if (pos < 0 || pos > psl->size - 1)
	{
		printf("要修改的位置不合法!\n");
		return false;
	}
	psl->base[pos] = x;
	return true;

}

bool SeqListModifyByVal(SeqList *psl, DataType key, DataType x)
{
	assert(psl != NULL);
	int index = SeqListFindByVal(psl, key);
	if (index == -1)
	{
		printf("要修改的数据不存在!\n");
		return false;
	}
	psl->base[index] = x;
	return true;
}

void SeqListSort(SeqList *psl)
{
	for (int i = 0; i < psl->size; i++)
	{
		for (int j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->base[j] > psl->base[j + 1])
			{
				swap(&psl->base[j], &psl->base[j + 1]);
			}
		}
	}
}

void SeqListReverse(SeqList *psl)
{
	assert(psl != NULL);
	int begin = 0;
	int end = psl->size - 1;
	while (begin < end)
	{
		swap(&psl->base[begin], &psl->base[end]);
		begin++;
		end--;
	}
}

void SeqListClear(SeqList *psl)
{
	assert(psl != NULL);
	psl->size = 0;
}

void SeqListDestroy(SeqList *psl)
{
	free(psl->base);
	psl->base = NULL;
	psl->capacity = psl->size = 0;
}