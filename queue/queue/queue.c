#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

//循环队列的实现
bool SeqQueueIsFull(SeqQueue *Q)
{
	return Q->tail >= Q->capacity;
}

bool SeqQueueIsEmpty(SeqQueue *Q)
{
	return Q->front == Q->tail;
}

void SeqQueueInit(SeqQueue *Q,int sz)
{
	Q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	Q->base = (DataType *)malloc(sizeof(DataType)*(Q->capacity));
	Q->front = Q->tail = 0;
}

void SeqQueueEn(SeqQueue *Q, DataType x)
{
	if (SeqQueueIsFull(Q))
	{
		printf("队列已满，%d不能入队!\n",x);
		return;
	}
	Q->base[Q->tail++] = x;
}

DataType SeqQueueFront(SeqQueue *Q)
{
	if (SeqQueueCyIsEmpty(Q))
	{
		printf("队列已空，不能取对头元素!\n");
		return -1;
	}
	return Q->base[Q->front];
}

void SeqQueueDe(SeqQueue *Q)
{
	if (SeqQueueCyIsEmpty(Q))
	{
		printf("队列已空，不能取对头元素!\n");
		return;
	}
	Q->front++;
}

void SeqQueueShow(SeqQueue *Q)
{
	for (int i = Q->front; i < Q->tail; ++i)
	{
		printf("%d ", Q->base[i]);
	}
	printf("\n");
}

void SeqQueueDestroy(SeqQueue *Q)
{
	free(Q->base);
	Q->base = NULL;
	Q->capacity = Q->front = Q->tail = 0;
}

//循环队列的实现
bool SeqQueueCyIsFull(SeqCyQueue *Q)
{
	return (Q->tail + 1) % Q->capacity == Q->front;
}

bool SeqQueueCyIsEmpty(SeqCyQueue *Q)
{
	return Q->tail == Q->front;
}

void SeqQueueCyInit(SeqCyQueue *Q, int sz)
{
	Q->base = (DataType *)malloc(sizeof(DataType)* DEFAULT_QUEUE_SIZE);
	Q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	Q->front = Q->tail = 0;
}

void SeqQueueCyEn(SeqCyQueue *Q, DataType x)
{
	if (SeqQueueCyIsFull(Q))
	{
		printf("循环队列已满，%d无法入队!\n",x);
		return;
	}
	Q->base[Q->tail] = x;
	Q->tail = (Q->tail + 1) % Q->capacity;
}

void SeqQueueCyShow(SeqCyQueue *Q)
{
	for (int i = Q->front; i != Q->tail;)
	{
		printf("%d ", Q->base[i]);
		i = (i + 1) % Q->capacity;
	}
	printf("\n");
}

DataType SeqQueueCyFront(SeqCyQueue *Q)
{
	if (SeqQueueCyIsEmpty(Q))
	{
		printf("循环队列已空，无法取队头!\n");
		return -1;
	}
	return Q->base[Q->front];
}

void SeqQueueCyDe(SeqCyQueue *Q)
{
	if (SeqQueueCyIsEmpty(Q))
	{
		printf("循环队列已空，无法出队!\n");
		return;
	}
	Q->front = (Q->front + 1) % Q->capacity;
}

void SeqQueueCyDestroy(SeqCyQueue *Q)
{
	free(Q->base);
	Q->base = NULL;
	Q->capacity = Q->front = Q->tail = 0;
}