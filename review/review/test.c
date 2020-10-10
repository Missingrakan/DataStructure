#define _CRT_SECURE_NO_WARNINGS 1

//#include "Bintree.h"
//#include "slist.h"
//#include "sclist.h"
//#include "dclist.h"
//#include "seqlist.h"
#include "stack.h"

int main()
{
	ListStack st;
	ListStackInit(&st);
	ListStackPush(&st, 1);
	ListStackPush(&st, 2);
	ListStackPush(&st, 3);
	ListStackShow(st);
	printf("==============\n");
	ListStackPop(&st);
	ListStackShow(st);

	//SeqStack st;
	//SeqStackInit(&st, STACK_DEFAULT_SIZE);

	//SeqStackPush(&st, 1);
	//SeqStackPush(&st, 2);
	//SeqStackPush(&st, 3);
	//SeqStackPush(&st, 4);
	//SeqStackPush(&st, 5);
	//SeqStackPush(&st, 6);
	//SeqStackPush(&st, 7);
	//SeqStackPush(&st, 8);

	//int val = SeqStackTop(&st);
	//SeqStackPop(&st);

	//SeqStackPush(&st, 9);

	//SeqStackShow(&st);
	return 0;
}



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
//		printf("��ѡ��:>");
//		scanf("%d", &select);
//		if (select == 0)
//			break;
//		switch (select)
//		{
//		case 1:
//			printf("������Ҫ���������<-1����>:>");
//			while (scanf("%d", &item), item != -1)
//			{
//				DCListPushBack(&mylist, item);
//			}
//			DCListShow(&mylist);
//			break;
//			case 2:
//			printf("������Ҫ���������<-1����>:>");
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
//			printf("������Ҫ�����λ��:>");
//			scanf("%d", &pos);
//			printf("������Ҫ���������:>");
//			scanf("%d", &item);
//			//SListInsertByPos(&mylist, pos, item);
//			DCListShow(&mylist);
//			break;
//		case 7:
//			printf("������Ҫ���������:>");
//			scanf("%d", &item);
//			DCListInsertByVal(&mylist, item);
//			DCListShow(&mylist);
//			break;
//		case 8:
//			printf("������Ҫɾ����λ��:>");
//			scanf("%d", &pos);
//			//SListDeleteByPos(&mylist, pos);
//			DCListShow(&mylist);
//			break;
//		case 9:
//			printf("������Ҫɾ��������:>");
//			scanf("%d", &key);
//			DCListDeleteByVal(&mylist, key);
//			DCListShow(&mylist);
//			break;
//		case 10:
//			printf("������Ҫ���ҵ�λ��:>");
//			scanf("%d", &pos);
//			//flag = SListFindByPos(&mylist, pos, &ret); //true false
//			if (flag)
//				printf("���ҵ�����Ϊ:> %d\n", ret);
//			else
//				printf("���ҵ����ݲ�����.\n");
//			break;
//		case 11:
//			printf("������Ҫ���ҵ�ֵ:>");
//			scanf("%d", &key);
//			pos = DCListFindByVal(&mylist, key);
//			if (pos == -1)
//				printf("���ҵ����ݲ�����.\n");
//			else
//				printf("�������ڵ��±�Ϊ:> %d\n", pos);
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
//			printf("�����������������......\n");
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