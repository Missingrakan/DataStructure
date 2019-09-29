#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void menu()
{
	printf("*************************************************\n");
	printf("********************* SEQLIST *******************\n");
	printf("******  [0] quit_system    [1] show_list   ******\n");
	printf("******  [2] push_back      [3] push_front  ******\n");
	printf("******  [4] pop_back       [5] pop_front   ******\n");
	printf("******  [6] insert_pos     [7] insert_val  ******\n");
	printf("******  [8] delete_pos     [9] delete_val  ******\n");
	printf("******  [10] find_pos      [11] find_val   ******\n");
	printf("******  [12] sort          [13] reverse    ******\n");
	printf("******  [14] length        [15] clear      ******\n");
	printf("******  [16] modify_pos    [17] modify_val ******\n");
	printf("******            [18] capatify            ******\n");
	printf("*************************************************\n");
}

int main()
{
	SeqList mylist;
	SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);

	int select = 1;
	DataType data = 0;
	int pos = -1;

	while (select)
	{
		menu();
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			SeqListShow(&mylist);
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			
			while (scanf("%d", &data), data != -1)
			{
				SeqListPushBack(&mylist,data);
			}
			SeqListShow(&mylist);
			break;
		case 3:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &data), data != -1)
			{
				SeqListPushFront(&mylist,data);
			}
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			SeqListShow(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			SeqListShow(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListInsertByPos(&mylist,pos,data);
			break;
		case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListInsertByVal(&mylist, data);
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			printf("SeqList Length = %d\n",SeqListLength(&mylist));
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			printf("SeqList Capacity = %d\n", SeqListCapacity(&mylist));
			break;
		default:
			printf("选择错误，请重新输入!\n");
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}