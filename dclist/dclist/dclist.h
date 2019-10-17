#ifndef _DCLIST_H_
#define _DCLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define DataType int

typedef struct DCListNode
{
	DataType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;

typedef struct DCList
{
	DCListNode *first;
	DCListNode *last;
	size_t size;
}DCList;

void DCListInit(DCList *plist);
void DCListShow(DCList *plist);
bool DCListPushBack(DCList *plist, DataType x);
bool DCListPushFront(DCList *plist, DataType x);
bool DCListPopBack(DCList *plist);
bool DCListPopFront(DCList *plist);
bool DCListInsertByVal(DCList *plist, DataType x);
DCListNode* DCListFindByVal(DCList *plist, DataType key);
bool DCListDeleteByVal(DCList *plist, DataType key);
void DCListClear(DCList *plist);
void DCListDestroy(DCList *plist);
void DCListReverse(DCList *plist);
void DCListSort(DCList *plist);


#endif /*_DCLIST_H_*/