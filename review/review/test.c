#define _CRT_SECURE_NO_WARNINGS 1

//#include "Bintree.h"
//#include "slist.h"
//#include "sclist.h"
//#include "dclist.h"
//#include "seqlist.h"
//#include "stack.h"
//#include "queue.h"
//#include "heap.h"
#include "bst.h"

int main()
{
	BSTree bst;
	int i;
	int j = 0;
	int ar[] = { 45, 10, 24, 53, 12, 38, 21, 90, 30 };
	int n = sizeof(ar) / sizeof(int);
	BSTreeInit(&bst);

	for (i = 0; i<n; ++i)
	{
		Insert(&bst, ar[i]);
	}

	printf("Min = %d\n", Min(bst));
	printf("Max = %d\n", Max(bst));

	Remove(&bst, 45);

	return 0;

	//BSTree bst;
	//int i;
	//int j = 0;
	//int ar[] = { 45, 10, 24, 53, 12, 38, 21, 90, 30 };
	//int n = sizeof(ar) / sizeof(int);
	//BSTreeInit(&bst);

	//for (i = 0; i<n; ++i)
	//{
	//	Insert(&bst, ar[i]);
	//}

	//Sort(bst, ar, &j);

	return 0;
}

//void main()
//{
//	int ar[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	int n = sizeof(ar) / sizeof(int);
//	Heap hp;
//	int i;
//	HeapInit(&hp, n);
//
//	for (i = 0; i<n; ++i)
//	{
//		HeapInsert(&hp, ar[i]);
//	}
//
//	HeapShow(&hp);
//
//	HeapRemove(&hp);
//	HeapShow(&hp);
//
//	HeapRemove(&hp);
//	HeapShow(&hp);
//
//	HeapDestroy(&hp);
//}

//int main()
//{
//	LinkQueue LQ;
//	LinkQueueInit(&LQ);
//	LinkQueueEn(&LQ, 1);
//	LinkQueueEn(&LQ, 2);
//	LinkQueueEn(&LQ, 3);
//	LinkQueueEn(&LQ, 4);
//	LinkQueueEn(&LQ, 5);
//
//	LinkQueueShow(&LQ);
//
//	LinkQueueDestroy(&LQ);
//
//	//SeqCyQueue CQ;
//	//SeqQueueCyInit(&CQ, 8);
//	//SeqQueueCyEn(&CQ, 1);
//	//SeqQueueCyEn(&CQ, 2);
//	//SeqQueueCyEn(&CQ, 3);
//	//SeqQueueCyEn(&CQ, 4);
//	//SeqQueueCyEn(&CQ, 5);
//
//	//SeqQueueCyShow(&CQ);
//	//SeqQueueCyDe(&CQ);
//	//SeqQueueCyDe(&CQ);
//	//SeqQueueCyShow(&CQ);
//
//	//SeqQueueCyEn(&CQ, 6);
//	//SeqQueueCyEn(&CQ, 7);
//	//SeqQueueCyEn(&CQ, 8);
//	//SeqQueueCyEn(&CQ, 9);
//
//	//SeqQueueCyShow(&CQ);
//
//	//SeqQueueCyEn(&CQ, 19);
//
//	//SeqQueue Q;
//	//SeqQueueInit(&Q, DEFAULT_QUEUE_SIZE);
//	//SeqQueueEn(&Q, 1); 
//	//SeqQueueEn(&Q, 2);
//	//SeqQueueEn(&Q, 3);
//	//SeqQueueEn(&Q, 4);
//	//SeqQueueEn(&Q, 5);
//	//SeqQueueShow(&Q);
//
//	//SeqQueueDe(&Q);
//	//SeqQueueDe(&Q);
//
//	//SeqQueueShow(&Q);
//
//	//SeqQueueEn(&Q, 6);
//	//SeqQueueEn(&Q, 7);
//	//SeqQueueEn(&Q, 8);
//	//SeqQueueEn(&Q, 9);
//
//	//SeqQueueDestroy(&Q);
//
//	return 0;
//}

//int main()
//{
//	ListStack st;
//	ListStackInit(&st);
//	ListStackPush(&st, 1);
//	ListStackPush(&st, 2);
//	ListStackPush(&st, 3);
//	ListStackShow(st);
//	printf("==============\n");
//	ListStackPop(&st);
//	ListStackShow(st);
//
//	//SeqStack st;
//	//SeqStackInit(&st, STACK_DEFAULT_SIZE);
//
//	//SeqStackPush(&st, 1);
//	//SeqStackPush(&st, 2);
//	//SeqStackPush(&st, 3);
//	//SeqStackPush(&st, 4);
//	//SeqStackPush(&st, 5);
//	//SeqStackPush(&st, 6);
//	//SeqStackPush(&st, 7);
//	//SeqStackPush(&st, 8);
//
//	//int val = SeqStackTop(&st);
//	//SeqStackPop(&st);
//
//	//SeqStackPush(&st, 9);
//
//	//SeqStackShow(&st);
//	return 0;
//}


//int main()
//{
//	DCList mylist;
//	DCListInit(&mylist);
//
//	int pos;
//	int select = -1;
//	DataType item, key;
//	DataType ret;
//	bool flag;
//	while (select)
//	{
//		printf("*****************************************\n");
//		printf("* [1] push_back         [2] push_front  *\n");
//		printf("* [3] show_list         [0] quit_system *\n");
//		printf("* [4] pop_back          [5] pop_front   *\n");
//		printf("* [6] insert_pos        [7] insert_val  *\n");
//		printf("* [8] delete_pos        [9] delete_val  *\n");
//		printf("* [10] find_pos         [11] find_val   *\n");
//		printf("* [12] sort             [13] reverse    *\n");
//		printf("* [14] length           [15] clear      *\n");
//		printf("* [16] modify_pos       [17] modify_val *\n");
//		printf("* [18] capacity                         *\n");
//		printf("*****************************************\n");
//		printf("请选择:>");
//		scanf("%d", &select);
//		if (select == 0)
//			break;
//		switch (select)
//		{
//		case 1:
//			printf("请输入要插入的数据<-1结束>:>");
//			while (scanf("%d", &item), item != -1)
//			{
//				DCListPushBack(&mylist, item);
//			}
//			DCListShow(&mylist);
//			break;
//			case 2:
//			printf("请输入要插入的数据<-1结束>:>");
//			while (scanf("%d", &item), item != -1)
//			{
//				DCListPushFront(&mylist, item);
//			}
//			DCListShow(&mylist);
//			break;
//		case 3:
//			DCListShow(&mylist);
//			break;
//		case 4:
//			DCListPopBack(&mylist);
//			break;
//		case 5:
//			DCListPopFront(&mylist);
//			break;
//		case 6:
//			printf("请输入要插入的位置:>");
//			scanf("%d", &pos);
//			printf("请输入要插入的数据:>");
//			scanf("%d", &item);
//			//SListInsertByPos(&mylist, pos, item);
//			DCListShow(&mylist);
//			break;
//		case 7:
//			printf("请输入要插入的数据:>");
//			scanf("%d", &item);
//			DCListInsertByVal(&mylist, item);
//			DCListShow(&mylist);
//			break;
//		case 8:
//			printf("请输入要删除的位置:>");
//			scanf("%d", &pos);
//			//SListDeleteByPos(&mylist, pos);
//			DCListShow(&mylist);
//			break;
//		case 9:
//			printf("请输入要删除的数据:>");
//			scanf("%d", &key);
//			DCListDeleteByVal(&mylist, key);
//			DCListShow(&mylist);
//			break;
//		case 10:
//			printf("请输入要查找的位置:>");
//			scanf("%d", &pos);
//			//flag = SListFindByPos(&mylist, pos, &ret); //true false
//			if (flag)
//				printf("查找的数据为:> %d\n", ret);
//			else
//				printf("查找的数据不存在.\n");
//			break;
//		case 11:
//			printf("请输入要查找的值:>");
//			scanf("%d", &key);
//			pos = DCListFindByVal(&mylist, key);
//			if (pos == -1)
//				printf("查找的数据不存在.\n");
//			else
//				printf("数据所在的下标为:> %d\n", pos);
//			break;
//		case 12:
//			DCListSort(&mylist);
//			break;
//		case 13:
//			DCListReverse(&mylist);
//			break;
//		case 14:
//			//printf("SeqList Length = %d\n", SCListLength(&mylist));
//			break;
//		case 15:
//			DCListClear(&mylist);
//			break;
//		case 18:
//			//printf("capacity = %d\n", SeqListCapacity(&mylist));
//			break;
//		default:
//			printf("输入错误，请重新输入......\n");
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//
//	DCListDestroy(&mylist);
//	return 0;
//}

//int main()
//{
//	char *str = "ABC##DE##F##G#H##";
//	char *str1 = "ABC##D#F##GE##H##";
//	int n = 0;
//	int i = 0, j = 0;
//	BinTree bt,bt1;
//	BinTreeInit(&bt);
//	BinTreeInit(&bt1);
//	//BinTreeCreate(&bt);
//	BinTreeCreateByStr(&bt, str, &i);
//	BinTreeCreateByStr(&bt1, str1, &j);
//	
//	printf("VLR    :");
//	PreOrder(&bt);
//	printf("\n");
//	printf("LVR    :");
//	InOrder(&bt);
//	printf("\n"); 
//	printf("LRV    :");
//	PostOrder(&bt);
//	printf("\n");
//
//	printf("Size = %d\n", Size(&bt));
//	printf("Height = %d\n", Height(&bt));
//
//	BinTreeNode *p = Find(&bt, 'B');
//	p = Parent(&bt, 'H');
//
//	bool flag = Equal(&bt, &bt1);
//
//	return 0;
//}