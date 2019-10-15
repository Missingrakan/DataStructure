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

size_t SCListLength(SCList *plist)
{
	return plist->size;
}