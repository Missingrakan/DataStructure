#define _CRT_SECURE_NO_WARNINGS 1

#include "Bintree.h"

int main()
{
	char *str = "ABC##DE##F##G#H##";
	char *str1 = "ABC##D#F##GE##H##";
	int n = 0;
	int i = 0, j = 0;
	BinTree bt,bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str, &i);
	BinTreeCreateByStr(&bt1, str1, &j);
	
	printf("VLR    :");
	PreOrder(&bt);
	printf("\n");
	printf("LVR    :");
	InOrder(&bt);
	printf("\n"); 
	printf("LRV    :");
	PostOrder(&bt);
	printf("\n");

	printf("Size = %d\n", Size(&bt));
	printf("Height = %d\n", Height(&bt));

	BinTreeNode *p = Find(&bt, 'B');
	p = Parent(&bt, 'H');

	bool flag = Equal(&bt, &bt1);

	return 0;
}