#define _CRT_SECURE_NO_WARNINGS 1

#include "sclist.h"

int main()
{
	SCList mylist;
	SCListInit(&mylist);
	SCListNode* p = NULL;

	int pos = -1;
	int select = 1;
	DataType item = 0;
	DataType ret = 0;
	DataType key = 0;
	bool flag = false;
	while (select)
	{
		printf("***************************************************\n");
		printf("**********************SCList************************\n");
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
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushBack(&mylist, item);
			}
			SCListShow(&mylist);
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushFront(&mylist, item);
			}
			SCListShow(&mylist);
			break;
		case 3:
			SCListShow(&mylist);
			break;
		case 4:
			SCListPopBack(&mylist);
			SCListShow(&mylist);
			break;
		case 5:
			SCListPopFront(&mylist);
			SCListShow(&mylist);
			break;
		/*case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SCListInsertByVal(&mylist, item);
			SCListShow(&mylist);
			break;*/
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			SCListDeleteByVal(&mylist, item);
			SCListShow(&mylist);
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SCListFindByVal(&mylist, key);
			if (p == NULL)
				printf("查找的数据不存在!\n");
			else
				SCListShow(&mylist);
			break;
		/*case 12:
			SCListSort(&mylist);
			SCListShow(&mylist);
			break;*/
		case 13:
			SCListReverse(&mylist);
			SCListShow(&mylist);
			break;
		case 14:
			printf("SCList Length = %d\n", SCListLength(&mylist));
			break;
		case 15:
			SCListClear(&mylist);
			printf("Clear Success!\n");
			break;
		/*case 17:
			printf("请输入要修改的数据:>");
			scanf("%d", &key);
			printf("请输入修改后的值:>");
			scanf("%d", &item);
			SCListModifyByVal(&mylist, key, item);
			SCListShow(&mylist);
			break;*/
		default:
			printf("输入错误，请重新输入......\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SCListDestroy(&mylist);
	return 0;
}