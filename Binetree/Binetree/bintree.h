#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"common.h"


typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;

//二叉树的创建
void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* _BinTreeCreate_2();
void BinTreeCreate(BinTree *t, char *str, int *i);
//void BinTreeCreate(BinTree *t);
//二叉树的遍历
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);

void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}


//void BinTreeCreate(BinTree *t)
//{
//	//_BinTreeCreate(&t->root);
//	t->root = _BinTreeCreate_2();
//}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate_1(&((*t)->leftChild));
		_BinTreeCreate_1(&((*t)->rightChild));
	}
}

BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		return NULL;
	}
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = _BinTreeCreate_2();
		t->rightChild = _BinTreeCreate_2();
		return t;
	}
}

BinTreeNode* _BinTreeCreatByStr(char *str, int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		t->data = str[*i];
		(*i)++;
		t->leftChild = _BinTreeCreatByStr(str, i);
		(*i)++;
		t->rightChild = _BinTreeCreatByStr(str, i);
		return t;
	}
}

void BinTreeCreate(BinTree *t, char *str, int *i)
{
	t->root = _BinTreeCreatByStr(str, i);
}



void PreOrder(BinTree *t)
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
	}
}
void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		_InOrder(t->leftChild);
		printf("%c ", t->data);
		_InOrder(t->rightChild);
	}
}
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}
void _PostOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		_PostOrder(t->leftChild);
		_PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}


/*
typedef BinTreeNode* BinTree;
void BinTreeInit(BinTree *t);
void BinTreeCreate_1(BinTree *t);
BinTreeNode* BinTreeCreate_2();
void BinTreeInit(BinTree *t)
{
*t = NULL;
}
void BinTreeCreate_1(BinTree *t)
{
DataType item;
scanf("%c", &item);
if(item == '#')
{
*t = NULL;
}
else
{
*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
assert(*t != NULL);
(*t)->data = item;
BinTreeCreate_1(&((*t)->leftChild));
BinTreeCreate_1(&((*t)->rightChild));
}
}
BinTreeNode* BinTreeCreate_2()
{
DataType item;
scanf("%c", &item);
if(item == '#')
{
return NULL;
}
else
{
BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
assert(t != NULL);
t->data = item;
t->leftChild = BinTreeCreate_2();
t->rightChild = BinTreeCreate_2();
return t;
}
}
*/

#endif /*_BINTREE_H_*/