#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define DataType int
#define SEQLIST_DEFAULT_SIZE 6

//typedef struct SeqList
//{
//	DataType *base;
//	size_t capacity;
//	size_t size;
//}SeqList;
//
//void swap(DataType *elem1, DataType *elem2)
//{
//	DataType tmp = *elem1;
//	*elem1 = *elem2;
//	*elem2 = tmp;
//}
// 
//
//void SeqListReverse(SeqList *psl)
//{
//	int begin = 0;
//	int end = psl->size - 1;
//	while (begin < end)
//	{
//		swap(psl->base[begin], psl->base[end]);
//		begin++;
//		end--;
//	}
//}
//
//void SeqListInit(SeqList *psl,int sz)
//{
//	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
//	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
//	psl->size = 0;
//}
//
//void SeqListShow(SeqList *psl)
//{
//	printf("SeqList:");
//	for (size_t i = 0; i < psl->size; i++)
//	{
//		printf("%d ", psl->base[i]);
//	}
//	printf("\n");
//}
//
//int SeqListIsFull(SeqList *psl)
//{
//	return psl->size >= psl->capacity;
//}
//
//int SeqListPushBack(SeqList *psl, DataType x)
//{
//	if (SeqListIsFull(psl))
//	{
//		printf("push_back:顺序表已满，%d不能插入!\n", x);
//		return -1;
//	}
//	psl->base[psl->size++] = x;
//	return 1;
//}
//
//int main()
//{
//	SeqList mylist;
//	SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);
//
//}


//void main()
//{
//	int a = 0;
//	char c = 0;
//	scanf("%3d,%3c",&a,&c);
//	printf("%d,%c",a, c);
//}


#define DataType int

typedef struct node
{
	DataType data;
	struct node *next;
}LNode;

typedef LNode* SList;

LNode* CreatLinkListByTail();
LNode* Get_LinkList(LNode* head, int k);
void LinkListShow(LNode* head);

void SListInit(SList *plist)
{
	LNode* s;
	int  i = 0;
	*plist = (LNode*)malloc(sizeof(LNode));
	(*plist)->next = NULL;
	while (i<=10)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = 0;
		s->next = (*plist)->next;
		(*plist)->next = s;
		i++;
	}
	
}

void LinkListShow(LNode *head)
{
	LNode *p = head->next;
	if (p == NULL)
		return;
	while (p != NULL)
	{
		if (p->data != 0)
			printf("%d->", p->data);
		p = p->next;
	}
	printf("Over!\n");
}

LNode* CreatLinkListByHead()
{
	LNode *s;
	int x;
	LNode* head;
	head = (LNode*)malloc(sizeof(LNode));
	head->data = 0;
	head->next = NULL;

	printf("请输入数值(以-1结束)");
	scanf("%d", &x);
	while (x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = head->next;
		head->next = s;
		scanf("%d", &x);
	}

	return head;
}

//void LinkListSort(LNode* plist)
//{
//
//}

void LinkListDeverse(LNode* plist,LNode* listodd,LNode *listeven)
{
	if (plist == NULL)
		return;
	//while(plist->next == NULL)
	while (plist != NULL)
	{
		if (plist->data % 2 != 0)
			listodd->data = plist->data;
		else
			listeven->data = plist->data;
		plist = plist->next;
		listodd = listodd->next;
		listeven = listeven->next;
	}
	/*LinkListSort(listodd);
	LinkListSort(listeven);*/
}


int main()
{
	LNode *plist = NULL;
	LNode *listeven = NULL;
	LNode *listodd = NULL;
	SListInit(&listodd);
	SListInit(&listeven);

	plist = CreatLinkListByHead();
	printf("plist：");
	LinkListShow(plist);
	LinkListDeverse(plist, listodd, listeven);
	printf("listodd：");
	LinkListShow(listodd);
	printf("listeven：");
	LinkListShow(listeven);


	return 0;
}