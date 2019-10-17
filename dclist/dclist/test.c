#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include "dclist.h"

int main()
{
	DCList mylist;
	DCListInit(&mylist);
	DCListNode* p = NULL;

	int pos = -1;
	int select = 1;
	DataType item = 0;
	DataType ret = 0;
	DataType key = 0;
	bool flag = false;
	while (select)
	{
		printf("***************************************************\n");
		printf("**********************DCList************************\n");
		printf("****** [1] push_back         [2] push_front  ******\n");
		printf("****** [3] show_list         [0] quit_system ******\n");
		printf("****** [4] pop_back          [5] pop_front   ******\n");
		printf("****** [6] uninsert_pos      [7] insert_val  ******\n");
		printf("****** [8] undelete_pos      [9] delete_val  ******\n");
		printf("****** [10] unfind_pos       [11] find_val   ******\n");
		printf("****** [12] sort             [13] reverse    ******\n");
		printf("****** [14] length           [15] clear      ******\n");
		printf("****** [16] unmodify_pos     [17] modify_val ******\n");
		printf("***************************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������<-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			DCListShow(&mylist);
			break;
		case 2:
			printf("������Ҫ���������<-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			DCListShow(&mylist);
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			DCListShow(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			DCListShow(&mylist);
			break;
		case 7:
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			DCListShow(&mylist);
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &item);
			DCListDeleteByVal(&mylist, item);
			DCListShow(&mylist);
			break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = DCListFindByVal(&mylist, key);
			if (p == NULL)
				printf("���ҵ����ݲ�����!\n");
			else
				DCListShow(&mylist);
			break;
		case 12:
			DCListSort(&mylist);
			DCListShow(&mylist);
			break;
		case 13:
			DCListReverse(&mylist);
			DCListShow(&mylist);
			break;
		/*case 14:
			printf("DCList Length = %d\n", DCListLength(&mylist));
			break;*/
		case 15:
			DCListClear(&mylist);
			printf("Clear Success!\n");
			break;
		/*case 17:
			printf("������Ҫ�޸ĵ�����:>");
			scanf("%d", &key);
			printf("�������޸ĺ��ֵ:>");
			scanf("%d", &item);
			DCListModifyByVal(&mylist, key, item);
			DCListShow(&mylist);
			break;*/
		default:
			printf("�����������������......\n");
			break;
		}
		system("pause");
		system("cls");
	}
	DCListDestroy(&mylist);
	return 0;
}