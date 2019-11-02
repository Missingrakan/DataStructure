#define _CRT_SECURE_NO_WARNINGS 1

#include"bintree.h"

int main()
{
	char *str = "ABC##DE##f##G#H##";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	int len = strlen(lvr);
	int i = 0;
	BinTree bt;
	BinTreeNode *p = NULL;
	BinTreeInit(&bt);
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str, &i);
	//BinTreecreateBy_LVR_LRV(&bt,lvr,lrv,len);

	//BinTreeCreate(&bt);
	//BinTreeCreate(&bt, str);


	printf("VLR:");
	PreOrder(&bt);
	printf("\n");
	printf("LVR:");
	InOrder(&bt);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt);
	printf("\n");
	return 0;
}