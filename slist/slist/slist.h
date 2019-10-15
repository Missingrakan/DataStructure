#ifndef _SLIST_H_
#define _SLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>

#define DataType int

//typedef struct Node
//{
//	DataType data;
//	struct Node* next;
//}Node;
//
//typedef Node* List;
//
//void InitList(List *head);
//void CreateList_Tail(List *head);
//void ShowList(List head);

typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t    size;
}SList;

void SListInit(SList *plist);
void SListShow(SList *plist);
bool SListPushBack(SList *plist, DataType x);
bool SListPushFront(SList *plist, DataType x);
bool SListPopBack(SList *plist);
bool SListPopFront(SList *plist);
SListNode* SListFindByVal(SList *plist, DataType key);
bool SListDeleteByVal(SList *plist, DataType key);

size_t SListLength(SList *plist);
void SListClear(SList *plist);
void SListDestroy(SList *plist);
void SListReverse(SList *plist);
void SListInsertByVal(SList *plist,DataType x);
void SListSort(SList *plist);
bool SListModifyByVal(SList *plist,DataType key, DataType x);



#endif