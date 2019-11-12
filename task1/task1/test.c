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
//bool isValid(char * s)
//{
//	if (s == NULL)
//		return false;
//	if (*s == '\0')
//		return true;
//
//	int len = strlen(s);
//	char *st = (char*)malloc(sizeof(char)* len);
//	int top = 0;
//
//	while (*s != '\0')
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			st[top++] = *s;
//		}
//		else
//		{
//			if (top == 0)
//				return false;
//
//			if ((*s == ')'&&st[top - 1] != '(')
//				|| (*s == ']'&&st[top - 1] != '[')
//				|| (*s == '}'&&st[top - 1] != '{'))
//				return false;
//			top--;
//		}
//		s++;
//	}
//
//	bool flag = (top == 0 ? 1 : 0);
//	free(st);
//	st = NULL;
//	return flag;
//}
//
//
//int main()
//{
//	//char *str = "()[]{}";
//	//char *str = "([)]";
//	//char *str = "{[]}";
//	char str[10] = { 0 };
//	scanf("%s", str);
//
//	bool flag = isValid(str);
//	if (flag)
//		printf("true\n");
//	else
//		printf("false\n");
//
//}

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


//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，
//每个桶能放3个整数，当一个桶中要放的元素超过3个时，
//则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。此Hash表的基桶数目为素数P，
//Hash表的hash函数对P取模。代码定义如下：

#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};
struct bucket_node hash_table[P];

//现在假设hash_table已经初始化好了，
//insert_new_element()函数目的是把一个新的值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

//int Hash(int key)
//{
//	return (key % P);
//}
//
//int insert_new_element(int new_element)
//{
//	int index = Hash(new_element);
//	
//	
//}
//
//void Init_bucket_node(struct bucket_node *pht, int null_data)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		pht->data[i] = null_data;
//	}
//	pht->next = NULL;
//}
//
//////////////////////////////////////////////////
//int main()
//{
//	Init_bucket_node(&hash_table, NULL_DATA); //
//	int array[] = { 15, 14, 21, 87, 96, 293, 35, 24, 149, 19, 63, 16, 103, 77, 5, 153, 145, 356, 51, 68, 705, 453 };
//	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
//	{
//		Insert_new_element(array[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node
//{
//	float coef;
//	int exp;
//	struct node *next;
//}nodetype, *polyty;
//
///*以尾插法创建有m项的多项式单链表*/
//polyty CreatePolyn(int m)
//{
//	polyty head = (nodetype*)malloc(sizeof(nodetype));
//	head->next = NULL;
//	nodetype *r = head;//初始化
//	nodetype *pa = NULL;
//	int k = 0;
//	float coef = 0;
//	int exp = 0;
//	for (k = 0; k < m; k++)
//	{
//		printf("输入系数指数:>");
//		scanf("%f,%d", &coef, &exp);//输入系数指数
//		pa = (nodetype*)malloc(sizeof(nodetype));//申请空间
//		//构造节点
//		pa->coef = coef;
//		pa->exp = exp;
//		//插入节点
//		r->next = pa;
//		r = pa;
//	}
//	r->next = NULL;
//	return head;
//}
//
////输出多项式
//
//void PrintPolyn(polyty head,char *str)
//{
//	nodetype *pt = head->next;
//	printf("\n The polynomial is: \n");
//	printf("%s = ", str);
//	while (pt != NULL)
//	{
//		if (pt->exp > 1)
//			printf("%.2fX^%d", pt->coef, pt->exp);
//		else if (pt->exp == 1)
//			printf("%.2fX", pt->coef);
//		else
//			printf("%.2f", pt->coef);
//		if (pt->next != NULL)
//			printf("+");
//		pt = pt->next;
//	}
//	printf("\n");
//}
//
//void AddPolyn(polyty la, polyty lb)
//{
//	nodetype *a = la->next;
//	nodetype *b = lb->next;
//	nodetype *c = la;
//	nodetype *temp = NULL;
//	float sum = 0.0;
//
//	while (a != NULL && b != NULL)
//	{
//		if (a->exp < b->exp)
//		{
//			c->next = a;
//			c = a;
//			a = a->next;
//		}
//		else if (a->exp == b->exp)
//		{
//			sum = a->coef + b->coef;
//			//和系数不为0，则修改多项式a的该项系数，
//			//将la的节点加入多项式，释放lb中该项的结点
//			if (sum != 0)
//			{
//				a->coef = sum;
//				c->next = a;
//				c = a;
//				a = a->next;
//				temp = b;
//				b = b->next;
//				free(temp);
//				temp = NULL;
//			}
//			//和系数为0，则将 la，lb中表示该项的节点都删除掉
//			else
//			{
//				temp = a;
//				a = a->next;
//				free(temp);
//				temp = b;
//				b = b->next;
//				free(temp);
//				temp = NULL;
//			}
//		}
//		else
//		{
//			c->next = b;
//			c = b;
//			b = b->next;
//		}
//	}
//	/*多项式A中还有剩余，则将剩余的结点加入到和多项式；
//	否则加入B的节点*/
//	if (a != NULL)
//		c->next = a;
//	else
//		c->next = b;
//}
//
//int main()
//{
//	int m = 0;
//	printf("创建有m项的多项式:>");
//	scanf("%d", &m);
//	polyty psla = CreatePolyn(m);   //创建多项式a
//	PrintPolyn(psla,"pa");
//	polyty pslb = CreatePolyn(m);   //创建多项式b
//	PrintPolyn(pslb,"pb");
//	AddPolyn(psla, pslb);
//	PrintPolyn(psla,"pa+pb");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

#define DataType int

typedef struct node
{
	DataType data;
	struct node *next;
}LNode;


LNode* CreatLLinkListByHead();
LNode* CreatLinkListByTail();
int Insert_LinkList_pos(LNode* head, int i, DataType x);
LNode* Get_LinkList(LNode* head, int k);
int Del_LinkList(LNode* head, int i);
void LinkListShow(LNode* head);

void LinkListShow(LNode* head)
{
	LNode *p = head->next;
	if (p == NULL)
		return;
	while (p != NULL)
	{
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

LNode* CreatLinkListByTail()
{
	LNode *s;
	LNode *tail;
	int x = 0;
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	tail = head;

	printf("请输入数值(以-1结束)");
	scanf("%d", &x);
	while (x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		tail->next = s;
		tail = s;
		scanf("%d", &x);
	}
	tail->next = NULL;
	return head;
}

LNode* Get_LinkList(LNode* head, int k)
{
	LNode *p = head;
	int j = 0;
	while ((p->next != NULL) && (j < k))
	{
		p = p->next;
		j++;
	}
	if (j == k)
		return p;
	else
		return NULL;
}

int Insert_LinkList_pos(LNode* head, int i, DataType x)
{
	LNode *p, *s;
	p = Get_LinkList(head, i - 1);       //查找第i-1个节点
	if (p == NULL)
	{
		printf("插入位置i错误!\n");
		return 0;
	}
	else
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}

int Del_LinkList(LNode* head, int i)
{
	LNode* p;
	LNode* q;
	p = Get_LinkList(head, i - 1);
	if (p == NULL)
	{
		printf("第i-1个结点不存在!\n");
		return 0;
	}
	else if (p->next == NULL)
	{
		printf("第i个结点不存在!\n");
		return 0;
	}
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		return 1;
	}

}

void menu()
{
	printf("****************************************************\n");
	printf("******1.CreatLinkListByHead  0.exit           ******\n");
	printf("******2.CreatLinkListByTail  3.Insert_LinkList******\n");
	printf("******4.Del_LinkList         5.	LinkListShow  ******\n");
	printf("****************************************************\n");
}

//LinkList CreatLinkListByHead();
//LinkList CreatLinkListByTail();
//int Insert_LinkList(LinkList head, int i, DataType x);
//LinkList Get_LinkList(LinkList head, int k);
//int Del_LinkList(LinkList head, int i);
int main()
{
	int select = 0;
	LNode* head1 = NULL;
	LNode* head2 = NULL;
	int n = 0;

	int pos = 0;
	int key = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			head1 = CreatLinkListByHead();
			LinkListShow(head1);
			break;
		case 2:
			head2 = CreatLinkListByTail();
			LinkListShow(head2);
			break;
		case 3:
			printf("请输入要插入的链表(1 或 2):>");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("请输入要插入的位置:>");
				scanf("%d", &pos);
				printf("请输入要插入的值:>");
				scanf("%d", &key);
				Insert_LinkList_pos(head1, pos, key);
				LinkListShow(head1);
			}
			else if (n == 2)
			{
				printf("请输入要插入的位置:>");
				scanf("%d", &pos);
				printf("请输入要插入的值:>");
				scanf("%d", &key);
				Insert_LinkList_pos(head2, pos, key);
				LinkListShow(head2);
			}
			else
				printf("输入错误\n");
			break;
		case 4:
			printf("请输入要删除的链表(1 或 2):>");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("请输入要删除的位置:>");
				scanf("%d", &pos);
				Del_LinkList(head1, pos);
				LinkListShow(head1);
			}
			else if (n == 2)
			{
				printf("请输入要删除的位置:>");
				scanf("%d", &pos);
				Del_LinkList(head2, pos);
				LinkListShow(head2);
			}
			else
				printf("输入错误\n");
			break;
		case 5:
			printf("请输入要显示的链表(1 或 2):>");
			scanf("%d", &n);
			if (n == 1)
			{
				LinkListShow(head1);
			}
			else if (n == 2)
			{
				LinkListShow(head2);
			}
			else
				printf("输入错误\n");
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default:
			printf("选择错误，请重新输入!\n");
			break;

		}
	} while (select);
	return 0;
}