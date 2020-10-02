#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "common.h"

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

void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* _BinTreeCreate_2();
void BinTreeCreate(BinTree *t);
BinTreeNode* _BinTreeCreateByStr(char *str, int *i);
void BinTreeCreateByStr(BinTree *t, char *str, int *i);

BinTreeNode* _BinTreeCreateBy_VLR_LVR(char *vlr, char *lvr, int n);
void BinTreeCreateBy_VLR_LVR(BinTree *t, char *vlr, char *lvr, int n);
BinTreeNode* _BinTreeCreateBy_LVR_LRV(char *vlr, char *lvr, int n);
void BinTreeCreateBy_LVR_LRV(BinTree *t, char *vlr, char *lvr, int n);

void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void _LevelOrder(BinTreeNode *t);
void LevelOrder(BinTree *t);

void _PreOrderNoR(BinTreeNode *t);
void PreOrderNoR(BinTree *t);
void _InOrderNoR(BinTreeNode *t);
void InOrderNoR(BinTree *t);
void _PostOrderNoR(BinTreeNode *t);
void PostOrderNoR(BinTree *t);

size_t _Size(BinTreeNode* t);
size_t Size(BinTree *t);
size_t _Height(BinTreeNode* t);
size_t Height(BinTree *t);
BinTreeNode* _Find(BinTreeNode *t, DataType key);
BinTreeNode* Find(BinTree *t, DataType key);
BinTreeNode* _Parent(BinTreeNode *t, DataType key);
BinTreeNode* Parent(BinTree *t, DataType key);

BinTreeNode* _Clone(BinTreeNode *t);
void Clone(BinTree *t1, BinTree *t2);
bool _Equal(BinTreeNode *t1, BinTreeNode *t2);// true false
bool Equal(BinTree *t1, BinTree *t2);// true false

void BinTreeInit(BinTree *t)
{
	t->root = 0;
}
void BinTreeCreate(BinTree *t)
{
	_BinTreeCreate_1(&t->root);

}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if (item != '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate_1((*t)->leftChild);
		_BinTreeCreate_1((*t)->rightChild);
	}
}

BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
	scanf("%s", &item);
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

void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	t->root = _BinTreeCreateByStr(str, i);
}
BinTreeNode* _BinTreeCreateByStr(char *str, int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		t->data = str[*i];
		(*i)++;
		t->leftChild = _BinTreeCreateByStr(str, i);
		(*i)++;
		t->rightChild = _BinTreeCreateByStr(str, i);
		return t;
	}
}
BinTreeNode* _BinTreeCreateBy_VLR_LVR(char *vlr, char *lvr, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (lvr[k] != vlr[0])
		k++;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lvr[k];
	t->leftChild = _BinTreeCreateBy_VLR_LVR(vlr + 1, lvr, k);
	t->rightChild = _BinTreeCreateBy_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1);
	return t;
}
void BinTreeCreateBy_VLR_LVR(BinTree *t, char *vlr, char *lvr, int n)
{
	t->root = _BinTreeCreateBy_VLR_LVR(vlr, lvr, n);
}
BinTreeNode* _BinTreeCreateBy_LVR_LRV(char *lvr, char *lrv, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (lvr[k] != lrv[n - 1])
		k++;
	BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	t->data = lvr[k];

	t->rightChild = _BinTreeCreateBy_LVR_LRV(lvr + k + 1, lrv + k, n - k - 1);
	t->leftChild = _BinTreeCreateBy_LVR_LRV(lvr, lrv, k);
	return t;
}
void BinTreeCreateBy_LVR_LRV(BinTree *t, char *lvr, char *lrv, int n)
{
	t->root = _BinTreeCreateBy_LVR_LRV(lvr, lrv, n);
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
size_t Size(BinTree *t)
{
	return _Size(t->root);
}
size_t _Size(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
		return _Size(t->leftChild) + _Size(t->rightChild) + 1;
}
size_t Height(BinTree *t)
{
	return _Height(t->root);
}
size_t _Height(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = _Height(t->leftChild);
		int right_h = _Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
BinTreeNode* Find(BinTree *t, DataType key)
{
	return _Find(t->root, key);
}
BinTreeNode* _Find(BinTreeNode *t, DataType key)
{
	BinTreeNode *p;
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;

	p = _Find(t->leftChild, key);
	if (p != NULL)
		return p;
	return _Find(t->rightChild, key);
}
BinTreeNode* Parent(BinTree *t, DataType key)
{
	return _Parent(t->root, key);
}
BinTreeNode* _Parent(BinTreeNode *t, DataType key)
{
	BinTree *pr;
	BinTreeNode *p = _Find(t, key);

	if (t == NULL || p == NULL || p == t)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	pr = _Parent(t->leftChild, key);
	if (pr != NULL)
		return pr;
	return _Parent(t->rightChild, key);
}
void Clone(BinTree *t1, BinTree *t2)
{
	t2->root = _Clone(t1->root);
}
BinTreeNode* _Clone(BinTreeNode *t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = t->data;
		p->leftChild = _Clone(t->leftChild);
		p->rightChild = _Clone(t->rightChild);
		return p;
	}
}
bool Equal(BinTree *t1, BinTree *t2)
{
	return _Equal(t1->root, t2->root);
}
bool _Equal(BinTreeNode *t1, BinTreeNode *t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return (t1->data == t2->data)
		&& _Equal(t1->leftChild, t2->leftChild)
		&& _Equal(t2->rightChild, t2->rightChild);
}

#endif