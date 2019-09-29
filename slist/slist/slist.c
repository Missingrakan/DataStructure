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
	while (p != plist->last)
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
	SListNode *ret = SListFindByVal(plist, key);
	if (ret == NULL)
		return false;
	ret->next;

}
