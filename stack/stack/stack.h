#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>

#define DataType int
#define STACK_DEFAULT_SIZE 8

//À≥–Ú’ª
typedef struct SeqStack
{
	DataType *base;
	size_t   capacity;
	int      top;
}SeqStack;

void SeqStackInit(SeqStack *pst,int sz);
SeqStack* SeqStackCreate(int sz);
void SeqStackPush(SeqStack *pst,DataType x);
DataType SeqStackTop(SeqStack *pst);
void SeqStackPop(SeqStack *pst);
void SeqStackShow(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);


//¡¥’ª
typedef struct StackNode
{
	DataType data;
	struct StackNode *next;
}StackNode;

typedef StackNode* ListStack;

void ListStackInit(ListStack *pst);
void ListStackPush(ListStack *pst,DataType x);
void ListStackPop(ListStack *pst);
void ListStackShow(ListStack pst);
DataType ListStackTop(ListStack *pst);
void ListStackDestroy(ListStack *pst);


#endif /*_STACK_H_*/