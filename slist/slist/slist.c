#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"
//void InitList(List *head)
//{
//	head = NULL;
//}
//
//void CreateList_Tail(List *head)
//{
//	assert(head != NULL);
//	*head = (Node*)malloc(sizeof(Node));
//	(*head)->data = 1;
//	(*head)->next = NULL;
//
//	Node *p = *head;
//	for (int i = 2; i <= 10; i++)
//	{
//		Node *s = (Node*)malloc(sizeof(Node));
//		assert(s != NULL);
//		s->data = i;
//		s->next = NULL;
//
//		p->next = s;
//		p = s;
//	}
//}

SListNode* _BuyNode(DataType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->next = NULL;
	s->data = x;
	return s;
}

void SListInit(SList *plist)
{
	SListNode *s = _BuyNode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

void SListShow(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}

bool SListPushBack(SList *plist, DataType x)
{
	assert(plist != NULL);
	SListNode * s = _BuyNode(x);
	if (s == NULL)
		return false;
	plist->last->next = s;
	plist->last = s;
	plist->size++;
	return true;
}

bool SListPushFront(SList *plist, DataType x)
{
	assert(plist != NULL);
	SListNode *s = _BuyNode(x);
	if (s == NULL)
		return false;
	s->next = plist->first->next;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
	return true;
}

bool SListPopFront(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->first;
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

bool SListPopBack(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->first;
	if (plist->size == 0)
		return false;
	while (p->next != plist->last)
		p = p->next;

	p->next = NULL;
	free(plist->last);
	plist->last = p;
	plist->size--;
	return true;
}

SListNode* SListFindByVal(SList *plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p = plist->first->next;
	while (p!=NULL && p->data!=key)
		p = p->next;
	return p;
}

bool SListDeleteByVal(SList *plist, DataType key)
{
	assert(plist != NULL);
	SListNode *q = NULL;
	SListNode *p = plist->first;
	while ((p->next != NULL) && (p->next->data != key))
		p = p->next;
	if (p->next == NULL)
		return false;

	q = p->next; 
	if (p->next == plist->last)
		plist->last = p;
	p->next = q->next;
	free(q);
	plist->size--;
	return true;
}

size_t SListLength(SList *plist)
{
	return plist->size;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

void SListReverse(SList *plist)
{
	SListNode *p = plist->first->next;
	SListNode *q = p->next;
	plist->last = p;
	plist->last->next = NULL;
	p = q;
	while(p != NULL)
	{
		q = p->next;
		p->next = plist->first->next;
		plist->first->next = p;
		p = q;
	}
}

//void SListReverse(SList *plist)
//{
//	if (plist->size > 1)
//	{
//		SListNode * p1 = NULL;
//		SListNode * p2 = plist->first->next;
//		SListNode * p3 = p2->next;
//		plist->last = p2;
//		while (p2 != NULL)
//		{
//			p2->next = p1;
//			p1 = p2;
//			p2 = p3;
//			if (p3 != NULL)
//				p3 = p3->next;
//		}
//		plist->first->next = p1;
//	}
//}

void SListInsertByVal(SList *plist,DataType x)
{
	SListNode *p = plist->first;
	while ((p->next != NULL) && (x > p->next->data))
		p = p->next;

	SListNode *s = _BuyNode(x);
	if (p->next == NULL)
	{
		p->next = s;
		plist->last = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	plist->size++;
}

void SListSort(SList *plist)
{
	if (plist->size > 1)
	{
		SListNode *prev = NULL;
		SListNode *p = plist->first->next;
		SListNode *q = p->next;
		plist->last = p;
		plist->last->next = NULL;

		p = q;
		while (p != NULL)
		{
			q = q->next;
			prev = plist->first;
			while (prev->next != NULL && p->data>prev->next->data)
				prev = prev->next;

			if (prev->next == NULL)
			{
				prev->next = p;
				plist->last = p;
				p->next = NULL;
			}
			else
			{
				p->next = prev->next;
				prev->next = p;
			}
			p = q;
		}
	}
}

bool SListModifyByVal(SList *plist, DataType key, DataType x)
{
	assert(plist != NULL);
	SListNode* p = SListFindByVal(plist, key);
	if (p == NULL)
	{
		printf("要修改的数据不存在!\n");
		return false;
	}
	p->data = x;
	return true;

}