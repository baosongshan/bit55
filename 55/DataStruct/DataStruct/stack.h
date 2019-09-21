#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"
typedef struct Stack
{
	DataType *base;
	size_t    capacity;
	size_t    top;
}Stack;

#define DEFAULT_STACK_SIZE 8

void StackInit(Stack *pst, size_t sz);
void StackPush(Stack *pst, DataType x);
void StackPop(Stack *pst);
void StackClear(Stack *pst);
void StackDestroy(Stack *pst);
DataType StackTop(Stack *pst);
void StackShow(Stack *pst);
BOOL StackIsFull(Stack *pst)
{return pst->top >= pst->capacity;}
BOOL StackIsEmpty(Stack *pst)
{return pst->top == 0;}
///////////////////////////////////////////////////////
void StackInit(Stack *pst, size_t sz)
{
	pst->capacity = sz > DEFAULT_STACK_SIZE ? sz : DEFAULT_STACK_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*(pst->capacity));
	assert(pst->base != NULL);
	pst->top = 0;
}

void StackPush(Stack *pst, DataType x)
{
	if (StackIsFull(pst))
	{
		printf("ջ�ռ�������%d ������ջ.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void StackPop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("ջ�ռ��ѿգ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}

DataType StackTop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("ջ�ռ��ѿգ�����ȡջ��Ԫ��.\n");
		return;
	}
	return pst->base[pst->top-1];//
}

void StackClear(Stack *pst)
{
	pst->top = 0;
}

void StackDestroy(Stack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

void StackShow(Stack *pst)
{
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d\n", pst->base[i]);
	}
}




#endif /*_STACK_H_*/