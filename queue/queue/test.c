#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

int main()
{
	SeqQueue Q;//
	SeqQueueInit(&Q, DEFAULT_QUEUE_SIZE);
	SeqQueueEn(&Q, 1); //
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 5);
	SeqQueueShow(&Q);
	SeqQueueDe(&Q);
	SeqQueueDe(&Q);
	SeqQueueShow(&Q);
	SeqQueueEn(&Q, 6);
	SeqQueueEn(&Q, 7);
	SeqQueueEn(&Q, 8);
	SeqQueueShow(&Q);
	SeqQueueEn(&Q, 9);
	SeqQueueDestroy(&Q);
	return 0;
}

//int main()
//{
//	SeqCyQueue CQ = { 0 };
//	SeqQueueCyInit(&CQ, DEFAULT_QUEUE_SIZE);
//	SeqQueueCyEn(&CQ, 3);
//	SeqQueueCyEn(&CQ, 1);
//	SeqQueueCyEn(&CQ, 2);
//	SeqQueueCyEn(&CQ, 4);
//	SeqQueueCyEn(&CQ, 5);
//
//	SeqQueueCyShow(&CQ);
//
//	SeqQueueCyDe(&CQ);
//	SeqQueueCyDe(&CQ);
//
//	SeqQueueCyShow(&CQ);
//	SeqQueueCyEn(&CQ, 6);
//	SeqQueueCyEn(&CQ, 7);
//	SeqQueueCyEn(&CQ, 8);
//	SeqQueueCyEn(&CQ, 9);
//
//	SeqQueueCyShow(&CQ);
//
//	SeqQueueCyEn(&CQ, 10);
//
//
//
//	SeqQueueCyDestroy(&CQ);
//	return 0;
//}