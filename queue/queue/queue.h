#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>

#define DataType int
#define DEFAULT_QUEUE_SIZE 8

//顺序队列

typedef struct SeqQueue
{
	DataType *base;
	size_t   capacity;
	int      front;
	int      tail;
}SeqQueue;

bool SeqQueueIsFull(SeqQueue *Q);
bool SeqQueueIsEmpty(SeqQueue *Q);

void SeqQueueInit(SeqQueue *Q,int sz);
void SeqQueueEn(SeqQueue *Q, DataType x);
DataType SeqQueueFront(SeqQueue *Q);
void SeqQueueDe(SeqQueue *Q);
void SeqQueueShow(SeqQueue *Q);
void SeqQueueDestroy(SeqQueue *Q);



//循环队列
typedef struct SeqCyQueue
{
	DataType *base;
	size_t   capacity;
	int      front;
	int      tail;
}SeqCyQueue;

bool SeqQueueCyIsFull(SeqCyQueue *Q);
bool SeqQueueCyIsEmpty(SeqCyQueue *Q);
void SeqQueueCyInit(SeqCyQueue *Q, int sz);
void SeqQueueCyEn(SeqCyQueue *Q, DataType x);
DataType SeqQueueCyFront(SeqCyQueue *Q);
void SeqQueueCyDe(SeqCyQueue *Q);

void SeqQueueCyShow(SeqCyQueue *Q);
void SeqQueueCyDestroy(SeqCyQueue *Q);


#endif /*_QUEUE_H_*/