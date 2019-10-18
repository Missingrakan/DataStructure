#define _CRT_SECURE_NO_WARNINGS 1

#include "sclist.h"

SCListNode* _BuyNode(DataType x)
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
	SCListNode *p = _BuyNode(0);
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
	printf("Over!\n");
}

bool SCListPushBack(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode *p = _BuyNode(x);
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
	SCListNode *p = _BuyNode(x);
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
/*
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
}*/

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