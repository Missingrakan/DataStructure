#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define DataType int
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 5

typedef struct SeqList
{
	DataType *base;
	size_t capacity;
	size_t size;
}SeqList;

void SeqListInit(SeqList *psl,int sz);
void SeqListShow(SeqList *psl);
bool SeqListPushBack(SeqList *psl, DataType x);
bool SeqListPushFront(SeqList *psl, DataType x);
bool SeqListPopBack(SeqList *psl);
bool SeqListPopFront(SeqList *psl);
bool SeqListInsertByPos(SeqList *psl, int pos, DataType x);
bool SeqListInsertByVal(SeqList *psl, DataType x);
size_t SeqListLength(SeqList *psl);
size_t SeqListCapacity(SeqList *psl);

void SeqListClear(SeqList *psl);
void SeqListDestroy(SeqList *psl);

bool SeqListFindByPos(SeqList *psl, int pos, DataType *ret);
int SeqListFindByVal(SeqList *psl, DataType key);

bool SeqListDeleteByPos(SeqList *psl, int pos);
bool SeqListDeleteByVal(SeqList *psl, DataType key);
bool SeqListModifyByPos(SeqList *psl,int pos,DataType x);
bool SeqListModifyByVal(SeqList *psl,DataType key,DataType x);

void SeqListSort(SeqList *psl);
void SeqListReverse(SeqList *psl);

#endif