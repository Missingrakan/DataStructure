#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define DataType int

typedef struct DListNode
{
	struct DListNode *prev;
	DataType data;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	size_t size;
}DList;

void DListInit(DList *plist);
void DListShow(DList *plist);
bool DListPushBack(DList *plist, DataType x);
bool DListPushFront(DList *plist, DataType x);
bool DListPopBack(DList *plist);
bool DListPopFront(DList *plist);
DListNode* DListFindByVal(DList *plist, DataType key);
bool DListDeleteByVal(DList *plist, DataType key);

size_t DListLength(DList *plist);
void DListClear(DList *plist);
void DListDestroy(DList *plist);
void DListReverse(DList *plist);
void DListInsertByVal(DList *plist, DataType x);
void DListSort(DList *plist);
bool DListModifyByVal(DList *plist, DataType key, DataType x);

#endif /*_DLIST_H_*/