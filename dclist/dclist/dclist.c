#define _CRT_SECURE_NO_WARNINGS 1

#include "dclist.h"

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
	plist->last->next  = plist->first;
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
	DCListNode *p = plist->first->next;
	DCListNode *s = _Buynode(x);
	if (s == NULL)
		return false;
	while (p != plist->first && s->data > p->data)
		p = p->next;

	//值重复
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
	/*
	//插入节点为第一个节点或最后一个节点
	if (p == plist->first)
	{
		s->prev = plist->last;
		plist->last->next = s;
		plist->last = s;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		plist->size++;
		return true;
	}
	//在p之前插入节点
	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
	plist->size++;
	*/
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
	if (NULL == p)
		return false;

	p->next->prev = p->prev;
	p->prev->next = p->next;

	if (p == plist->last)
		plist->last = plist->first;
	free(p);
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
		DCListNode *cur;		//cur指针始终指向第一个真实节点
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


