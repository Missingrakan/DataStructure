#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

bool SeqStackIsFull(SeqStack *pst)
{
	if (pst->top >= pst->capacity)
		return true;
	return false;
}

bool SeqStackIsEmpty(SeqStack *pst)
{
	if (pst->top == 0)
		return true;
	return false;
}

void SeqStackInit(SeqStack *pst, int sz)
{
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*(pst->capacity));
	pst->top = 0;
}

SeqStack* SeqStackCreate(int sz)
{
	SeqStack *pst = (SeqStack*)malloc(sizeof(SeqStack));
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*(pst->capacity));
	pst->top = 0;
	return pst;
}

void SeqStackPush(SeqStack *pst,DataType x)
{
	if (SeqStackIsFull(pst))
	{
		printf("栈已满，%d不能入栈!\n");
		return;
	}
	pst->base[pst->top++] = x;
}

DataType SeqStackTop(SeqStack *pst)
{
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能取栈顶元素!\n");
		return -1;
	}
	return pst->base[pst->top - 1];
}

void SeqStackPop(SeqStack *pst)
{
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈!\n");
		return;
	}
	pst->top--;
}

void SeqStackShow(SeqStack *pst)
{
	for (int i = pst->top - 1; i >= 0; --i)
		printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack *pst)
{
	free(pst->base);
	free(pst);
	pst = NULL;
}


//链栈实现
void ListStackInit(ListStack *pst)
{
	*pst = NULL;
}

void ListStackPush(ListStack *pst,DataType x)
{
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;
	node->next = *pst;
	*pst = node;
}

DataType ListStackTop(ListStack *pst)
{
	assert(*pst != NULL);
	return (*pst)->data;
}

void ListStackPop(ListStack *pst)
{
	StackNode *p = *pst;
	*pst = p->next;
	free(p);
}

void ListStackShow(ListStack pst)
{
	StackNode *p = pst;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void ListStackDestroy(ListStack *pst)
{
	free(*pst);
	(*pst) = NULL;
}
