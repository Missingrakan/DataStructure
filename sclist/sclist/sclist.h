#ifndef _SCLIST_H_
#define _SCLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>

#define DataType int

typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next;
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t    size;
}SCList;

void SCListInit(SCList *plist);
void SCListShow(SCList *plist);
bool SCListPushBack(SCList *plist, DataType x);
bool SCListPushFront(SCList *plist, DataType x);
bool SCListPopBack(SCList *plist);
bool SCListPopFront(SCList *plist);
SCListNode* SCListFindByVal(SCList *plist, DataType key);
bool SCListDeleteByVal(SCList *plist, DataType key);

size_t SCListLength(SCList *plist);
void SCListClear(SCList *plist);
void SCListDestroy(SCList *plist);
void SCListReverse(SCList *plist);
void SCListInsertByVal(SCList *plist, DataType x);
void SCListSort(SCList *plist);
bool SCListModifyByVal(SCList *plist, DataType key, DataType x);


#endif