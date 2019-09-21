#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"common.h"

struct BinTreeNode;
#define QueueDataType  struct BinTreeNode*

typedef struct Queue
{
	QueueDataType *base;
	size_t    capacity;
	size_t    front;
	size_t    tail;
}Queue;

#define DEFAULT_QUEUE_SIZE 80

BOOL QueueIsFull(Queue *q)
{return q->tail >= q->capacity;}
BOOL QueueIsEmpty(Queue *q)
{return q->front == q->tail;}
void QueueInit(Queue *q, int sz);
void QueuePush(Queue *q, QueueDataType x);
void QueuePop(Queue *q);
QueueDataType QueueFront(Queue *q);

void QueueShow(Queue *q);

void QueueInit(Queue *q, int sz)
{
	q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	q->base = (QueueDataType *)malloc(sizeof(QueueDataType)*(q->capacity));
	assert(q->base != NULL);
	q->front = q->tail = 0;
}
void QueuePush(Queue *q, QueueDataType x)
{
	if (QueueIsFull(q))
	{
		printf("队列已满, %d 不能入队.\n", x);
		return;
	}
	q->base[q->tail++] = x;
}
void QueuePop(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空, 不能出队.\n");
		return;
	}
	q->front++;
}
QueueDataType QueueFront(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空, 不能去对头元素.\n");
		return;
	}
	return q->base[q->front];
}


#if 0
typedef struct Queue
{
	DataType *base;
	size_t    capacity;
	size_t    front;
	size_t    tail;
}Queue;

#define DEFAULT_QUEUE_SIZE 8

BOOL QueueIsFull(Queue *q)
{return q->tail >= q->capacity;}
BOOL QueueIsEmpty(Queue *q)
{return q->front == q->tail;}
void QueueInit(Queue *q, int sz);
void QueuePush(Queue *q, DataType x);
void QueuePop(Queue *q);
DataType QueueFront(Queue *q);

void QueueShow(Queue *q);

void QueueInit(Queue *q, int sz)
{
	q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	q->base = (DataType *)malloc(sizeof(DataType)*(q->capacity));
	assert(q->base != NULL);
	q->front = q->tail = 0;
}
void QueuePush(Queue *q, DataType x)
{
	if (QueueIsFull(q))
	{
		printf("队列已满, %d 不能入队.\n", x);
		return;
	}
	q->base[q->tail++] = x;
}
void QueuePop(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空, 不能出队.\n");
		return;
	}
	q->front++;
}
DataType QueueFront(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空, 不能去对头元素.\n");
		return;
	}
	return q->base[q->front];
}

void QueueShow(Queue *q)
{
	for (int i = q->front; i < q->tail; ++i)
	{
		printf("%d ", q->base[i]);
	}
	printf("\n");
}

///////////////////////////////////////////////////////
typedef struct ListQueueNode
{
	DataType data;
	struct ListQueueNode *next;
}ListQueueNode;

typedef struct ListQueue
{
	ListQueueNode *front;
	ListQueueNode *tail;
}ListQueue;

void ListQueueInit(ListQueue *q);
void ListQueuePush(ListQueue *q, DataType x);
void ListQueuePop(ListQueue *q);
DataType ListQueueFront(ListQueue *q);
void ListQueueShow(ListQueue *q);
void ListQueueInit(ListQueue *q)
{
	q->front = q->tail = NULL;
}
void ListQueuePush(ListQueue *q, DataType x)
{
	ListQueueNode *s = (ListQueueNode*)malloc(sizeof(ListQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	if (q->front == NULL)
	{
		q->front = q->tail = s;
		return;
	}
	q->tail->next = s;
	q->tail = s;
}

void ListQueuePop(ListQueue *q)
{
	if (q->front != NULL)
	{
		ListQueueNode *p = q->front;
		q->front = q->front->next;
		free(p);
	}
}

DataType ListQueueFront(ListQueue *q)
{
	assert(q->front != NULL);
	return q->front->data;
}

void ListQueueShow(ListQueue *q)
{
	ListQueueNode *p = q->front;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}

////////////////////////////////////////////////////////////
typedef struct CircleQueue
{
	DataType *base;
	size_t    capacity;
	size_t    front;
	size_t    tail;
}CircleQueue;

#define DEFAULT_QUEUE_SIZE 8

BOOL CircleQueueIsFull(Queue *q)
{
	if ((q->tail + 1) % q->capacity == q->front)
		return TRUE;
	return FALSE;
}
BOOL CircleQueueIsEmpty(Queue *q)
{
	if (q->tail == q->front)
		return TRUE;
	return FALSE;
}
void CircleQueueInit(Queue *q, int sz);
void CircleQueuePush(Queue *q, DataType x);
void CircleQueuePop(Queue *q);
DataType CircleQueueFront(Queue *q);
void CircleQueueShow(Queue *q);

void CircleQueueInit(Queue *q, int sz)
{
	q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	q->base = (DataType *)malloc(sizeof(DataType)*(q->capacity));
	assert(q->base != NULL);
	q->front = q->tail = 0;
}
void CircleQueuePush(Queue *q, DataType x)
{
	if (CircleQueueIsFull(q))
	{
		printf("队列已满, %d 不能入队.\n", x);
		return;
	}

	q->base[q->tail] = x;
	q->tail = (q->tail + 1) % q->capacity;
}
void CircleQueuePop(Queue *q)
{
	if (CircleQueueIsEmpty(q))
	{
		printf("队列已空, 不能出队.\n");
		return;
	}
	q->front = (q->front + 1) % q->capacity;
}
DataType CircleQueueFront(Queue *q)
{
	if (CircleQueueIsEmpty(q))
	{
		printf("队列已空, 不能去对头元素.\n");
		return;
	}
	return q->base[q->front];
}
void CircleQueueShow(Queue *q)
{
	for (int i = q->front; i != q->tail;)
	{
		printf("%d  ", q->base[i]);
		i = (i + 1) % q->capacity;
	}
	printf("\n");
}
#endif


#endif/*_QUEUE_H_*/
