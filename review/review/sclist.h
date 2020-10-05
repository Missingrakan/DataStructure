#include "common.h"

typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next;
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t size;
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

SCListNode *_Buynode(DataType x)
{
	SCListNode *s = (SCListNode*)malloc(sizeof(SCListNode));
	if (s == NULL)
		return NULL;
	s->next = NULL;
	s->data = x;
	return s;
}

void SCListInit(SCList *plist)
{
	SCListNode *p = _Buynode(0);
	plist->first = plist->last = p;
	plist->last->next = plist->first;
	plist->size = 0;
}
void SCListShow(SCList *plist)
{
	SCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
bool SCListPushBack(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode *p = _Buynode(x);
	if (p == NULL)
		return false;

	plist->last->next = p;
	plist->last = p;
	plist->last->next = plist->first;

	plist->size++;
	return true;
}
bool SCListPushFront(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode *p = _Buynode(x);
	if (p == NULL)
		return false;
	p->next = plist->first->next;
	plist->first->next = p;
	if (plist->size == 0)
	{
		plist->last = p;
		plist->last->next = plist->first;
	}
	plist->size++;
	return true;
}
bool SCListPopBack(SCList *plist)
{
	assert(plist != NULL);
	SCListNode *p = plist->first;
	if (plist->size == 0)
		return false;

	while (p->next != plist->last)
		p = p->next;

	p->next = plist->first;
	free(plist->last);
	plist->last = p;
	plist->size--;
	return true;
}
bool SCListPopFront(SCList *plist)
{
	assert(plist != NULL);
	SCListNode *p = plist->first;
	if (plist->size == 0)
		return false;
	p = plist->first->next;
	plist->first->next = p->next;
	free(p);
	plist->size--;
	if (plist->size == 0)
		plist->last = plist->first;
	return true;

}

SCListNode* SCListFindByVal(SCList *plist, DataType key)
{
	assert(plist != NULL);
	SCListNode *p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	return p;
}

bool SCListDeleteByVal(SCList *plist, DataType key)
{
	assert(plist != NULL);
	SCListNode *q = NULL;
	SCListNode *p = plist->first;
	while (p->next != plist->first && p->next->data != key)
		p = p->next;
	if (p->next == plist->first)
		return false;

	q = p->next;
	if (p->next == plist->last)
		plist->last = p;
	p->next = q->next;
	free(q);
	plist->size--;
	return true;
}

size_t SCListLength(SCList *plist)
{
	return plist->size;
}

void SCListClear(SCList *plist)
{
	SCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void SCListDestroy(SCList *plist)
{
	SCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}
void SCListReverse(SCList *plist)
{
	if (plist->size > 1)
	{
		SCListNode *p = plist->first->next;
		SCListNode *q = p->next;
		plist->last = p;
		plist->last->next = plist->first;

		p = q;
		while (p != plist->first)
		{
			q = p->next;
			p->next = plist->first->next;
			plist->first->next = p;
			p = q;
		}
	}
}

//void SCListReverse(SCList *plist)
//{
//	if (plist->size > 1)
//	{
//		SCListNode *p1 = NULL;
//		SCListNode *p2 = plist->first->next;
//		SCListNode *p3 = p2->next;
//		plist->last = p2;
//		while (p2 != plist->first)
//		{
//			p2->next = p1;
//			p1 = p2;
//			p2 = p3;
//			if (p3 != plist->first)
//				p3 = p3->next;
//		}
//		plist->first->next = p1;
//	}
//}