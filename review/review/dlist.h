#include "common.h"

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
bool DListPopFront(DList plist);
DListNode* DListFindByVal(DList *plist, DataType key);
bool DListDeleteByVal(DList *plist, DataType key);

size_t DListLength(DList *plist);
void DListClear(DList *plist);
void DListDestroy(DList *plist);
void DListReverse(DList *plist);
void DListInsertByVal(DList *plist, DataType x);
void DListSort(DList *plist);
bool DListModifyByVal(DList *plist, DataType key, DataType x);
DListNode* _Buynode(DataType x)
{
	DListNode *s = (DListNode*)malloc(sizeof(DListNode));
	if (NULL == s)
		return NULL;
	s->data = x;
	s->next = s->prev = NULL;
	return s;
}

void DListInit(DList *plist)
{
	DListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

void DListShow(DList *plist)
{
	DListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over!\n");
}

bool DListPushBack(DList *plist, DataType x)
{
	DListNode *s = _Buynode(x);
	if (NULL == s)
		return false;
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;

	plist->size++;
	return true;
}

bool DListPushFront(DList *plist, DataType x)
{
	assert(plist != NULL);

	DListNode *s = _Buynode(x);
	if (NULL == s)
		return false;
	s->next = plist->first->next;
	if (s->next != NULL)
		s->next->prev = s;
	s->prev = plist->first;
	s->prev->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
	return true;
}

DListNode* DListFindByVal(DList *plist, DataType key)
{
	assert(plist != NULL);
	DListNode *p = plist->first->next;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

bool DListDeleteByVal(DList *plist, DataType key)
{
	assert(plist != NULL);
	DListNode *p = DListFindByVal(plist, key);
	if (NULL == p)
		return false;
	if (p = plist->last)
		plist->last = p->prev;
	p->prev->next = p->next;
	if (p->next != NULL)
		p->next->prev = p->prev;

	free(p);

	plist->size--;
	return true;

}