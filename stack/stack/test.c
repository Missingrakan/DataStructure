#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

int main()
{
	int val = 0;
	ListStack st;
	ListStackInit(&st);

	ListStackPush(&st, 1);
	ListStackPush(&st, 2);
	ListStackPush(&st, 3);
	ListStackPush(&st, 4);
	ListStackPush(&st, 5);
	ListStackPush(&st, 6);
	ListStackPush(&st, 7);
	ListStackPush(&st, 8);
	ListStackShow(st);
	val = ListStackTop(&st);
	printf("The top elem of stack is %d!\n", val);
	ListStackPop(&st);
	ListStackPush(&st, 9);
	ListStackShow(st);

	ListStackDestroy(&st);
	return 0;
}

//int main()
//{
//	int val = 0;
//	SeqStack* pst = SeqStackCreate(STACK_DEFAULT_SIZE);
//	SeqStackInit(pst, STACK_DEFAULT_SIZE);
//
//	SeqStackPush(pst, 1);
//	SeqStackPush(pst, 2);
//	SeqStackPush(pst, 3);
//	SeqStackPush(pst, 4);
//	SeqStackPush(pst, 5);
//	SeqStackPush(pst, 6);
//	SeqStackPush(pst, 7);
//	SeqStackPush(pst, 8);
//	SeqStackShow(pst);
//	val = SeqStackTop(pst);
//	printf("The top elem of stack is %d!\n", val);
//	SeqStackPop(pst);
//	SeqStackPush(pst, 9);
//
//	SeqStackShow(pst);
//	SeqStackDestroy(pst);
//	return 0;
//}

//int main()
//{
//	int val = 0;
//	SeqStack st = { 0 };
//	SeqStackInit(&st, STACK_DEFAULT_SIZE);
//	
//	SeqStackPush(&st, 1);
//	SeqStackPush(&st, 2);
//	SeqStackPush(&st, 3);
//	SeqStackPush(&st, 4);
//	SeqStackPush(&st, 5);
//	SeqStackPush(&st, 6);
//	SeqStackPush(&st, 7);
//	SeqStackPush(&st, 8);
//	SeqStackShow(&st);
//	val = SeqStackTop(&st);
//	printf("The top elem of stack is %d!\n",val);
//	SeqStackPop(&st);
//	SeqStackPush(&st, 9);
//
//	SeqStackShow(&st);
//	return 0;
//}