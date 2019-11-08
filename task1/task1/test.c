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

//typedef struct node
//{
//	DataType data;
//	struct node *next;
//}LNode;
//
//typedef LNode* SList;
//
//LNode* CreatLinkListByTail();
//LNode* Get_LinkList(LNode* head, int k);
//void LinkListShow(LNode* head);
//
//void SListInit(SList *plist)
//{
//	LNode* s;
//	int  i = 0;
//	*plist = (LNode*)malloc(sizeof(LNode));
//	(*plist)->next = NULL;
//	while (i<=10)
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = 0;
//		s->next = (*plist)->next;
//		(*plist)->next = s;
//		i++;
//	}
//	
//}
//
//void LinkListShow(LNode *head)
//{
//	LNode *p = head->next;
//	if (p == NULL)
//		return;
//	while (p != NULL)
//	{
//		if (p->data != 0)
//			printf("%d->", p->data);
//		p = p->next;
//	}
//	printf("Over!\n");
//}
//
//LNode* CreatLinkListByHead()
//{
//	LNode *s;
//	int x;
//	LNode* head;
//	head = (LNode*)malloc(sizeof(LNode));
//	head->data = 0;
//	head->next = NULL;
//
//	printf("请输入数值(以-1结束)");
//	scanf("%d", &x);
//	while (x != -1)
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = x;
//		s->next = head->next;
//		head->next = s;
//		scanf("%d", &x);
//	}
//
//	return head;
//}
//

//void LinkListSort(LNode* plist)
//{
//	LNode *prev = NULL;
//	LNode *p = plist->next;
//	LNode *q = p->next;
//
//	p = q;
//	while (p != NULL && p->data != 0)
//	{
//		q = q->next;
//		prev = plist->next;
//		while (prev->next != NULL && p->data > prev->data)
//			prev = prev->next;
//
//		//if (prev->next == NULL)
//		//{
//		//	prev->next = p;
//		//	p->next = NULL;
//		//}
//		//else
//		//{
//		//	/*p->next = prev->next;
//		//	prev->next = p;*/
//		//}
//		p = q;
//	}	
//}

//void LinkListDeverse(LNode* plist,LNode* p,LNode *q)
//{
//	if (plist == NULL)
//		return;
//	//while(plist->next == NULL)
//	while (plist != NULL)
//	{
//		if (plist->data % 2 != 0)
//			p->data = plist->data;
//		else
//			q->data = plist->data;
//		plist = plist->next;
//		p = p->next;
//		q = q->next;
//	}
//
//	LinkListSort(p);
//	LinkListSort(q);
//}


//int main()
//{
//	SList plist = NULL;
//	SList listeven = NULL;
//	SList listodd = NULL;
//	SListInit(&listodd);
//	SListInit(&listeven);
//
//	plist = CreatLinkListByHead();
//	printf("plist：");
//	LinkListShow(plist);
//	LinkListDeverse(plist, listodd, listeven);
//	printf("listodd：");
//	LinkListShow(listodd);
//	printf("listeven：");
//	LinkListShow(listeven);
//
//
//	return 0;
//}
//
bool isValid(char * s)
{
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;

	int len = strlen(s);
	char *st = (char*)malloc(sizeof(char)* len);
	int top = 0;

	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			st[top++] = *s;
		}
		else
		{
			if (top == 0)
				return false;

			if ((*s == ')'&&st[top - 1] != '(')
				|| (*s == ']'&&st[top - 1] != '[')
				|| (*s == '}'&&st[top - 1] != '{'))
				return false;
			top--;
		}
		s++;
	}

	bool flag = (top == 0 ? 1 : 0);
	free(st);
	st = NULL;
	return flag;
}


int main()
{
	//char *str = "()[]{}";
	//char *str = "([)]";
	//char *str = "{[]}";
	char str[10] = { 0 };
	scanf("%s", str);

	bool flag = isValid(str);
	if (flag)
		printf("true\n");
	else
		printf("false\n");

}

//typedef struct SeqList
//{
//	DataType *base;
//	size_t capacity;
//	size_t size;
//}SeqList;
//
//void swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void SeqListReverse(SeqList *psl)
//{
//	int begin = 0;
//	int end = psl->size - 1;
//	while (begin < end)
//	{
//		swap(&psl->base[begin], &psl->base[end]);
//		begin++;
//		end--;
//	}
//}
//
//void SeqListInit(SeqList *psl, int sz)
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
//bool SeqListPushBack(SeqList *psl, DataType x)
//{
//	if (psl->size >= psl->capacity)
//	{
//		printf("push_back:顺序表已满，%d不能插入!\n", x);
//		return false;
//	}
//	psl->base[psl->size++] = x;
//	return true;
//}
//
//int main()
//{
//	SeqList mylist;
//	int data = 0;
//	SeqListInit(&mylist, 10);
//	printf("请输入要插入的数据<-1结束>:>");
//	while (scanf("%d", &data), data != -1)
//	{
//		SeqListPushBack(&mylist, data);
//	}
//	SeqListShow(&mylist);
//
//	SeqListReverse(&mylist);
//	SeqListShow(&mylist);
//
//	return 0;
//}

//
//typedef struct SListNode
//{
//	DataType data;
//	struct SListNode *next;
//}SListNode;
//
//typedef struct SList
//{
//	SListNode *first;
//	SListNode *last;
//	size_t    size;
//}SList;
//
//SListNode* _BuyNode(DataType x)
//{
//	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
//	assert(s != NULL);
//	s->next = NULL;
//	s->data = x;
//	return s;
//}
//
//void SListInit(SList *plist)
//{
//	SListNode *s = _BuyNode(0);
//	plist->first = plist->last = s;
//	plist->size = 0;
//}
//
//void SListShow(SList *plist)
//{
//	SListNode *p = plist->first->next;
//	while (p != NULL)
//	{
//		printf("%d-->", p->data);
//		p = p->next;
//	}
//	printf("over.\n");
//}
//
//void SListReverse(SList *plist)
//{
//	SListNode *p = plist->first->next;
//	SListNode *q = p->next;
//	plist->last = p;
//	plist->last->next = NULL;
//	p = q;
//	while (p != NULL)
//	{
//		q = p->next;
//		p->next = plist->first->next;
//		plist->first->next = p;
//		p = q;
//	}
//}
//
//bool SListPushBack(SList *plist, DataType x)
//{
//	assert(plist != NULL);
//	SListNode * s = _BuyNode(x);
//	if (s == NULL)
//		return false;
//	plist->last->next = s;
//	plist->last = s;
//	plist->size++;
//	return true;
//}
//
//int main()
//{
//	SList mylist;
//	int item = 0;
//	SListInit(&mylist);
//
//	printf("请输入要插入的数据<-1结束>:>");
//	while (scanf("%d", &item), item != -1)
//	{
//		SListPushBack(&mylist, item);
//	}
//	SListShow(&mylist);
//
//	SListReverse(&mylist);
//	SListShow(&mylist);
//
//	return 0;
//}