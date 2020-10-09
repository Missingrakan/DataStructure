#include "common.h"

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

DCListNode* _Buynode(DataType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	if (NULL == s)
		return NULL;
	s->data = x;
	s->prev = s->next = NULL;
	return s;
}

void DCListInit(DCList *plist)
{
	DCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListShow(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over!\n");
}

bool DCListPushBack(DCList *plist, DataType x)
{
	DCListNode *p = _Buynode(x);
	if (NULL == p)
		return false;
	plist->last->next = p;
	p->prev = plist->last;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;

	plist->size++;
	return true;
}

bool DCListPushFront(DCList *plist, DataType x)
{
	DCListNode *s = _Buynode(x);
	if (NULL == s)
		return false;
	s->next = plist->first->next;
	s->next->prev = s;
	s->prev = plist->first;
	s->prev->next = s;

	if (plist->size == 0)
		plist->last = s;

	plist->size++;
	return true;
}

bool DCListPopBack(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->last;
	if (plist->size == 0)
		return false;

	plist->last = p->prev;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;

	free(p);
	plist->size--;

	return true;
}

bool DCListPopFront(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->first->next;
	if (plist->size == 0)
		return false;
	p->next->prev = p->prev;
	p->prev->next = p->next;

	if (p == plist->last)
		plist->last = plist->first;
	free(p);

	plist->size--;
	return true;
}

bool DCListInsertByVal(DCList *plist, DataType x)
{
	DCListNode *p;
	DCListNode *s = _Buynode(x);
	if (s == NULL)
		return false;
	p = plist->first->next;
	while (p != plist->last && s->data > p->data)
		p = p->next;

	//ÖµÖØ¸´
	if (s->data == p->data)
	{
		free(s);
		return false;
	}

	s->prev = p->prev;
	s->next = p;
	s->prev->next = s;
	s->next->prev = s;

	if (p == plist->first)
		plist->last = s;
	plist->size++;

	return true;
}

DCListNode* DCListFindByVal(DCList *plist, DataType key)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	if (p == plist->first)
		return NULL;
	return p;
}
bool DCListDeleteByVal(DCList *plist, DataType key)
{
	DCListNode *p = DCListFindByVal(plist, key);
	if (p == NULL)
		return false;

	p->next->prev = p->prev;
	p->prev->next = p->next;

	if (p == plist->last)
		plist->last = plist->first->prev;
	plist->size--;
	return true;
}

void DCListClear(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
}
void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}
void DCListReverse(DCList *plist)
{
	if (plist->size > 1)
	{
		DCListNode *p = plist->first->next;
		DCListNode *q = p->next;

		plist->last = p;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;

		p = q;
		while (p != plist->first)
		{
			q = q->next;
			p->next = plist->first->next;
			p->prev = plist->first;
			p->next->prev = p;
			p->prev->next = p;

			p = q;
		}
	}
}
void DCListSort(DCList *plist)
{
	if (plist->size > 1)
	{
		DCListNode *cur;
		DCListNode *p = plist->first->next;
		DCListNode *q = p->next;

		plist->last = p;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;

		p = q;
		while (p != plist->first)
		{
			q = q->next;
			cur = plist->first->next;
			while (cur != plist->first && p->data > cur->data)
				cur = cur->next;

			p->prev = cur->prev;
			p->next = cur;
			p->next->prev = p;
			p->prev->next = p;

			if (cur == plist->first)
				plist->last = p;

			p = q;
		}
	}
}